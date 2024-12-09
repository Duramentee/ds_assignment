#include <gtest/gtest.h>
#include "SeqTable.hpp" // 包含SeqTable的头文件

// 测试SeqTable的单元测试
TEST(SeqTableTest, HappyPath) {
    ds::SeqTable<int> table(2); // 初始化一个大小为2的SeqTable

    // 测试push_back功能
    table.push_back(1);
    table.push_back(2);
    EXPECT_EQ(table.size(), 2); // 验证当前大小为2
    EXPECT_EQ(table.at(0), 1);   // 验证第一个元素为1
    EXPECT_EQ(table.at(1), 2);   // 验证第二个元素为2

    // 测试insert功能
    table.insert(1, 3); // 在位置1插入3
    EXPECT_EQ(table.size(), 3); // 验证当前大小为3
    EXPECT_EQ(table.at(1), 3);   // 验证新插入的元素在位置1

    // 测试pop_back功能
    table.pop_back(); // 移除最后一个元素
    EXPECT_EQ(table.size(), 2); // 验证当前大小为2

    // 测试erase功能
    table.erase(0); // 移除位置0的元素
    EXPECT_EQ(table.size(), 1); // 验证当前大小为1
    EXPECT_EQ(table.at(0), 3);   // 验证当前位置的元素为3

    // 测试front和back功能
    EXPECT_EQ(table.front(), 3); // 验证front
    EXPECT_EQ(table.back(), 3);  // 验证back

    // 测试resize到更大和更小
    table.resize(5); // 扩展到5
    EXPECT_EQ(table.size(), 5); // 验证当前大小为5
    EXPECT_EQ(table.at(0), 3);   // 验证当前位置的元素为3

    table.resize(0); // 收缩到0
    EXPECT_EQ(table.size(), 0); // 验证当前大小为0
}

// 边缘案例测试
TEST(SeqTableTest, EdgeCases) {
    // 测试构造函数，大小为0的情况下
    EXPECT_THROW(ds::SeqTable<int>(0), std::invalid_argument); // 应该抛出异常

    ds::SeqTable<int> table;

    // 测试push_back在容量为0的情况下
    table.push_back(1);
    EXPECT_EQ(table.size(), 1); // 当前大小为1

    // 测试out_of_range异常
    EXPECT_THROW(table.at(1), std::out_of_range); // 超出范围访问
    EXPECT_THROW(table.erase(1), std::out_of_range); // 超出范围删除
    EXPECT_THROW(table.insert(2, 4), std::out_of_range); // 超出范围插入

    // 测试pop_back在空表情况
    table.pop_back(); // 移除元素
    EXPECT_EQ(table.size(), 0); // 验证当前大小为0
    table.pop_back(); // 再次移除应该不会出错（空表）

    // 测试out_of_range异常的访问
    EXPECT_THROW(table.front(), std::out_of_range); // 空表访问front
    EXPECT_THROW(table.back(), std::out_of_range); // 空表访问back
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // 初始化GoogleTest
    return RUN_ALL_TESTS(); // 运行所有测试
}
