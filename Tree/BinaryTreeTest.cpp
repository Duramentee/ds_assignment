#include <gtest/gtest.h>
#include <sstream>
#include "BinaryTree.hpp"

using namespace ds;

// Helper function to capture standard output
std::string captureStdout(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
}

TEST(BinaryTreeTest, Insert) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // The tree structure should be:
    //         10
    //        /  \
    //       5    15
    //      / \   / \
    //     3   7 12  18
}

TEST(BinaryTreeTest, PreOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::string output = captureStdout([&tree]() { tree.pre_order(); });
    EXPECT_EQ(output, "10 5 3 7 15 12 18 \n");
}

TEST(BinaryTreeTest, InOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::string output = captureStdout([&tree]() { tree.in_order(); });
    EXPECT_EQ(output, "3 5 7 10 12 15 18 \n");
}

TEST(BinaryTreeTest, PostOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::string output = captureStdout([&tree]() { tree.post_order(); });
    EXPECT_EQ(output, "3 7 5 12 18 15 10 \n");
}

TEST(BinaryTreeTest, LevelOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::string output = captureStdout([&tree]() { tree.level_order(); });
    EXPECT_EQ(output, "10 5 15 3 7 12 18 \n");
}
