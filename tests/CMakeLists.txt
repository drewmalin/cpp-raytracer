set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/tests)
set(CTEST_BINARY_DIRECTORY ${PROJECT_BINARY_DIR}/tests)

#####################
# Test dependencies #
#####################

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1
)
FetchContent_MakeAvailable(Catch2)

##
# Catch2 setup -- this testing framework declares its own custom 'main'
# function, which must be instantiated via a macro. The tests/main.cpp
# class here provides this entry point.
## 
add_library(catch STATIC main.cpp)
target_link_libraries(catch Catch2::Catch2)


##
# Discover every single test file and generate tests for each (this 
# doesn't seem to be common, but I want to avoid updating this 
# CMakeLists.txt file as tests are added and removed).
##
file(GLOB_RECURSE TEST_FILES
  "test_*.c"
  "test_*.cpp"
)

foreach(TEST_FILE ${TEST_FILES})

    # Determine a test name per test file
    string(REGEX REPLACE "(^.*/|\\.[^.]*$)" "" TEST ${TEST_FILE})

    # Create each standalone test, linking catch and the context project
    add_executable(${TEST} ${TEST_FILE})
    target_link_libraries(${TEST} ${PROJECT_LIBS} catch)
    add_test(${TEST} ${TEST})

endforeach()