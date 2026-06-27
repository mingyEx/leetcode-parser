# CMakeList.txt : CMake project for leetcode-parser, include source and define
cmake_minimum_required(VERSION 3.10)

if (UNIX)
    file(GLOB GCC_LIST "/usr/bin/gcc-[0-9]*")
    list(SORT GCC_LIST COMPARE NATURAL ORDER DESCENDING)

    if (GCC_LIST)
        list(GET GCC_LIST 0 GCC_LATEST)
        string(REGEX REPLACE ".*/gcc-([0-9]+)$" "\\1" GCC_VER "${GCC_LATEST}")
        set(GXX_LATEST "/usr/bin/g++-${GCC_VER}")

        if (EXISTS "${GXX_LATEST}")
            set(CMAKE_C_COMPILER "${GCC_LATEST}" CACHE FILEPATH "" FORCE)
            set(CMAKE_CXX_COMPILER "${GXX_LATEST}" CACHE FILEPATH "" FORCE)
        endif()
    endif()
endif()

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
