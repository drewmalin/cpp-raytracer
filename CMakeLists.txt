cmake_minimum_required(VERSION 3.14...3.18 FATAL_ERROR)
project(
  HelloCpp
  VERSION 0.1.0
  DESCRIPTION "Hello, C++!"
  LANGUAGES CXX
)

#####################
# Source code setup #
#####################

set(CMAKE_CXX_STANDARD 20)

# Source files
file(GLOB_RECURSE SOURCE_FILES
  ${CMAKE_SOURCE_DIR}/src/*.c
  ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Header files
file(GLOB_RECURSE HEADER_FILES
  ${CMAKE_SOURCE_DIR}/src/*.h
  ${CMAKE_SOURCE_DIR}/src/*.hpp
)

# All files
file(GLOB_RECURSE ALL_FILES
  ${CMAKE_SOURCE_DIR}/src/*.c
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.h
  ${CMAKE_SOURCE_DIR}/src/*.hpp
  ${CMAKE_SOURCE_DIR}/tests/*.c
  ${CMAKE_SOURCE_DIR}/tests/*.cpp
  ${CMAKE_SOURCE_DIR}/tests/*.h
  ${CMAKE_SOURCE_DIR}/tests/*.hpp
)

# Create project executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

######################
# Dependencies setup #
######################

include(FetchContent)

# FetchContent_Declare(...)
# FetchContent_MakeAvailable(...)

#################
# Include setup #
#################

include_directories(
  "${CMAKE_SOURCE_DIR}/src"
  "${CMAKE_SOURCE_DIR}/include"
)

##############
# Test setup #
##############

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)

  # Create project library (this is done to allow tests to arbitrarily 
  # import any source code).
  add_library(${PROJECT_NAME}_lib ${HEADER_FILES} ${SOURCE_FILES})
  set(PROJECT_LIBS ${PROJECT_NAME}_lib)

  add_subdirectory(tests)
endif()

######################
# CMake script setup #
######################

include(cmake/clang-format.cmake)
include(cmake/cppcheck.cmake)