cmake_minimum_required(VERSION 3.29.6)
project(ds)

set(CMAKE_CXX_STANDARD 20)

add_executable(ds main.cpp
        LinkedList/LinkedList.hpp
        LinkedList/LinkedList_test.cpp
        Stack/Stack.hpp
        Stack/Stack_test.cpp
        SeqTable/SeqTable.hpp
        SeqTable/SeqTable_test.cpp
        Queue/Queue.hpp
        Queue/Queue_test.cpp
        Tree/BinaryTree.hpp
        Tree/BinaryTree_test.cpp)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(ds ${GTEST_LIBRARIES} pthread)
