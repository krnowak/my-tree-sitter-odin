#!/bin/bash

if [[ -e 'locations.sh.inc' ]]; then source 'locations.sh.inc'; fi

: "${dumper_odin:=${HOME}/projects/Odin/ast-dump/odin}"
: "${master_odin:=${HOME}/projects/Odin/master/odin}"
: "${top_srcdir:=${HOME}/projects/my-tree-sitter-odin/master}"

skip_generate=''
if [[ ${1} = '--skip-generate' || ${1} = '-s' ]]; then
    skip_generate='x'
    shift
fi

collection=${1-'core'}
pkgdir=${2:-'math/fixed'}
file=${3:-'fixed.odin'}

output=${file%.odin}

pkg=$(grep -m 1 -e '^package' "${master_odin%/*}/${collection}/${pkgdir}/${file}" | cut -f2 -d' ')

echo "od"
"${dumper_odin}" build "${master_odin%/*}/${collection}/${pkgdir}" -dump-ast:"${pkg}:${file}" -dump-ast-opts:omit-defaults,disregard-filetags -out:"${output}"

rm -rf inputs; mkdir inputs
mv "${output}-${pkg}-${output}.ast" "inputs/input-od.ast"
cp -a "${master_odin%/*}/${collection}/${pkgdir}/${file}" inputs/input.odin

this_dir="${PWD}"

pushd "${top_srcdir}" >/dev/null 2>&1
if [[ -z ${skip_generate} ]]; then
    echo "tsg"
    tree-sitter generate
fi
echo "tsp"
tree-sitter parse "${master_odin%/*}/${collection}/${pkgdir}/${file}" >"${this_dir}/inputs/input-ts.ast"
popd >/dev/null 2>&1

this_script=${this_dir}/${0##*/}
cat <<EOF >"${this_dir}/inputs/regen_same.sh"
#!/bin/bash
${this_script@Q} "\${@}" ${@@Q}
EOF

chmod a+x "${this_dir}/inputs/regen_same.sh"
