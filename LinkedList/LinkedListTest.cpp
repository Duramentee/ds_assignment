#include <gtest/gtest.h>
#include "LinkedList.hpp" // 假设你的 LinkedList 类定义在这个头文件中

using namespace ds;

// 测试默认构造函数
TEST(LinkedListTest, DefaultConstructor) {
    LinkedList<int> list;
    EXPECT_TRUE(list.empty());
}

// 测试带参数构造函数
TEST(LinkedListTest, ParamConstructor) {
    LinkedList<int> list(42);
    EXPECT_FALSE(list.empty());
    EXPECT_TRUE(list.find(42));
}

// 测试复制构造函数
TEST(LinkedListTest, CopyConstructor) {
    LinkedList<int> original;
    original.push_back(1);
    original.push_back(2);

    LinkedList<int> copy = original;
    EXPECT_FALSE(copy.empty());
    EXPECT_TRUE(copy.find(1));
    EXPECT_TRUE(copy.find(2));
}

// 测试赋值操作符
TEST(LinkedListTest, AssignmentOperator) {
    LinkedList<int> original;
    original.push_back(3);
    original.push_back(4);

    LinkedList<int> assigned;
    assigned = original;
    EXPECT_FALSE(assigned.empty());
    EXPECT_TRUE(assigned.find(3));
    EXPECT_TRUE(assigned.find(4));
}

// 测试 push_front 方法
TEST(LinkedListTest, PushFront) {
    LinkedList<int> list;
    list.push_front(5);
    list.push_front(6);
    EXPECT_EQ(list.find(5), true);
    EXPECT_EQ(list.find(6), true);
}

// 测试 push_back 方法
TEST(LinkedListTest, PushBack) {
    LinkedList<int> list;
    list.push_back(7);
    list.push_back(8);
    EXPECT_EQ(list.find(7), true);
    EXPECT_EQ(list.find(8), true);
}

// 测试 insert 方法
TEST(LinkedListTest, Insert) {
    LinkedList<int> list;
    list.push_back(10);
    list.insert(0, 9); // 插入到头部
    list.insert(2, 11); // 插入到尾部
    list.insert(1, 10.5); // 插入到中间
    EXPECT_EQ(list.find(9), true);
    EXPECT_EQ(list.find(10.5), true);
    EXPECT_EQ(list.find(11), true);
}

// 测试 pop_front 方法
TEST(LinkedListTest, PopFront) {
    LinkedList<int> list;
    list.push_back(12);
    list.push_back(13);
    list.pop_front();
    EXPECT_FALSE(list.find(12));
    EXPECT_TRUE(list.find(13));
}

// 测试 pop_back 方法
TEST(LinkedListTest, PopBack) {
    LinkedList<int> list;
    list.push_back(14);
    list.push_back(15);
    list.pop_back();
    EXPECT_TRUE(list.find(14));
    EXPECT_FALSE(list.find(15));
}

// 测试 erase 方法
TEST(LinkedListTest, Erase) {
    LinkedList<int> list;
    list.push_back(16);
    list.push_back(17);
    list.erase(0); // 删除头部元素
    EXPECT_FALSE(list.find(16));
    EXPECT_TRUE(list.find(17));
}

// 测试 find 方法
TEST(LinkedListTest, Find) {
    LinkedList<int> list;
    list.push_back(18);
    EXPECT_TRUE(list.find(18));
    EXPECT_FALSE(list.find(19)); // 不在列表中的元素
}

// 测试 empty 方法
TEST(LinkedListTest, Empty) {
    LinkedList<int> list;
    EXPECT_TRUE(list.empty());
    list.push_back(20);
    EXPECT_FALSE(list.empty());
}

// 测试 clear 方法
TEST(LinkedListTest, Clear) {
    LinkedList<int> list;
    list.push_back(21);
    list.clear();
    EXPECT_TRUE(list.empty());
}

// 测试 print 方法（这是一个输出测试，通常不会在自动测试中进行）
// TEST(LinkedListTest, Print) {
//     LinkedList<int> list;
//     list.push_back(22);
//     list.print(); // 这个测试需要人工检查输出
// }

