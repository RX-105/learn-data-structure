cmake_minimum_required(VERSION 3.26.3)
project(learn-data-structure)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#aux_source_directory(./chapter2 C2_DIRS)
#aux_source_directory(./chapter3 C3_DIRS)
#aux_source_directory(./chapter4 C4_DIRS)
#
#add_library(C2_LIB ${C2_DIRS})
#add_library(C3_LIB ${C3_DIRS})
#add_library(C4_LIB ${C4_DIRS})

add_executable(main main.c chapter2/LinkList.c chapter2/SqList.c chapter3/SqStack.c chapter4/SString.c)
