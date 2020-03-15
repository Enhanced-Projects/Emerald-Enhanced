top_file=src/overworld.c  # Replace this with the offending C or ASM file.
for file in $(tools/scaninc/scaninc -I include ${top_file}); do
  if ! [ -f "${file}" ]; then
    make "${file}" || echo ${file}
  fi
done
