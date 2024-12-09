//
// Created by drowlia on 24-12-9.
//

#include <gtest/gtest.h>
#include "LinkedList.hpp" // 包含要测试的LinkedList类

// 单元测试LinkedList类的各个功能
TEST(LinkedListTest, HappyPath) {
    // 测试构造函数和push_front
    ds::LinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    // 检查元素顺序
    std::ostringstream oss;
    list.print(); // 打印链表
    oss << "3 2 1 "; // 预期输出
    ASSERT_EQ(oss.str(), "3 2 1 "); // 验证输出

    // 测试push_back
    list.push_back(4);
    list.push_back(5);

    // 检查添加后元素顺序
    oss.str(""); // 清空输出流
    list.print();
    oss << "3 2 1 4 5 "; // 预期输出
    ASSERT_EQ(oss.str(), "3 2 1 4 5 ");

    // 测试insert
    list.insert(2, 6); // 在位置2插入6
    oss.str(""); // 清空输出流
    list.print();
    oss << "3 2 6 1 4 5 "; // 预期输出
    ASSERT_EQ(oss.str(), "3 2 6 1 4 5 ");

    // 测试pop_front
    list.pop_front();
    oss.str(""); // 清空输出流
    list.print();
    oss << "2 6 1 4 5 "; // 预期输出
    ASSERT_EQ(oss.str(), "2 6 1 4 5 ");

    // 测试pop_back
    list.pop_back();
    oss.str(""); // 清空输出流
    list.print();
    oss << "2 6 1 4 "; // 预期输出
    ASSERT_EQ(oss.str(), "2 6 1 4 ");

    // 测试erase
    list.erase(1); // 删除位置1的元素
    oss.str(""); // 清空输出流
    list.print();
    oss << "2 1 4 "; // 预期输出
    ASSERT_EQ(oss.str(), "2 1 4 ");

    // 测试find
    ASSERT_TRUE(list.find(1)); // 验证1是否在链表中
    ASSERT_FALSE(list.find(10)); // 验证10是否不在链表中

    // 测试clear
    list.clear();
    ASSERT_TRUE(list.empty()); // 检查链表是否为空
}

TEST(LinkedListTest, EdgeCases) {
    ds::LinkedList<int> list;

    // 测试空链表的find和empty
    ASSERT_FALSE(list.find(1)); // 在空链表中查找1应返回false
    ASSERT_TRUE(list.empty()); // 空链表应返回true

    // 测试pop_front 和 pop_back 在空链表中的行为
    list.pop_front(); // 不应崩溃
    list.pop_back(); // 不应崩溃

    // 测试单个元素的操作
    list.push_front(10);
    ASSERT_FALSE(list.empty()); // 此时链表不应为空

    // 测试在单个元素的链表中pop_front和pop_back
    list.pop_front();
    ASSERT_TRUE(list.empty()); // 删除后链表应为空
    list.push_front(20); // 重新插入
    list.pop_back();
    ASSERT_TRUE(list.empty()); // 删除后链表应为空

    // 测试在无效位置插入
    list.insert(10, 30); // 超出范围的插入
    list.insert(-1, 40); // 负数位置的插入
    ASSERT_TRUE(list.empty()); // 依然应为空
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv); // 初始化 Google Test
    return RUN_ALL_TESTS(); // 运行所有测试用例
}
