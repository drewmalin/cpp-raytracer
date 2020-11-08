add_custom_target(
  clang-format
  COMMAND /usr/local/bin/clang-format
  -style=LLVM
  -i
  ${ALL_FILES}
)