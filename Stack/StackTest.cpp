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
