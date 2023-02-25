# CMakeList.txt : CMake project for leetcode-parser, include source and define
cmake_minimum_required(VERSION 3.10)

if (UNIX)
  set(CMAKE_C_COMPILER /usr/bin/gcc-10)
  set(CMAKE_CXX_COMPILER /usr/bin/g++-10)
endif (UNIX)

project(leetcode_parser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(leetcode)

add_executable(main main.cpp)

#from https://stackoverflow.com/a/46995969/13792395
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/in.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

target_link_libraries(main PUBLIC leetcode)

target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/leetcode"
                           )
