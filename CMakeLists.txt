cmake_minimum_required(VERSION 3.29.6)
project(ds)

set(CMAKE_CXX_STANDARD 20)

add_executable(ds main.cpp
        LinkedList/LinkedList.hpp
        LinkedList/LinkedListTest.cpp
        Stack/Stack.hpp
        Stack/StackTest.cpp
        SeqTable/SeqTable.hpp
        SeqTable/SeqTableTest.cpp
        Queue/Queue.hpp
        Queue/QueueTest.cpp
        Tree/BinaryTree.hpp
        Tree/BinaryTreeTest.cpp
        Graph/GraphTest.cpp
        Graph/Graph.hpp
        HashTable/HashTable.hpp
        HashTable/HashTableTest.cpp
        Pair/Pair.hpp
        Pair/PairTest.cpp
)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(ds ${GTEST_LIBRARIES} pthread)
