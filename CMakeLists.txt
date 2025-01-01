cmake_minimum_required(VERSION 3.29.6)
project(ds)

set(CMAKE_CXX_STANDARD 17)

add_executable(ds main.cpp
        SeqTable/SeqTable.hpp
        SeqTable/SeqTableTest.cpp
        LinkedList/LinkedList.hpp
        LinkedList/LinkedListTest.cpp
        Stack/Stack.hpp
        Stack/StackTest.cpp
        Queue/Queue.hpp
        Queue/QueueTest.cpp
        Tree/BinaryTree.hpp
        Tree/BinaryTreeTest.cpp
        Pair/Pair.hpp
        Pair/PairTest.cpp
        HashTable/HashTable.hpp
        HashTable/HashTableTest.cpp
        Graph/Graph.hpp
        Graph/GraphTest.cpp
)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(ds ${GTEST_LIBRARIES} pthread)
