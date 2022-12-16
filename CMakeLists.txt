# CMakeList.txt : CMake project for leetcode-parser, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.10)
project(leetcode)

# Add source to this project's executable.
# add_executable (leetcode-parser "main.cpp" "Solution.h" "pprint.h")
#没必要加头文件吧，不是会自己执行吗? 这个是我写的还是生成的?
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# 关于语言标准号，写一些if else.
# 只留一个main在外面，头文件单独塞到一个文件夹里去.
# 发布！
add_executable(main main.cpp)

target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# TODO: Add tests and install targets if needed.
