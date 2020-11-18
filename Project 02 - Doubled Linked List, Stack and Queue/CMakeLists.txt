cmake_minimum_required(VERSION 3.5)
project(DoubledLinkedListStackQueue VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

# program entries
SET ( SRCS
      src/main.cpp )

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable( prog "${SRCS}" )

# define C++11 standard
set_property(TARGET prog PROPERTY CXX_STANDARD 11)