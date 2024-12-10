//
// Created by drowlia on 24-12-9.
//

#include <gtest/gtest.h>
#include "Stack.hpp"

using namespace ds;

TEST(StackTest, Constructor_Default) {
    Stack<int> stack(10);
    EXPECT_EQ(stack.size(), 0);
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, Push) {
    Stack<int> stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.size(), 3);
    EXPECT_FALSE(stack.empty());
}

TEST(StackTest, Pop) {
    Stack<int> stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.top(), 2);

    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 1);

    stack.pop();
    EXPECT_EQ(stack.size(), 0);
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, Top) {
    Stack<int> stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.top(), 3);

    stack.pop();
    EXPECT_EQ(stack.top(), 2);

    stack.pop();
    EXPECT_EQ(stack.top(), 1);
}

TEST(StackTest, Empty) {
    Stack<int> stack(3);
    EXPECT_TRUE(stack.empty());

    stack.push(1);
    EXPECT_FALSE(stack.empty());

    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, Size) {
    Stack<int> stack(3);
    EXPECT_EQ(stack.size(), 0);

    stack.push(1);
    EXPECT_EQ(stack.size(), 1);

    stack.push(2);
    EXPECT_EQ(stack.size(), 2);

    stack.push(3);
    EXPECT_EQ(stack.size(), 3);

    stack.pop();
    EXPECT_EQ(stack.size(), 2);

    stack.pop();
    EXPECT_EQ(stack.size(), 1);

    stack.pop();
    EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, CopyConstructor) {
    Stack<int> original(3);
    original.push(1);
    original.push(2);
    original.push(3);

    Stack<int> copy(original);
    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.top(), original.top());

    while (!original.empty()) {
        EXPECT_EQ(copy.top(), original.top());
        copy.pop();
        original.pop();
    }
}

TEST(StackTest, CopyAssignment) {
    Stack<int> original(3);
    original.push(1);
    original.push(2);
    original.push(3);

    Stack<int> assigned = original;
    EXPECT_EQ(assigned.size(), original.size());
    EXPECT_EQ(assigned.top(), original.top());

    while (!original.empty()) {
        EXPECT_EQ(assigned.top(), original.top());
        assigned.pop();
        original.pop();
    }
}

TEST(StackTest, MoveConstructor) {
    Stack<int> original(3);
    original.push(1);
    original.push(2);
    original.push(3);

    Stack<int> moved(std::move(original));
    EXPECT_EQ(moved.size(), 3);
    EXPECT_EQ(moved.top(), 3);

    moved.pop();
    EXPECT_EQ(moved.top(), 2);

    moved.pop();
    EXPECT_EQ(moved.top(), 1);
}

TEST(StackTest, MoveAssignmentOperator) {
    Stack<int> original(3);
    original.push(1);
    original.push(2);
    original.push(3);

    Stack<int> moved = std::move(original);
    EXPECT_EQ(moved.size(), 3);
    EXPECT_EQ(moved.top(), 3);

    moved.pop();
    EXPECT_EQ(moved.top(), 2);

    moved.pop();
    EXPECT_EQ(moved.top(), 1);
}
