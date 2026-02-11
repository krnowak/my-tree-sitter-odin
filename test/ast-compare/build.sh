#!/bin/bash

if [[ -e 'locations.sh.inc' ]]; then source 'locations.sh.inc'; fi

: "${master_odin:=${HOME}/projects/Odin/master/odin}"

"${master_odin}" build . -debug
