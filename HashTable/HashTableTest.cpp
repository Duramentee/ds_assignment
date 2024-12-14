//
// Created by lsx31 on 24-12-12.
//

#include <gtest/gtest.h>
#include "HashTable.hpp" // 确保路径正确

TEST(HashTableTest, InsertAndFind) {
    ds::HashTable<int, std::string> hash_table(5);

    // 插入元素
    hash_table.insert(1, "one");
    hash_table.insert(2, "two");

    std::string value;

    // 查找存在的元素
    EXPECT_TRUE(hash_table.find(1, value));
    EXPECT_EQ(value, "one");

    EXPECT_TRUE(hash_table.find(2, value));
    EXPECT_EQ(value, "two");

    // 查找不存在的元素
    EXPECT_FALSE(hash_table.find(3, value));
}

TEST(HashTableTest, Remove) {
    ds::HashTable<int, std::string> hash_table(5);

    // 插入元素
    hash_table.insert(1, "one");
    hash_table.insert(2, "two");

    // 删除存在的元素
    EXPECT_TRUE(hash_table.remove(1));

    // 再次查找已删除的元素
    std::string value;
    EXPECT_FALSE(hash_table.find(1, value));

    // 删除不存在的元素
    EXPECT_FALSE(hash_table.remove(3));
}

TEST(HashTableTest, UpdateValue) {
    ds::HashTable<int, std::string> hash_table(5);

    // 插入元素
    hash_table.insert(1, "one");

    // 更新元素值
    hash_table.insert(1, "updated_one");

    // 查找更新后的元素
    std::string value;
    EXPECT_TRUE(hash_table.find(1, value));
    EXPECT_EQ(value, "updated_one");
}


