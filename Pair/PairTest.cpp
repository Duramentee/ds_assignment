//
// Created by lsx31 on 24-12-14.
//
#include <gtest/gtest.h>
#include "Pair.hpp"

namespace ds {

TEST(PairTest, DefaultConstructor) {
    Pair<int, std::string> pair;
    EXPECT_EQ(pair.first_, 0);
    EXPECT_EQ(pair.second_, "");
}

TEST(PairTest, ParameterizedConstructor) {
    Pair<int, std::string> pair(42, "Hello");
    EXPECT_EQ(pair.first_, 42);
    EXPECT_EQ(pair.second_, "Hello");
}

TEST(PairTest, AssignmentOperator) {
    Pair<int, std::string> pair1(42, "Hello");
    Pair<int, std::string> pair2;
    pair2 = pair1;
    EXPECT_EQ(pair2.first_, 42);
    EXPECT_EQ(pair2.second_, "Hello");
}

TEST(PairTest, SelfAssignment) {
    Pair<int, std::string> pair(42, "Hello");
    pair = pair;
    EXPECT_EQ(pair.first_, 42);
    EXPECT_EQ(pair.second_, "Hello");
}

TEST(PairTest, EqualityOperator) {
    Pair<int, std::string> pair1(42, "Hello");
    Pair<int, std::string> pair2(42, "Hello");
    EXPECT_TRUE(pair1 == pair2);
}

TEST(PairTest, InequalityOperator) {
    Pair<int, std::string> pair1(42, "Hello");
    Pair<int, std::string> pair2(10, "World");
    EXPECT_TRUE(pair1 != pair2);
}

}  // namespace ds
