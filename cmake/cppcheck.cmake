add_custom_target(
  cppcheck
  COMMAND /usr/local/bin/cppcheck
  --enable=warning,performance,portability,information
  --suppress=missingInclude
  --std=c++11
  --library=qt.cfg
  --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
  --verbose
  --quiet
  ${ALL_FILES}
)