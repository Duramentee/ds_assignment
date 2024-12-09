//
// Created by lsx31 on 24-12-9.
//

#include <gtest/gtest.h>
#include "SeqTable.hpp"

using namespace ds;

// 测试单元类
class SeqTableTest : public ::testing::Test {
protected:
    SeqTable<int> seqTable;

    // 测试前的准备
    void SetUp() override {
        seqTable.push_back(1);
        seqTable.push_back(2);
        seqTable.push_back(3);
    }

    // 测试后的清理
    void TearDown() override {
        // 这里不需要做特别的清理，因为SeqTable会自动处理内存
    }
};

// 测试正常情况
TEST_F(SeqTableTest, PushBackTest) {
    EXPECT_EQ(seqTable.size(), 3); // 当前大小应该为3
    seqTable.push_back(4);
    EXPECT_EQ(seqTable.size(), 4); // 添加一个元素后，大小应该为4
    EXPECT_EQ(seqTable.at(3), 4);   // 最后一个元素应该是4
}

// 测试插入元素
TEST_F(SeqTableTest, InsertTest) {
    seqTable.insert(1, 5); // 在位置1插入5
    EXPECT_EQ(seqTable.at(1), 5); // 确保插入成功
    EXPECT_EQ(seqTable.size(), 4); // 大小应该增加到4
}

// 测试获得元素
TEST_F(SeqTableTest, AtTest) {
    EXPECT_EQ(seqTable.at(0), 1); // 第一个元素应该是1
    EXPECT_EQ(seqTable.at(2), 3); // 第三个元素应该是3
}

// 测试边界情况：插入越界
TEST_F(SeqTableTest, InsertOutOfRangeTest) {
    EXPECT_THROW(seqTable.insert(5, 6), std::out_of_range); // 超出范围的插入应该抛出异常
}

// 测试删除元素
TEST_F(SeqTableTest, EraseTest) {
    seqTable.erase(1); // 删除索引为1的元素
    EXPECT_EQ(seqTable.size(), 2); // 删除后大小应该为2
    EXPECT_EQ(seqTable.at(1), 3); // 确保索引1的元素现在是3
}

// 测试边界情况：删除越界
TEST_F(SeqTableTest, EraseOutOfRangeTest) {
    EXPECT_THROW(seqTable.erase(3), std::out_of_range); // 超出范围的删除应该抛出异常
}

// 测试弹出最后一个元素
TEST_F(SeqTableTest, PopBackTest) {
    seqTable.pop_back(); // 弹出最后一个元素
    EXPECT_EQ(seqTable.size(), 2); // 大小应该为2
}

// 测试空表
TEST(SeqTableEmptyTest, EmptyTest) {
    SeqTable<int> emptyTable;
    EXPECT_TRUE(emptyTable.empty()); // 确保为空
}

// 测试调整大小
TEST_F(SeqTableTest, ResizeTest) {
    seqTable.resize(5); // 调整为更大的大小
    EXPECT_EQ(seqTable.size(), 5); // 大小应该更新为5
    EXPECT_EQ(seqTable.at(0), 1); // 原始元素应该保留
    EXPECT_EQ(seqTable.at(1), 2);
    EXPECT_EQ(seqTable.at(2), 3);
}

// 测试调整大小为零
TEST_F(SeqTableTest, ResizeToZeroTest) {
    seqTable.resize(0); // 调整为0
    EXPECT_TRUE(seqTable.empty()); // 应该为空
}

// 测试异常：获取越界元素
TEST_F(SeqTableTest, AtOutOfRangeTest) {
    EXPECT_THROW(seqTable.at(5), std::out_of_range); // 超出范围的访问应该抛出异常
}
