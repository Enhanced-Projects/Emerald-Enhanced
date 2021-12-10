#!/usr/bin/env python
import re

with open('include/constants/battle_frontier_mons.h') as f:
    ids = { l.split()[1]: l.split()[2] for l in f.readlines() if l.startswith('#define FRONTIER_MON_') }

with open('src/data/battle_frontier/battle_frontier_mons.h', 'r') as f:
    new_lines = [ f'{l.rstrip()} {"" if "//" in l else "// "}(ID: {ids[r.group(1)]})\n' if (r := re.match('^\s+\[(FRONTIER_MON_[\w_\d]+)\] = \{', l)) else l for l in f.readlines()]

with open('src/data/battle_frontier/battle_frontier_mons.h', 'w') as f:
    f.writelines(new_lines)
