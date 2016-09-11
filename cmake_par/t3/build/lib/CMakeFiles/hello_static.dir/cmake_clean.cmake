FILE(REMOVE_RECURSE
  "CMakeFiles/hello_static.dir/hello.o"
  "../OOO/libhello.pdb"
  "../OOO/libhello.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang C)
  INCLUDE(CMakeFiles/hello_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
