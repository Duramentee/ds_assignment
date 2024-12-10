//
// Created by lsx31 on 24-12-9.
//

#include <gtest/gtest.h>
#include "Queue.hpp" // 假设你的 Queue 类定义在这个头文件中

using namespace ds;

// 测试构造函数
TEST(QueueTest, Constructor) {
	Queue<int> q;
	EXPECT_TRUE(q.is_empty());
}

// 测试复制构造函数
TEST(QueueTest, CopyConstructor) {
	Queue<int> original;
	original.enqueue(1);
	original.enqueue(2);

	Queue<int> copy = original;
	EXPECT_EQ(copy.size(), 2);
	EXPECT_EQ(copy.peek(), 1);
}

// 测试赋值操作符
TEST(QueueTest, AssignmentOperator) {
	Queue<int> original;
	original.enqueue(3);
	original.enqueue(4);

	Queue<int> assigned;
	assigned = original;
	EXPECT_EQ(assigned.size(), 2);
	EXPECT_EQ(assigned.peek(), 3);
}

// 测试 enqueue 和 dequeue 方法
TEST(QueueTest, EnqueueDequeue) {
	Queue<int> q;
	q.enqueue(5);
	q.enqueue(6);
	EXPECT_EQ(q.size(), 2);

	EXPECT_EQ(q.dequeue(), 5);
	EXPECT_EQ(q.size(), 1);
	EXPECT_EQ(q.dequeue(), 6);
	EXPECT_TRUE(q.is_empty());
}

// 测试 clear 方法
TEST(QueueTest, Clear) {
	Queue<int> q;
	q.enqueue(7);
	q.clear();
	EXPECT_TRUE(q.is_empty());
}

// 测试 peek 方法
TEST(QueueTest, Peek) {
	Queue<int> q;
	q.enqueue(8);
	EXPECT_EQ(q.peek(), 8);
	EXPECT_EQ(q.size(), 1); // 确保 peek 不改变队列状态
}

// 测试 size 方法
TEST(QueueTest, Size) {
	Queue<int> q;
	EXPECT_EQ(q.size(), 0);
	q.enqueue(9);
	EXPECT_EQ(q.size(), 1);
}

// 测试在空队列上调用 dequeue 和 peek 的行为
TEST(QueueTest, EmptyQueueOperations) {
	Queue<int> q;
	EXPECT_THROW(q.dequeue(), std::runtime_error);
	EXPECT_THROW(q.peek(), std::runtime_error);
}