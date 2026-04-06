#!/bin/bash

set -u

if [[ -e 'locations.sh.inc' ]]; then source 'locations.sh.inc'; fi

: "${top_srcdir:=${HOME}/projects/my-tree-sitter-odin/master}"
: "${master_odin:=${HOME}/projects/Odin/master/odin}"

grammar_js="${top_srcdir}/grammar.js"
parser_hpp="${master_odin%/*}/src/parser.hpp"

if [[ ${#} -gt 0 ]]; then
    generated_odin=${1}; shift
fi

: "${generated_odin:=generated.odin}"

extract_bracket_contents() {
    local js_var_name=${1}; shift
    local file=${1}; shift
    local out_var_name=${1}; shift
    local begin end grep_expr

    grep_expr='  '"${js_var_name}"' : $ => ['
    begin=$(
        grep -m 1 -nFxe "${grep_expr}" "${file}" | \
            cut -f1 -d:
         )
    length=$(
        tail -n "+${begin}" "${file}" | \
            grep -m 1 -nFxe '  ],' | \
            cut -f1 -d:
          )
    mapfile -t "${out_var_name}" < \
            <(tail -n "+${begin}" "${file}" | \
                  head -n "${length}" | \
                  grep -e '^[[:space:]]*\$\.[^_]' | \
                  sed -e 's/^.*\$\.\([a-z_]*\),$/\1/'
             )
}

extract_rules_contents() {
    local file=${1}; shift
    local out_var_name=${1}; shift
    local begin length sed_expr1 sed_expr2

    begin=$(
        grep -m 1 -nFxe '  rules : {' "${file}" | \
            cut -f1 -d:
         )
    length=$(
        tail -n "+${begin}" "${file}" | \
            grep -m 1 -nFxe '  }' | \
            cut -f1 -d:
          )
    # delete all the lines that are not public rule introducers
    sed_expr1='/^[[:space:]]*[a-z][a-z_]*[[:space:]]*:[[:space:]]*\$[[:space:]]*=>/!d'
    # strip rule introducer to its name only
    sed_expr2='s/^[[:space:]]*\([a-z][a-z_]*\).*/\1/'
    mapfile -t "${out_var_name}" < \
            <(tail -n "+${begin}" "${file}" | \
                  head -n "${length}" | \
                  sed -e "${sed_expr1}" -e "${sed_expr2}"
             )
}

csort() {
    LC_ALL=C sort "${@}"
}

declare -a externals supertypes rules symbols aliases
extract_bracket_contents externals "${grammar_js}" externals
extract_bracket_contents supertypes "${grammar_js}" supertypes
extract_rules_contents "${grammar_js}" rules
mapfile -t aliases < \
        <(
    grep -oe 'alias[[:space:]]*([^)]*)' "${grammar_js}" | \
        cut -f2 -d, | \
        sed \
            -e 's/[[:space:]]*\$\.\([^)]*\))/\1/' \
            -e "s/[[:space:]]*'\([^']*\)')/\1/"
)

mapfile -t symbols < \
        <(comm -2 -3 \
               <(printf '%s\n' "${externals[@]}" "${rules[@]}" "${aliases[@]}" | csort -u) \
               <(printf '%s\n' "${supertypes[@]}" | csort -u))

lines=(
    '// THIS FILE IS GENERATED, DO NOT EDIT'
    ''
    'package ac'
    ''
    'TS_Element :: enum {'
    '    Nil_Element,'
)

printf '%s\n' "${lines[@]}" >"${generated_odin}"
declare -a enum_symbols
mapfile -t enum_symbols < <(printf '%s\n' "${symbols[@]}" | sed -e 's/\(^.\)/\u\1/' -e 's/_\(.\)/_\u\1/g')
printf '    %s,\n' "${enum_symbols[@]}" >>"${generated_odin}"

lines=(
    '}'
    ''
    'make_ts_elements_map :: proc() -> map[string]TS_Element {'
    '    m := make(map[string]TS_Element, 2 * ('"${#symbols[@]}"' + 1))'
    '    m[""] = .Nil_Element'
)
declare -i i
for ((i = 0; i < ${#enum_symbols[@]}; i++)); do
    s=${symbols[i]}
    e=${enum_symbols[i]}
    lines+=( "    m[\"${s}\"] = .${e}" )
done
lines+=(
    '    return m'
    '}'
)
printf '%s\n' "${lines[@]}" >>"${generated_odin}"

declare -a odin_symbols odin_enum_symbols
begin=$(grep -m 1 -Fne 'AST_KINDS' "${parser_hpp}" | cut -f1 -d:)
length=$(tail -n "+${begin}" "${parser_hpp}" | grep -m 1 -Fnxe '' | cut -f1 -d:)

# filter out lines that do not begin with AST_KIND( followed by a
# letter (filters out markers like _ExprBegin too)
sed_expr1='/AST_KIND([A-Z]/!d'
# pluck the string out of the AST_KIND line (without the quotes)
sed_expr2='s/^[^"]*"\([^"]*\)".*$/\1/'
# filter out hashes
sed_expr3='s/#\+//g'
# change all consecutive whitespace into a single dash
sed_expr4='s/[[:space:]]\+/-/g'
mapfile -t odin_symbols < \
        <(
    {
        echo "source-file"
        tail -n "+${begin}" "${parser_hpp}" | \
            head -n "${length}" | \
            sed \
                -e "${sed_expr1}" \
                -e "${sed_expr2}" \
                -e "${sed_expr3}" \
                -e "${sed_expr4}"
    } | csort -u
)

mapfile -t odin_enum_symbols < <(printf '%s\n' "${odin_symbols[@]}" | sed -e 's/\(^.\)/\u\1/' -e 's/-\(.\)/_\u\1/g')

lines=(
    ''
    'OD_Element :: enum {'
    '    Nil_Element,'
)
printf '%s\n' "${lines[@]}" >>"${generated_odin}"
printf '    %s,\n' "${odin_enum_symbols[@]}" >>"${generated_odin}"
lines=(
    '}'
    ''
    'make_od_elements_map :: proc() -> map[string]OD_Element {'
    '    m := make(map[string]OD_Element, 2 * ('"${#odin_symbols[@]}"' + 1))'
    '    m[""] = .Nil_Element'
)
for ((i = 0; i < ${#odin_enum_symbols[@]}; i++)); do
    s=${odin_symbols[i]}
    e=${odin_enum_symbols[i]}
    lines+=( "    m[\"${s}\"] = .${e}" )
done
lines+=(
    '    return m'
    '}'
)
printf '%s\n' "${lines[@]}" >>"${generated_odin}"
