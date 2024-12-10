#include <gtest/gtest.h>
#include "SeqTable.hpp"

using namespace ds;

TEST(SeqTableTest, Constructor_Default) {
    SeqTable<int> table;
    EXPECT_EQ(table.size(), 0);
    EXPECT_EQ(table.capacity(), 0);
}

TEST(SeqTableTest, Constructor_Size) {
    SeqTable<int> table(5);
    EXPECT_EQ(table.size(), 5);
    EXPECT_GE(table.capacity(), 10); // capacity should be at least double the size
}

TEST(SeqTableTest, CopyConstructor) {
    SeqTable<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;

    SeqTable<int> copy(original);
    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.capacity(), original.capacity());

    for (size_t i = 0; i < original.size(); ++i) {
        EXPECT_EQ(copy[i], original[i]);
    }
}

TEST(SeqTableTest, AssignmentOperator) {
    SeqTable<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;

    SeqTable<int> assigned;
    assigned = original;
    EXPECT_EQ(assigned.size(), original.size());
    EXPECT_EQ(assigned.capacity(), original.capacity());

    for (size_t i = 0; i < original.size(); ++i) {
        EXPECT_EQ(assigned[i], original[i]);
    }
}

TEST(SeqTableTest, MoveConstructor) {
    SeqTable<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;

    SeqTable<int> moved(std::move(original));
    EXPECT_EQ(moved.size(), 3);
    EXPECT_GE(moved.capacity(), 6);

    EXPECT_EQ(original.size(), 0);
    EXPECT_EQ(original.capacity(), 0);

    EXPECT_EQ(moved[0], 1);
    EXPECT_EQ(moved[1], 2);
    EXPECT_EQ(moved[2], 3);
}

TEST(SeqTableTest, MoveAssignmentOperator) {
    SeqTable<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;

    SeqTable<int> moved;
    moved = std::move(original);
    EXPECT_EQ(moved.size(), 3);
    EXPECT_GE(moved.capacity(), 6);

    EXPECT_EQ(original.size(), 0);
    EXPECT_EQ(original.capacity(), 0);

    EXPECT_EQ(moved[0], 1);
    EXPECT_EQ(moved[1], 2);
    EXPECT_EQ(moved[2], 3);
}

TEST(SeqTableTest, Resize) {
    SeqTable<int> table(3);
    table.resize(5);
    EXPECT_EQ(table.size(), 3);
    EXPECT_GE(table.capacity(), 5);

    table.resize(2);
    EXPECT_EQ(table.size(), 2);
    EXPECT_GE(table.capacity(), 2);
}

TEST(SeqTableTest, PushBack) {
    SeqTable<int> table;
    table.push_back(1);
    table.push_back(2);
    table.push_back(3);

    EXPECT_EQ(table.size(), 3);
    EXPECT_EQ(table[0], 1);
    EXPECT_EQ(table[1], 2);
    EXPECT_EQ(table[2], 3);
}

TEST(SeqTableTest, Insert) {
    SeqTable<int> table(3);
    table[0] = 1;
    table[1] = 2;
    table[2] = 3;

    table.insert(1, 10);
    EXPECT_EQ(table.size(), 4);
    EXPECT_EQ(table[0], 1);
    EXPECT_EQ(table[1], 10);
    EXPECT_EQ(table[2], 2);
    EXPECT_EQ(table[3], 3);
}

TEST(SeqTableTest, PopBack) {
    SeqTable<int> table(3);
    table[0] = 1;
    table[1] = 2;
    table[2] = 3;

    table.pop_back();
    EXPECT_EQ(table.size(), 2);
    EXPECT_EQ(table[0], 1);
    EXPECT_EQ(table[1], 2);
}

TEST(SeqTableTest, Erase) {
    SeqTable<int> table(3);
    table[0] = 1;
    table[1] = 2;
    table[2] = 3;

    table.erase(1);
    EXPECT_EQ(table.size(), 2);
    EXPECT_EQ(table[0], 1);
    EXPECT_EQ(table[1], 3);
}

TEST(SeqTableTest, At) {
    SeqTable<int> table(3);
    table[0] = 1;
    table[1] = 2;
    table[2] = 3;

    EXPECT_EQ(table.at(0), 1);
    EXPECT_EQ(table.at(1), 2);
    EXPECT_EQ(table.at(2), 3);
    EXPECT_THROW(table.at(3), std::out_of_range);
}

TEST(SeqTableTest, OperatorBrackets) {
    SeqTable<int> table(3);
    table[0] = 1;
    table[1] = 2;
    table[2] = 3;

    EXPECT_EQ(table[0], 1);
    EXPECT_EQ(table[1], 2);
    EXPECT_EQ(table[2], 3);
    EXPECT_THROW(table[3], std::out_of_range);
}

TEST(SeqTableTest, FrontAndBack) {
    SeqTable<int> table(3);
    table[0] = 1;
    table[1] = 2;
    table[2] = 3;

    EXPECT_EQ(table.front(), 1);
    EXPECT_EQ(table.back(), 3);
}

TEST(SeqTableTest, EmptySizeCapacityBeginEnd) {
    SeqTable<int> table;
    EXPECT_TRUE(table.empty());
    EXPECT_EQ(table.size(), 0);
    EXPECT_EQ(table.capacity(), 0);
    EXPECT_EQ(table.begin(), table.end());
    EXPECT_EQ(table.cbegin(), table.cend());
}



