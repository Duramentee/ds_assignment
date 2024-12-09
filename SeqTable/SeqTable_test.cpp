#include "SeqTable.hpp"
#include <gtest/gtest.h>

namespace ds {

TEST(SeqTableTest, Constructor) {
    SeqTable<int> table(10);
    EXPECT_EQ(table.size(), 10u);
    EXPECT_EQ(table.capacity(), 20u);
}

TEST(SeqTableTest, CopyConstructor) {
    SeqTable<int> original(5);
    for (int i = 0; i < 5; ++i) {
        original.push_back(i);
    }
    SeqTable<int> copy(original);
    EXPECT_EQ(copy.size(), 10u);
    EXPECT_EQ(copy.capacity(), 10u);
    for (int i = 5; i < 10; ++i) {
        EXPECT_EQ(copy[i], i - 5);
    }
}

TEST(SeqTableTest, MoveConstructor) {
    SeqTable<int> original(5);
    for (int i = 0; i < 5; ++i) {
        original.push_back(i);
    }
    SeqTable<int> moved(std::move(original));
    EXPECT_EQ(moved.size(), 10u);
    EXPECT_EQ(moved.capacity(), 10u);
    for (int i = 5; i < 10; ++i) {
        EXPECT_EQ(moved[i], i - 5);
    }
    EXPECT_TRUE(original.empty());
}

TEST(SeqTableTest, CopyAssignment) {
    SeqTable<int> original(5);
    for (int i = 0; i < 5; ++i) {
        original.push_back(i);
    }
    SeqTable<int> copy = original;
    EXPECT_EQ(copy.size(), 10u);
    EXPECT_EQ(copy.capacity(), 10u);
    for (int i = 5; i < 10; ++i) {
        EXPECT_EQ(copy[i], i - 5);
    }
}

TEST(SeqTableTest, MoveAssignment) {
    SeqTable<int> original(5);
    for (int i = 0; i < 5; ++i) {
        original.push_back(i);
    }
    SeqTable<int> moved = std::move(original);
    EXPECT_EQ(moved.size(), 10u);
    EXPECT_EQ(moved.capacity(), 10u);
    for (int i = 5; i < 10; ++i) {
        EXPECT_EQ(moved[i], i - 5);
    }
    EXPECT_TRUE(original.empty());
}

TEST(SeqTableTest, Insert) {
    SeqTable<int> table(1);
    table[0] = 1;
    table.insert(0, 0);
    EXPECT_EQ(table.size(), 2u);
    EXPECT_EQ(table[0], 0);
    EXPECT_EQ(table[1], 1);
}

TEST(SeqTableTest, PopBack) {
    SeqTable<int> table(2);
    table[0] = 1;
    table[1] = 2;
    table.pop_back();
    EXPECT_EQ(table.size(), 1u);
    EXPECT_EQ(table[0], 1);
}

TEST(SeqTableTest, Erase) {
    SeqTable<int> table(3);
    for (int i = 0; i < 3; ++i) {
        table[i] = i;
    }
    table.erase(1);
    EXPECT_EQ(table.size(), 2u);
    EXPECT_EQ(table[0], 0);
    EXPECT_EQ(table[1], 2);
}

TEST(SeqTableTest, At) {
    SeqTable<int> table(2);
    table[0] = 1;
    table[1] = 2;
    EXPECT_EQ(table.at(0), 1);
    EXPECT_EQ(table.at(1), 2);
}

TEST(SeqTableTest, OperatorBrackets) {
    SeqTable<int> table(2);
    table[0] = 1;
    table[1] = 2;
    EXPECT_EQ(table[0], 1);
    EXPECT_EQ(table[1], 2);
}

TEST(SeqTableTest, FrontBack) {
    SeqTable<int> table(2);
    table[0] = 1;
    table[1] = 2;
    EXPECT_EQ(table.front(), 1);
    EXPECT_EQ(table.back(), 2);
}

TEST(SeqTableTest, EmptySize) {
    SeqTable<int> table(1);
    table.erase(0);
    EXPECT_TRUE(table.empty());
    table.push_back(1);
    EXPECT_FALSE(table.empty());
    EXPECT_EQ(table.size(), 1u);
}

TEST(SeqTableTest, Iterators) {
    SeqTable<int> table(3);
    for (int i = 0; i < 3; ++i) {
        table[i] = i;
    }
    const std::vector<int> vec(table.begin(), table.end());
    EXPECT_EQ(vec.size(), 3u);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], i);
    }
}

TEST(SeqTableTest, Print) {
    SeqTable<int> table(3);
    for (int i = 0; i < 3; ++i) {
        table.push_back(i);
    }
    EXPECT_NO_THROW(table.print());
}

}  // namespace ds

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}