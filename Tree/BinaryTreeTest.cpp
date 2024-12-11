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

TEST(BinaryTreeTest, SearchTest) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.search(7));
    EXPECT_TRUE(tree.search(12));
    EXPECT_TRUE(tree.search(18));

    EXPECT_FALSE(tree.search(20));
    EXPECT_FALSE(tree.search(0));
    EXPECT_FALSE(tree.search(8));
}

TEST(BinaryTreeTest, FindMaxTest) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    EXPECT_EQ(tree.find_max(), 18);

    BinaryTree<int> emptyTree;
    EXPECT_THROW(emptyTree.find_max(), std::runtime_error);
}

TEST(BinaryTreeTest, FindMinTest) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    EXPECT_EQ(tree.find_min(), 3);

    BinaryTree<int> emptyTree;
    EXPECT_THROW(emptyTree.find_min(), std::runtime_error);
}
