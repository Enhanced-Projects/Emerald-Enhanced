#!/bin/sh

file="include/constants/battle_frontier_mons.h"
awk -f scripts/reenumerate.awk "$file" > "$file"_tmp
mv "$file"_tmp "$file"
