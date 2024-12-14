#include <gtest/gtest.h>
#include "LinkedList.hpp"

using namespace ds;

// 测试默认构造函数
TEST(LinkedListTest, DefaultConstructor) {
    LinkedList<int> list;
    EXPECT_TRUE(list.empty());
}

// 测试带参数的构造函数
TEST(LinkedListTest, ParameterizedConstructor) {
    LinkedList<int> list(42);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(*list.begin(), 42);
}

// 测试 push_front 方法
TEST(LinkedListTest, PushFront) {
    LinkedList<int> list;
    list.push_front(1);
    EXPECT_EQ(*list.begin(), 1);
    list.push_front(2);
    EXPECT_EQ(*list.begin(), 2);
    EXPECT_EQ(*(++list.begin()), 1);
}

// 测试 push_back 方法
TEST(LinkedListTest, PushBack) {
    LinkedList<int> list;
    list.push_back(1);
    EXPECT_EQ(*list.begin(), 1);
    list.push_back(2);
    EXPECT_EQ(*list.begin(), 1);
    EXPECT_EQ(*(++list.begin()), 2);
}

// 测试 insert 方法
TEST(LinkedListTest, Insert) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(3);
    auto it = list.insert(++list.begin(), 2);
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(*list.begin(), 1);
    EXPECT_EQ(*(++list.begin()), 2);
    EXPECT_EQ(*(++++list.begin()), 3);
}

// 测试 pop_front 方法
TEST(LinkedListTest, PopFront) {
    LinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.pop_front();
    EXPECT_EQ(*list.begin(), 1);
    list.pop_front();
    EXPECT_TRUE(list.empty());
}

// 测试 pop_back 方法
TEST(LinkedListTest, PopBack) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    EXPECT_EQ(*list.begin(), 1);
    list.pop_back();
    EXPECT_TRUE(list.empty());
}

// 测试 erase 方法
TEST(LinkedListTest, Erase) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.erase(++list.begin());
    EXPECT_EQ(*it, 3);
    EXPECT_EQ(*list.begin(), 1);
    EXPECT_EQ(*(++list.begin()), 3);
}

// 测试 find 方法
TEST(LinkedListTest, Find) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.find(2));
    EXPECT_FALSE(list.find(4));
}

// 测试 clear 方法
TEST(LinkedListTest, Clear) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    EXPECT_TRUE(list.empty());
}

// 测试 copy 构造函数
TEST(LinkedListTest, CopyConstructor) {
    LinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    LinkedList<int> list2 = list1;
    EXPECT_EQ(*list2.begin(), 1);
    EXPECT_EQ(*(++list2.begin()), 2);
    EXPECT_NE(&(*list1.begin()), &(*list2.begin()));
}

// 测试赋值操作符
TEST(LinkedListTest, AssignmentOperator) {
    LinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    LinkedList<int> list2;
    list2 = list1;
    EXPECT_EQ(*list2.begin(), 1);
    EXPECT_EQ(*(++list2.begin()), 2);
    EXPECT_NE(&(*list1.begin()), &(*list2.begin()));
}
