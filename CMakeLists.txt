cmake_minimum_required(VERSION 3.17)
project(laba1sem3)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest-master)
include_directories(googletest-master/googletest/include)
include_directories(googletest-master/googlemock/include)
add_executable(laba1sem3 main.cpp Sequence.h LinkedList.h ArraySequence.h LinkedListSequence.h DinamicArray.h Sorts.h menu.h Timing.h Tests.cpp menu.cpp)
target_link_libraries(laba1sem3 gtest gtest_main)
