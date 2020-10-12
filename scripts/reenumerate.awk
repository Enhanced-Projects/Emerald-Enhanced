#!/usr/bin/awk -f

# This serves as a marker/separator between regular and high tier, and does not get its own number.
/#define FRONTIER_MONS_HIGH_TIER/ {
  printf("#define %-50s %d\n", $2, n-1);
  next
}

/#define (FRONTIER_MON_|NUM_FRONTIER_MONS)/ {
  printf("#define %-50s %d\n", $2, n);
  n++;
  next
}

{
  print $0;
}
