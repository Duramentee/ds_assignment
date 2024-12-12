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

TEST(BinaryTreeTest, FindMaxValueTest) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    EXPECT_EQ(tree.find_max_value(), 18);

    BinaryTree<int> emptyTree;
    EXPECT_THROW(emptyTree.find_max_value(), std::runtime_error);
}

TEST(BinaryTreeTest, FindMinValueTest) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    EXPECT_EQ(tree.find_min_value(), 3);

    BinaryTree<int> emptyTree;
    EXPECT_THROW(emptyTree.find_min_value(), std::runtime_error);
}

TEST(BinaryTreeTest, FindMin) {
    ds::BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    ds::BinaryTreeNode<int>* min_node = tree.find_min();
    ASSERT_NE(min_node, nullptr); // 确保返回的节点不为空
    EXPECT_EQ(min_node->data_, 3);
}

TEST(BinaryTreeTest, FindMax) {
    ds::BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    ds::BinaryTreeNode<int>* max_node = tree.find_max();
    ASSERT_NE(max_node, nullptr); // 确保返回的节点不为空
    EXPECT_EQ(max_node->data_, 18);
}

TEST(BinaryTreeTest, CalculateHeight) {
    BinaryTree<int> tree;

    // Empty tree height should be 0
    EXPECT_EQ(tree.calculate_height(), 0);

    // Single node tree height should be 1
    tree.insert(10);
    EXPECT_EQ(tree.calculate_height(), 1);

    // Tree with multiple levels
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
    // Height should be 3
    EXPECT_EQ(tree.calculate_height(), 3);

    // Adding more nodes to increase the height
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(11);
    tree.insert(13);
    tree.insert(17);
    tree.insert(19);

    // The tree structure should be:
    //               10
    //            /      \
    //           5        15
    //          / \      /  \
    //         3   7    12   18
    //        / \ / \  / \   / \
    //       2  4 6 8 11 13 17 19
    // Height should be 4
    EXPECT_EQ(tree.calculate_height(), 4);
}












