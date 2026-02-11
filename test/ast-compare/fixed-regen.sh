#!/bin/bash

if [[ -e 'locations.sh.inc' ]]; then source 'locations.sh.inc'; fi

: "${dumper_odin:=${HOME}/projects/Odin/ast-dump/odin}"
: "${master_odin:=${HOME}/projects/Odin/master/odin}"
: "${top_srcdir:=${HOME}/projects/my-tree-sitter-odin/master}"

"${dumper_odin}" build "${master_odin%/*}/core/math/fixed" -dump-ast:math_fixed -dump-ast-opts:sexp,omit-defaults,disregard-filetags
mv -f fixed-math_fixed-fixed.ast fixed-od.ast

this_dir="${PWD}"

pushd "${top_srcdir}" >/dev/null 2>&1
tree-sitter parse "${master_odin%/*}/core/math/fixed/fixed.odin" >"${this_dir}/fixed-ts.ast"
popd >/dev/null 2>&1
