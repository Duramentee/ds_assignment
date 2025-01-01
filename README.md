# 数据结构作业

[TOC]

------

已上传到我的 github 仓库:

[[Duramentee/ds_assignment](](https://github.com/Duramentee/ds_assignment)


## 概述

在仅使用数组以及自己实现的数据结构支持下, 仿照了部分 stl 的数据结构规范和 stl 提供的对应容器操作接口实现了一些简陋的容器.

实现了:

- `SeqTable` 顺序表 (仿照 `std::vector` 实现, 支持自动扩容)
- `LinkedList` 双向链表 (仿照 `std::list` 实现, 支持迭代器访问)
- `Stack` 栈 (仿照 `std::stack` 实现)
- `Queue` 队列
- `Tree` 二叉搜索树
- `Pair` 二元组绑定器 (为适配哈希表实现, 仿照 `std::pair` 实现)
- `HashTable` 哈希表
- `Graph` 图  



项目使用cmake作为构建工具.

## CMakeLists.txt

内容如下:

```cmake
cmake_minimum_required(VERSION 3.29.6)
project(ds)

set(CMAKE_CXX_STANDARD 17)

add_executable(ds main.cpp
        SeqTable/SeqTable.hpp
        SeqTable/SeqTableTest.cpp
        LinkedList/LinkedList.hpp
        LinkedList/LinkedListTest.cpp
        Stack/Stack.hpp
        Stack/StackTest.cpp
        Queue/Queue.hpp
        Queue/QueueTest.cpp
        Tree/BinaryTree.hpp
        Tree/BinaryTreeTest.cpp
        Pair/Pair.hpp
        Pair/PairTest.cpp
        HashTable/HashTable.hpp
        HashTable/HashTableTest.cpp
        Graph/Graph.hpp
        Graph/GraphTest.cpp
)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(ds ${GTEST_LIBRARIES} pthread)
```



## main.cpp

主函数如下:

```c++
#include <gtest/gtest.h>

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

```



## 测试

使用 googletest 作为测试框架.

测试用例由 ai 根据源码生成, 再做了一些细节修改

在我的 wsl-kali-linux上可正常运行

测试环境为: 

Kali GNU/Linux Rolling

Linux version 5.15.167.4-microsoft-standard-WSL2

gcc version 14.2.0 (Debian 14.2.0-8)

测试结果输出如下:

```text
\\wsl.localhost\kali-linux\home\drowlia\code_save\ds\cmake-build-debug-\ds
[==========] Running 81 tests from 8 test suites.
[----------] Global test environment set-up.
[----------] 15 tests from SeqTableTest
[ RUN      ] SeqTableTest.Constructor_Default
[       OK ] SeqTableTest.Constructor_Default (0 ms)
[ RUN      ] SeqTableTest.Constructor_Size
[       OK ] SeqTableTest.Constructor_Size (0 ms)
[ RUN      ] SeqTableTest.CopyConstructor
[       OK ] SeqTableTest.CopyConstructor (0 ms)
[ RUN      ] SeqTableTest.AssignmentOperator
[       OK ] SeqTableTest.AssignmentOperator (0 ms)
[ RUN      ] SeqTableTest.MoveConstructor
[       OK ] SeqTableTest.MoveConstructor (0 ms)
[ RUN      ] SeqTableTest.MoveAssignmentOperator
[       OK ] SeqTableTest.MoveAssignmentOperator (0 ms)
[ RUN      ] SeqTableTest.Resize
[       OK ] SeqTableTest.Resize (0 ms)
[ RUN      ] SeqTableTest.PushBack
[       OK ] SeqTableTest.PushBack (0 ms)
[ RUN      ] SeqTableTest.Insert
[       OK ] SeqTableTest.Insert (0 ms)
[ RUN      ] SeqTableTest.PopBack
[       OK ] SeqTableTest.PopBack (0 ms)
[ RUN      ] SeqTableTest.Erase
[       OK ] SeqTableTest.Erase (0 ms)
[ RUN      ] SeqTableTest.At
[       OK ] SeqTableTest.At (1 ms)
[ RUN      ] SeqTableTest.OperatorBrackets
[       OK ] SeqTableTest.OperatorBrackets (0 ms)
[ RUN      ] SeqTableTest.FrontAndBack
[       OK ] SeqTableTest.FrontAndBack (0 ms)
[ RUN      ] SeqTableTest.EmptySizeCapacityBeginEnd
[       OK ] SeqTableTest.EmptySizeCapacityBeginEnd (0 ms)
[----------] 15 tests from SeqTableTest (1 ms total)

[----------] 12 tests from LinkedListTest
[ RUN      ] LinkedListTest.DefaultConstructor
[       OK ] LinkedListTest.DefaultConstructor (0 ms)
[ RUN      ] LinkedListTest.ParameterizedConstructor
[       OK ] LinkedListTest.ParameterizedConstructor (0 ms)
[ RUN      ] LinkedListTest.PushFront
[       OK ] LinkedListTest.PushFront (0 ms)
[ RUN      ] LinkedListTest.PushBack
[       OK ] LinkedListTest.PushBack (0 ms)
[ RUN      ] LinkedListTest.Insert
[       OK ] LinkedListTest.Insert (0 ms)
[ RUN      ] LinkedListTest.PopFront
[       OK ] LinkedListTest.PopFront (0 ms)
[ RUN      ] LinkedListTest.PopBack
[       OK ] LinkedListTest.PopBack (0 ms)
[ RUN      ] LinkedListTest.Erase
[       OK ] LinkedListTest.Erase (0 ms)
[ RUN      ] LinkedListTest.Find
[       OK ] LinkedListTest.Find (0 ms)
[ RUN      ] LinkedListTest.Clear
[       OK ] LinkedListTest.Clear (0 ms)
[ RUN      ] LinkedListTest.CopyConstructor
[       OK ] LinkedListTest.CopyConstructor (0 ms)
[ RUN      ] LinkedListTest.AssignmentOperator
[       OK ] LinkedListTest.AssignmentOperator (0 ms)
[----------] 12 tests from LinkedListTest (0 ms total)

[----------] 10 tests from StackTest
[ RUN      ] StackTest.Constructor_Default
[       OK ] StackTest.Constructor_Default (0 ms)
[ RUN      ] StackTest.Push
[       OK ] StackTest.Push (0 ms)
[ RUN      ] StackTest.Pop
[       OK ] StackTest.Pop (0 ms)
[ RUN      ] StackTest.Top
[       OK ] StackTest.Top (0 ms)
[ RUN      ] StackTest.Empty
[       OK ] StackTest.Empty (0 ms)
[ RUN      ] StackTest.Size
[       OK ] StackTest.Size (0 ms)
[ RUN      ] StackTest.CopyConstructor
[       OK ] StackTest.CopyConstructor (0 ms)
[ RUN      ] StackTest.CopyAssignment
[       OK ] StackTest.CopyAssignment (0 ms)
[ RUN      ] StackTest.MoveConstructor
[       OK ] StackTest.MoveConstructor (0 ms)
[ RUN      ] StackTest.MoveAssignmentOperator
[       OK ] StackTest.MoveAssignmentOperator (0 ms)
[----------] 10 tests from StackTest (0 ms total)

[----------] 8 tests from QueueTest
[ RUN      ] QueueTest.Constructor
[       OK ] QueueTest.Constructor (0 ms)
[ RUN      ] QueueTest.CopyConstructor
[       OK ] QueueTest.CopyConstructor (0 ms)
[ RUN      ] QueueTest.AssignmentOperator
[       OK ] QueueTest.AssignmentOperator (0 ms)
[ RUN      ] QueueTest.EnqueueDequeue
[       OK ] QueueTest.EnqueueDequeue (0 ms)
[ RUN      ] QueueTest.Clear
[       OK ] QueueTest.Clear (0 ms)
[ RUN      ] QueueTest.Peek
[       OK ] QueueTest.Peek (0 ms)
[ RUN      ] QueueTest.Size
[       OK ] QueueTest.Size (0 ms)
[ RUN      ] QueueTest.EmptyQueueOperations
[       OK ] QueueTest.EmptyQueueOperations (0 ms)
[----------] 8 tests from QueueTest (0 ms total)

[----------] 21 tests from BinaryTreeTest
[ RUN      ] BinaryTreeTest.Insert
[       OK ] BinaryTreeTest.Insert (0 ms)
[ RUN      ] BinaryTreeTest.PreOrderTraversal
[       OK ] BinaryTreeTest.PreOrderTraversal (0 ms)
[ RUN      ] BinaryTreeTest.InOrderTraversal
[       OK ] BinaryTreeTest.InOrderTraversal (0 ms)
[ RUN      ] BinaryTreeTest.PostOrderTraversal
[       OK ] BinaryTreeTest.PostOrderTraversal (0 ms)
[ RUN      ] BinaryTreeTest.LevelOrderTraversal
[       OK ] BinaryTreeTest.LevelOrderTraversal (0 ms)
[ RUN      ] BinaryTreeTest.SearchTest
[       OK ] BinaryTreeTest.SearchTest (0 ms)
[ RUN      ] BinaryTreeTest.FindMaxValueTest
[       OK ] BinaryTreeTest.FindMaxValueTest (0 ms)
[ RUN      ] BinaryTreeTest.FindMinValueTest
[       OK ] BinaryTreeTest.FindMinValueTest (0 ms)
[ RUN      ] BinaryTreeTest.FindMin
[       OK ] BinaryTreeTest.FindMin (0 ms)
[ RUN      ] BinaryTreeTest.FindMax
[       OK ] BinaryTreeTest.FindMax (0 ms)
[ RUN      ] BinaryTreeTest.CalculateHeight
[       OK ] BinaryTreeTest.CalculateHeight (0 ms)
[ RUN      ] BinaryTreeTest.EmptyTreeIsBST
[       OK ] BinaryTreeTest.EmptyTreeIsBST (0 ms)
[ RUN      ] BinaryTreeTest.SingleNodeTreeIsBST
[       OK ] BinaryTreeTest.SingleNodeTreeIsBST (0 ms)
[ RUN      ] BinaryTreeTest.ValidBST
[       OK ] BinaryTreeTest.ValidBST (0 ms)
[ RUN      ] BinaryTreeTest.InvalidBST
[       OK ] BinaryTreeTest.InvalidBST (0 ms)
[ RUN      ] BinaryTreeTest.LeftSkewedTreeIsBST
[       OK ] BinaryTreeTest.LeftSkewedTreeIsBST (0 ms)
[ RUN      ] BinaryTreeTest.RightSkewedTreeIsBST
[       OK ] BinaryTreeTest.RightSkewedTreeIsBST (0 ms)
[ RUN      ] BinaryTreeTest.EraseLeafNode
[       OK ] BinaryTreeTest.EraseLeafNode (0 ms)
[ RUN      ] BinaryTreeTest.EraseNodeWithOneChild
[       OK ] BinaryTreeTest.EraseNodeWithOneChild (0 ms)
[ RUN      ] BinaryTreeTest.EraseNodeWithTwoChildren
[       OK ] BinaryTreeTest.EraseNodeWithTwoChildren (0 ms)
[ RUN      ] BinaryTreeTest.EraseNonExistentNode
[       OK ] BinaryTreeTest.EraseNonExistentNode (0 ms)
[----------] 21 tests from BinaryTreeTest (0 ms total)

[----------] 6 tests from PairTest
[ RUN      ] PairTest.DefaultConstructor
[       OK ] PairTest.DefaultConstructor (0 ms)
[ RUN      ] PairTest.ParameterizedConstructor
[       OK ] PairTest.ParameterizedConstructor (0 ms)
[ RUN      ] PairTest.AssignmentOperator
[       OK ] PairTest.AssignmentOperator (0 ms)
[ RUN      ] PairTest.SelfAssignment
[       OK ] PairTest.SelfAssignment (0 ms)
[ RUN      ] PairTest.EqualityOperator
[       OK ] PairTest.EqualityOperator (0 ms)
[ RUN      ] PairTest.InequalityOperator
[       OK ] PairTest.InequalityOperator (0 ms)
[----------] 6 tests from PairTest (0 ms total)

[----------] 3 tests from HashTableTest
[ RUN      ] HashTableTest.InsertAndFind
[       OK ] HashTableTest.InsertAndFind (0 ms)
[ RUN      ] HashTableTest.Remove
[       OK ] HashTableTest.Remove (0 ms)
[ RUN      ] HashTableTest.UpdateValue
[       OK ] HashTableTest.UpdateValue (0 ms)
[----------] 3 tests from HashTableTest (0 ms total)

[----------] 6 tests from GraphTest
[ RUN      ] GraphTest.Constructor
[       OK ] GraphTest.Constructor (0 ms)
[ RUN      ] GraphTest.AddEdge
[       OK ] GraphTest.AddEdge (0 ms)
[ RUN      ] GraphTest.RemoveEdge
[       OK ] GraphTest.RemoveEdge (0 ms)
[ RUN      ] GraphTest.HasEdge
[       OK ] GraphTest.HasEdge (0 ms)
[ RUN      ] GraphTest.GetNeighbors
[       OK ] GraphTest.GetNeighbors (0 ms)
[ RUN      ] GraphTest.PrintGraph
[       OK ] GraphTest.PrintGraph (0 ms)
[----------] 6 tests from GraphTest (0 ms total)

[----------] Global test environment tear-down
[==========] 81 tests from 8 test suites ran. (2 ms total)
[  PASSED  ] 81 tests.

进程已结束，退出代码为 0
```





## 容器代码:

### SeqTable.hpp

```c++
//
// Created by lsx31 on 24-12-9.
//

#pragma once

#include <iostream>
#include <algorithm>

namespace ds {

template <typename ElemType>
struct SeqTable {
	size_t size_;
	size_t capacity_;
	ElemType *array_;

	SeqTable() : size_{0}, capacity_{0}, array_{nullptr} {}

	explicit SeqTable(size_t size) :
		size_{size},
		capacity_{size ? 2 * size : 0},
		array_{size ? new ElemType[capacity_]() : nullptr} {
	}

	~SeqTable() {
		delete[] array_;
		array_ = nullptr;
	}

	SeqTable(const SeqTable& ano_table) :
		size_{ano_table.size_},
		capacity_{ano_table.capacity_},
		array_{ano_table.size_ ? new ElemType[ano_table.capacity_]() : nullptr} {
			if (ano_table.size_ > 0)
				std::copy(ano_table.array_, ano_table.array_ + size_, array_);
	}

	SeqTable& operator=(const SeqTable& ano_table) {
		if (this == &ano_table)
			return *this;

		delete[] array_;

		size_ = ano_table.size_;
		capacity_ = ano_table.capacity_;
		array_ = ano_table.size_ ? new ElemType[ano_table.capacity_]() : nullptr;

		if (ano_table.size_ > 0) {
			std::copy(ano_table.array_, ano_table.array_ + size_, array_);
		}

		return *this;
	}

	SeqTable(SeqTable&& ano_table) noexcept :
		size_{ano_table.size_},
		capacity_{ano_table.capacity_},
		array_{ano_table.array_} {
			ano_table.size_ = 0;
			ano_table.capacity_ = 0;
			ano_table.array_ = nullptr;
	}

	SeqTable& operator=(SeqTable&& ano_table) noexcept {
		if (this == &ano_table)
			return *this;

		delete[] array_;

		size_ = ano_table.size_;
		capacity_ = ano_table.capacity_;
		array_ = ano_table.array_;

		ano_table.size_ = 0;
		ano_table.capacity_ = 0;
		ano_table.array_ = nullptr;

		return *this;
	}

	void resize(const size_t& new_size) {
		if (new_size == 0) {
			delete[] array_;
			size_ = 0;
			capacity_ = 0;
			array_ = nullptr;
			return;
		}

		auto *new_array = new ElemType[new_size]();
		auto copy_size = std::min(size_, new_size);
		std::copy(array_, array_ + copy_size, new_array);

		delete[] array_;

		if (new_size < size_)
			size_ = new_size;

		capacity_ = new_size;

		array_ = new_array;
	}

	void push_back(const ElemType& elem) {
		if (size_ >= capacity_)
			resize(capacity_ == 0 ? 1 : capacity_ * 2);

		array_[size_] = elem;
		++size_;
	}

	void insert(const size_t& pos, const ElemType& elem) {
		if (pos > size_)
			throw std::out_of_range("Index out of range");

		if (size_ >= capacity_)
			resize(capacity_ == 0 ? 1 : capacity_ * 2);

		std::move(array_ + pos, array_ + size_, array_ + pos + 1);

		array_[pos] = elem;
		++size_;
	}

	void pop_back() {
		if (size_ > 0)
			--size_;
	}

	void erase(const size_t& pos) {
		if (pos >= size_)
			throw std::out_of_range("Index out of range");

		std::move(array_ + pos + 1, array_ + size_, array_ + pos);

		--size_;
	}

	const ElemType& at(const size_t& pos) const {
		if (pos >= size_)
			throw std::out_of_range("Index out of range");

		return array_[pos];
	}

	ElemType& operator[](const size_t& pos) {
		if (pos >= size_)
			throw std::out_of_range("Index out of range");

		return array_[pos];
	}

	const ElemType& operator[](const size_t& pos) const {
		if (pos >= size_)
			throw std::out_of_range("Index out of range");

		return array_[pos];
	}

	const ElemType& front() const {
		return array_[0];
	}

	const ElemType& back() const {
		return array_[size_ - 1];
	}

	[[nodiscard]] bool            empty()    const { return size_ == 0; }

	[[nodiscard]] size_t          size()     const { return size_; }
	[[nodiscard]] size_t          capacity() const { return capacity_; }

	[[nodiscard]] ElemType*       begin()    const { return array_; }
	[[nodiscard]] const ElemType* cbegin()   const { return array_; }

	[[nodiscard]] ElemType*       end()      const { return array_ + size_; }
	[[nodiscard]] const ElemType* cend()     const { return array_ + size_; }

	void print() const {
		for (size_t i = 0; i < size_; ++i) {
			std::cout << array_[i] << " ";
		}
		std::cout << std::endl;
	}
};

}
```



### LinkedList.hpp

```c++
#pragma once

#include <iostream>

namespace ds {

template <typename ElemType>
struct Node {
    ElemType data_;
    Node* next_;
    Node* prev_;

    explicit Node(const ElemType& val) : data_{val}, next_{nullptr}, prev_{nullptr} {
    }

    ~Node() {
        next_ = nullptr;
        prev_ = nullptr;
    }

    Node(const Node& ano_node) : data_{ano_node.data_}, next_{nullptr}, prev_{nullptr} {
    }
};

template <typename ElemType>
struct LinkedList {

struct Iterator {
    Node<ElemType>* node_;

    explicit Iterator(Node<ElemType>* node = nullptr) : node_{node} {}

    Iterator& operator++() {
        if (node_ != nullptr) {
            node_ = node_->next_;
        }
        return *this;
    }
    Iterator operator++(int) {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

    Iterator& operator--() {
        if (node_ != nullptr) {
            node_ = node_->prev_;
        }
        return *this;
    }
    Iterator operator--(int) {
        Iterator temp = *this;
        --(*this);
        return temp;
    }

    Iterator& operator+=(const size_t n) {
        for (size_t i = 0; i < n && node_ != nullptr; ++i) {
            node_ = node_->next_;
        }
        return *this;
    }
    Iterator& operator-=(const size_t n) {
        for (size_t i = 0; i < n && node_ != nullptr; ++i) {
            node_ = node_->prev_;
        }
        return *this;
    }

    ElemType& operator*() {
        return node_->data_;
    }
    const ElemType& operator*() const {
        return node_->data_;
    }

    ElemType* operator->() {
        return &(node_->data_);
    }
    const ElemType* operator->() const {
        return &(node_->data_);
    }

    bool operator==(const Iterator& other) const {
        return node_ == other.node_;
    }
    bool operator!=(const Iterator& other) const {
        return node_ != other.node_;
    }

};

    Node<ElemType>* head_;
    Node<ElemType>* tail_;

    LinkedList() : head_{nullptr}, tail_{nullptr} {}

    explicit LinkedList(ElemType val) : head_{new Node<ElemType>(val)}, tail_{head_} {}

    ~LinkedList() { clear(); }

    LinkedList(const LinkedList& ano_list) : head_{nullptr}, tail_{nullptr} {
        if (ano_list.head_ != nullptr) {
            head_ = new Node<ElemType>(ano_list.head_->data_);
            tail_ = head_;
            Node<ElemType>* this_current = head_;
            Node<ElemType>* ano_current = ano_list.head_->next_;

            while (ano_current != nullptr) {
                this_current->next_ = new Node<ElemType>(ano_current->data_);
                this_current->next_->prev_ = this_current;
                this_current = this_current->next_;
                tail_ = this_current;
                ano_current = ano_current->next_;
            }
        }
    }

    LinkedList& operator=(const LinkedList& ano_list) {
        if (this != &ano_list) {
            clear();

            if (ano_list.head_ != nullptr) {
                head_ = new Node<ElemType>(ano_list.head_->data_);
                tail_ = head_;
                Node<ElemType>* this_current = head_;
                Node<ElemType>* ano_current = ano_list.head_->next_;

                while (ano_current != nullptr) {
                    this_current->next_ = new Node<ElemType>(ano_current->data_);
                    this_current->next_->prev_ = this_current;
                    this_current = this_current->next_;
                    tail_ = this_current;
                    ano_current = ano_current->next_;
                }
            }
            else {
                head_ = nullptr;
                tail_ = nullptr;
            }
        }
        return *this;
    }


    void clear() {
        Node<ElemType>* current = head_;
        while (current != nullptr) {
            Node<ElemType>* next = current->next_;
            delete current;
            current = next;
        }
        head_ = nullptr;
        tail_ = nullptr;
    }

    void push_front(const ElemType& val) {
        Node<ElemType>* new_node = new Node(val);
        new_node->next_ = head_;
        if (head_ != nullptr) {
            head_->prev_ = new_node;
        }
        head_ = new_node;
        if (tail_ == nullptr) {
            tail_ = new_node;
        }
    }

    void push_back(const ElemType& val) {
        Node<ElemType>* new_node = new Node(val);
        if (tail_ != nullptr) {
            tail_->next_ = new_node;
            new_node->prev_ = tail_;
        }
        tail_ = new_node;
        if (head_ == nullptr) {
            head_ = new_node;
        }
    }

    Iterator insert(Iterator pos, const ElemType& val) {
        Node<ElemType>* new_node = new Node(val);
        Node<ElemType>* current = pos.node_;

        if (current == nullptr) {
            push_back(val);
            return Iterator(tail_);
        }

        new_node->next_ = current;
        new_node->prev_ = current->prev_;

        if (current->prev_ != nullptr) {
            current->prev_->next_ = new_node;
        }
        else {
            head_ = new_node;
        }

        current->prev_ = new_node;

        return Iterator(new_node);
    }

    void pop_front() {
        if (head_ == nullptr)
            return;

        Node<ElemType>* old_head = head_;
        head_ = head_->next_;

        if (head_ != nullptr) {
            head_->prev_ = nullptr;
        } else {
            tail_ = nullptr;
        }

        delete old_head;
    }

    void pop_back() {
        if (head_ == nullptr)
            return;
        if (head_->next_ == nullptr) {
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
            return;
        }

        Node<ElemType>* current = tail_;
        tail_ = tail_->prev_;
        tail_->next_ = nullptr;

        delete current;
    }

    Iterator erase(Iterator pos) {
        Node<ElemType>* current = pos.node_;
        if (current == nullptr) {
            return end();
        }

        Node<ElemType>* next = current->next_;
        Node<ElemType>* prev = current->prev_;

        if (prev != nullptr) {
            prev->next_ = next;
        }
        else {
            head_ = next;
        }

        if (next != nullptr) {
            next->prev_ = prev;
        }
        else {
            tail_ = prev;
        }

        delete current;

        return Iterator(next);
    }

    [[nodiscard]] bool find(const ElemType& val) const {
        Node<ElemType>* current = head_;
        while (current != nullptr) {
            if (current->data_ == val)
                return true;
            current = current->next_;
        }

        return false;
    }

    void print() const {
        Node<ElemType>* current = head_;
        while (current != nullptr) {
            std::cout << current->data_ << " ";
            current = current->next_;
        }
        std::cout << std::endl;
    }

    [[nodiscard]] bool empty()  const { return head_ == nullptr; }
    Iterator           begin()        { return Iterator(head_); }
    Iterator           end()          { return Iterator(nullptr); }
    Iterator           begin()  const { return Iterator(head_); }
    Iterator           end()    const { return Iterator(nullptr); }
};

}

```



### Stack.hpp

```c++
#pragma once

#include "../SeqTable/SeqTable.hpp"

namespace ds {

template <typename ElemType>
struct Stack {
	SeqTable<ElemType>* vec_;

	Stack() = default;

	explicit Stack(size_t size) {
		vec_ = new SeqTable<ElemType>();
		vec_->size_ = 0;
		vec_->resize(size);
	}

	~Stack() {
		delete vec_;
	}

	Stack(const Stack& other) {
		vec_ = new SeqTable<ElemType>();

		vec_->size_ = other.vec_->size_;
		vec_->capacity_ = other.vec_->capacity_;
		vec_->array_ = new ElemType[vec_->capacity_]();

		for (size_t i = 0; i < vec_->size_; ++i) {
			vec_->array_[i] = other.vec_->array_[i];
		}
	}

	Stack& operator=(const Stack& other) {
		if (this != &other) {
			delete vec_;

			vec_ = new SeqTable<ElemType>();
			vec_->size_ = other.vec_->size_;
			vec_->capacity_ = other.vec_->capacity_;
			vec_->array_ = new ElemType[vec_->capacity_]();

			for (size_t i = 0; i < vec_->size_; ++i) {
				vec_->array_[i] = other.vec_->array_[i];
			}
		}

		return *this;
	}

	Stack(Stack&& other) noexcept : vec_(other.vec_) {
		other.vec_ = nullptr;
	}

	Stack& operator=(Stack&& other) noexcept {
		if (this != &other) {
			delete vec_;
			vec_ = other.vec_;
			other.vec_ = nullptr;
		}
		return *this;
	}

	void push(ElemType value) {
		vec_->push_back(value);
	}

	void pop() {
		vec_->pop_back();
	}

	const ElemType& top() const {
		return vec_->back();
	}

	[[nodiscard]] bool empty() const {
		return vec_->empty();
	}

	[[nodiscard]] size_t size() const {
		return vec_->size();
	}

};

}
```



### Queue.hpp

```c++
//
// Created by lsx31 on 24-12-9.
//

#pragma once

#include <stdexcept>

namespace ds {

template <typename ElemType>
struct Node {
	ElemType data_;
	Node* next_{nullptr};

	explicit Node(const ElemType& val) : data_{val}, next_{nullptr} {
	}

	~Node() {
		next_ = nullptr;
	}

	Node(const Node& ano_node) : data_{ano_node.data_}, next_{nullptr} {
	}
};

template <typename ElemType>
struct Queue {
	Node<ElemType>* front_{nullptr};
	Node<ElemType>* rear_{nullptr};

	Queue() : front_{nullptr}, rear_{nullptr} {}

	~Queue() {
		clear();
	}

	Queue(const Queue& ano_queue) : front_{nullptr}, rear_{nullptr} {
		auto* current = ano_queue.front_;
		while (current != nullptr) {
			enqueue(current->data_);
			current = current->next_;
		}
	}

	Queue& operator=(const Queue& ano_queue) {
		if (this == &ano_queue)
			return *this;

		clear();

		auto* current = ano_queue.front_;
		while (current != nullptr) {
			enqueue(current->data_);
			current = current->next_;
		}

		return *this;
	}

	bool is_empty() {
		return front_ == nullptr;
	}

	void clear() {
		while (!is_empty()) {
			dequeue();
		}
	}

	void enqueue(const ElemType& val) {
		auto* new_node = new Node<ElemType>(val);
		if (rear_)
			rear_->next_ = new_node;
		rear_ = new_node;

		if (!front_)
			front_ = rear_;
	}

	ElemType dequeue() {
		if (is_empty())
			throw std::runtime_error("empty queue");

		auto* temp = front_;
		ElemType val = front_->data_;

		front_ = front_->next_;
		if (front_ == nullptr)
			rear_ = nullptr;

		delete temp;
		temp = nullptr;

		return val;
	}

	ElemType peek() {
		if (is_empty()) {
			throw std::runtime_error("empty queue");
		}
		return front_->data_;
	}

	size_t size() {
		int counter = 0;
		auto* current = front_;

		while (current != nullptr) {
			++counter;
			current = current->next_;
		}

		return counter;
	}
};

}

```



### BinaryTree.hpp

```c++
//
// Created by lsx31 on 24-12-9.
//

#pragma once

#include <iostream>
#include <stdexcept>

#include "../Queue/Queue.hpp"

namespace ds {

template <typename ElemType>
struct BinaryTreeNode {
	ElemType data_;
	BinaryTreeNode* left_;
	BinaryTreeNode* right_;

	explicit BinaryTreeNode(const ElemType& value) : data_{value}, left_{nullptr}, right_{nullptr} {}
};

template <typename ElemType>
struct BinaryTree {
private:
	BinaryTreeNode<ElemType>* root_;

	void destroy_tree(BinaryTreeNode<ElemType>* node) {
		if (node != nullptr) {
			destroy_tree(node->left_);
			destroy_tree(node->right_);
			delete node;
		}
	}

	void insert_util(BinaryTreeNode<ElemType>*& node, const ElemType& value) {
		if (node == nullptr) {
			node = new BinaryTreeNode<ElemType>(value);
		} else if (value < node->data_) {
			insert_util(node->left_, value);
		} else {
			insert_util(node->right_, value);
		}
	}

	static void visit(BinaryTreeNode<ElemType>* node) {
		std::cout << node->data_ << " ";
	}

	void pre_order_util(BinaryTreeNode<ElemType>* node) const {
		if (node != nullptr) {
			visit(node);
			pre_order_util(node->left_);
			pre_order_util(node->right_);
		}
	}
	void in_order_util(BinaryTreeNode<ElemType>* node) const {
		if (node != nullptr) {
			in_order_util(node->left_);
			visit(node);
			in_order_util(node->right_);
		}
	}
	void post_order_util(BinaryTreeNode<ElemType>* node) const {
		if (node != nullptr) {
			post_order_util(node->left_);
			post_order_util(node->right_);
			visit(node);
		}
	}

	bool search_util(const BinaryTreeNode<ElemType>* node, const ElemType& value) const {
		if (node == nullptr)
			return false;
		if (value == node->data_) {
			return true;
		} else if (value < node->data_) {
			return search_util(node->left_, value);
		} else {
			return search_util(node->right_, value);
		}
	}
	ElemType find_max_value_util(const BinaryTreeNode<ElemType>* node) const {
		if (node->right_ == nullptr)
			return node->data_;
		return find_max_value_util(node->right_);
	}
	ElemType find_min_value_util(const BinaryTreeNode<ElemType>* node) const {
		if (node->left_ == nullptr)
			return node->data_;
		return find_min_value_util(node->left_);
	}
	BinaryTreeNode<ElemType>* find_max_util(BinaryTreeNode<ElemType>* node) const {
		if (node->right_ == nullptr)
			return node;
		return find_max_util(node->right_);
	}
	BinaryTreeNode<ElemType>* find_min_util(BinaryTreeNode<ElemType>* node) const {
		if (node->left_ == nullptr)
			return node;
		return find_min_util(node->left_);
	}

	size_t calculate_height_util(BinaryTreeNode<ElemType>* node) const {
		if (node == nullptr) {
			return 0;
		} else {
			return std::max(calculate_height_util(node->left_), calculate_height_util(node->right_)) + 1;
		}
	}

	bool is_bst_util(BinaryTreeNode<ElemType>* node, const ElemType& min, const ElemType& max) const {
		if (node == nullptr)
			return true;

		if (node->data_ <= min || node->data_ >= max) {
			return false;
		}

		return is_bst_util(node->left_, min, node->data_) &&
			   is_bst_util(node->right_, node->data_, max);
	}

	BinaryTreeNode<ElemType>* erase_util(BinaryTreeNode<ElemType>* node, const ElemType& data) {
		if (node == nullptr) {
			return nullptr;
		}

		if (data < node->data_) {
			node->left_ = erase_util(node->left_, data);
		} else if (data > node->data_) {
			node->right_ = erase_util(node->right_, data);
		} else {
			if (node->left_ == nullptr) {
				BinaryTreeNode<ElemType>* temp = node->right_;
				delete node;
				return temp;
			} else if (node->right_ == nullptr) {
				BinaryTreeNode<ElemType>* temp = node->left_;
				delete node;
				return temp;
			}

			BinaryTreeNode<ElemType>* temp = find_min_util(node->right_);
			node->data_ = temp->data_;
			node->right_ = erase_util(node->right_, temp->data_);
		}
		return node;
	}

public:
	BinaryTree() : root_{nullptr} {}

	~BinaryTree() {
		destroy_tree(root_);
	}

	void insert(const ElemType& value) {
		insert_util(root_, value);
	}

	void pre_order() const {
		pre_order_util(root_);
		std::cout << std::endl;
	}

	void in_order() const {
		in_order_util(root_);
		std::cout << std::endl;
	}

	void post_order() const {
		post_order_util(root_);
		std::cout << std::endl;
	}

	void level_order() const {
		if (root_ == nullptr)
			return;

		ds::Queue<BinaryTreeNode<ElemType>*> q;
		q.enqueue(root_);

		while (!q.is_empty()) {
			BinaryTreeNode<ElemType>* current = q.peek();
			q.dequeue();

			std::cout << current->data_ << " ";

			if (current->left_ != nullptr) {
				q.enqueue(current->left_);
			}

			if (current->right_ != nullptr) {
				q.enqueue(current->right_);
			}
		}
		std::cout << std::endl;
	}

	bool search(const ElemType& value) const {
		return search_util(root_, value);
	}

	ElemType find_max_value() const {
		if (root_ == nullptr)
			throw std::runtime_error("can't find on empty tree.");

		return find_max_value_util(root_);
	}

	ElemType find_min_value() const {
		if (root_ == nullptr)
			throw std::runtime_error("can't find on empty tree.");

		return find_min_value_util(root_);
	}

	BinaryTreeNode<ElemType>* find_max() const {
		if (root_ == nullptr)
			return nullptr;

		return find_max_util(root_);
	}

	BinaryTreeNode<ElemType>* find_min() const {
		if (root_ == nullptr)
			return nullptr;

		return find_min_util(root_);
	}

	[[nodiscard]] size_t calculate_height() const {
		return calculate_height_util(root_);
	}

	[[nodiscard]] bool is_bst() const {
		return is_bst_util(root_, std::numeric_limits<ElemType>::min(), std::numeric_limits<ElemType>::max());
	}

	void erase(const ElemType& data) {
		root_ = erase_util(root_, data);
	}
};

}






















```



### Pair.hpp

```c++
//
// Created by lsx31 on 24-12-14.
//

#pragma once

namespace ds {

template <typename T1, typename T2>
struct  Pair {

	T1 first;
	T2 second;

	Pair() : first(), second() {}
	Pair (const T1& a, const T2& b) : first{a}, second{b} {}

	Pair& operator=(const Pair<T1, T2>& ano_pair) {
		if (this != &ano_pair) {
			first = ano_pair.first;
			second = ano_pair.second;
		}
		return *this;
	}

	bool operator==(const Pair& ano_pair) const {
		return first == ano_pair.first && second == ano_pair.second;
	}

	bool operator!=(const Pair& ano_pair) const {
		return !(*this == ano_pair);
	}
};

}

```



### HashTable.hpp

```c++
//
// Created by lsx31 on 24-12-12.
//

#pragma once

#include "../Pair/Pair.hpp"
#include "../LinkedList/LinkedList.hpp"
#include "../SeqTable/SeqTable.hpp"

namespace ds {

template <typename KeyType, typename ValueType>
class HashTable {
public:
	using value_type = ds::Pair<KeyType, ValueType>;
	using container_type = ds::LinkedList<value_type>;
	using table_type = ds::SeqTable<container_type>;

	explicit HashTable(size_t size = 10) : table_{size}, num_elements_{0} {}

	void insert(const KeyType& key, const ValueType& value) {
		auto index = hash_function(key);
		for (auto it = table_[index].begin(); it != table_[index].end(); ++it) {
			// 存在则更新
			if (it->first == key) {
				it->second = value;
				return;
			}
		}
		table_[index].push_back(value_type(key, value));
		++num_elements_;
	}

	bool find(const KeyType& key, ValueType& value) const {
		auto index = hash_function(key);
		for (auto it = table_[index].begin(); it != table_[index].end(); ++it) {
			if (it->first == key) {
				value = it->second;
				return true;
			}
		}
		return false;
	}

	bool remove(const KeyType& key) {
		auto index = hash_function(key);
		for (auto it = table_[index].begin(); it != table_[index].end(); ++it) {
			if (it->first == key) {
				table_[index].erase(it);
				--num_elements_;
				return true;
			}
		}
		return false;
	}

private:
	// hash function
	size_t hash_function(const KeyType& key) const {
		// using c++ 11 hash function
		std::hash<KeyType> hasher;
		return hasher(key) % table_.size();
	}

	table_type table_;
	size_t num_elements_;
};

}




```



### Graph.hpp

```c++
//
// Created by lsx31 on 24-12-10.
//

#pragma once

#include <ostream>
#include <vector>
#include <iostream>

struct Graph {
    int V;
    std::vector<std::vector<int>> adj_matrix;

    Graph(int vertices) {
        V = vertices;
        adj_matrix.resize(V, std::vector<int>(V, 0));
    }

    void add_edge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        } else {
            std::cout << "边顶点超出范围！" << std::endl;
        }
    }

    void remove_edge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj_matrix[u][v] = 0;
            adj_matrix[v][u] = 0;
        } else {
            std::cout << "边顶点超出范围!" << std::endl;
        }
    }

    bool has_edge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            return adj_matrix[u][v] == 1;
        } else {
            std::cout << "边顶点超出范围!" << std::endl;
            return false;
        }
    }

    std::vector<int> get_neighbors(int u) {
        std::vector<int> neighbors;
        if (u >= 0 && u < V) {
            for (int v = 0; v < V; ++v) {
                if (adj_matrix[u][v] == 1) {
                    neighbors.push_back(v);
                }
            }
        } else {
            std::cout << "顶点超出范围！" << std::endl;
        }
        return neighbors;
    }

    void print_graph() {
        std::cout << "用邻接矩阵表示的图：" << std::endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                std::cout << adj_matrix[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};
```





## 测试框架代码:

### SeqTableTest.cpp

```c++
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




```



### LinkedListTest.cpp

```c++
#include <gtest/gtest.h>
#include "LinkedList.hpp"

using namespace ds;

// 测试默认构造函数
TEST(LinkedListTest, DefaultConstructor) {
    LinkedList<int> list;
    EXPECT_TRUE(list.empty());
}

// 测试带参数的构造函数
TEST(LinkedListTest, ParameterizedConstructor) {
    LinkedList<int> list(42);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(*list.begin(), 42);
}

// 测试 push_front 方法
TEST(LinkedListTest, PushFront) {
    LinkedList<int> list;
    list.push_front(1);
    EXPECT_EQ(*list.begin(), 1);
    list.push_front(2);
    EXPECT_EQ(*list.begin(), 2);
    EXPECT_EQ(*(++list.begin()), 1);
}

// 测试 push_back 方法
TEST(LinkedListTest, PushBack) {
    LinkedList<int> list;
    list.push_back(1);
    EXPECT_EQ(*list.begin(), 1);
    list.push_back(2);
    EXPECT_EQ(*list.begin(), 1);
    EXPECT_EQ(*(++list.begin()), 2);
}

// 测试 insert 方法
TEST(LinkedListTest, Insert) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(3);
    auto it = list.insert(++list.begin(), 2);
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(*list.begin(), 1);
    EXPECT_EQ(*(++list.begin()), 2);
    EXPECT_EQ(*(++++list.begin()), 3);
}

// 测试 pop_front 方法
TEST(LinkedListTest, PopFront) {
    LinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.pop_front();
    EXPECT_EQ(*list.begin(), 1);
    list.pop_front();
    EXPECT_TRUE(list.empty());
}

// 测试 pop_back 方法
TEST(LinkedListTest, PopBack) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    EXPECT_EQ(*list.begin(), 1);
    list.pop_back();
    EXPECT_TRUE(list.empty());
}

// 测试 erase 方法
TEST(LinkedListTest, Erase) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.erase(++list.begin());
    EXPECT_EQ(*it, 3);
    EXPECT_EQ(*list.begin(), 1);
    EXPECT_EQ(*(++list.begin()), 3);
}

// 测试 find 方法
TEST(LinkedListTest, Find) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.find(2));
    EXPECT_FALSE(list.find(4));
}

// 测试 clear 方法
TEST(LinkedListTest, Clear) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    EXPECT_TRUE(list.empty());
}

// 测试 copy 构造函数
TEST(LinkedListTest, CopyConstructor) {
    LinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    LinkedList<int> list2 = list1;
    EXPECT_EQ(*list2.begin(), 1);
    EXPECT_EQ(*(++list2.begin()), 2);
    EXPECT_NE(&(*list1.begin()), &(*list2.begin()));
}

// 测试赋值操作符
TEST(LinkedListTest, AssignmentOperator) {
    LinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    LinkedList<int> list2;
    list2 = list1;
    EXPECT_EQ(*list2.begin(), 1);
    EXPECT_EQ(*(++list2.begin()), 2);
    EXPECT_NE(&(*list1.begin()), &(*list2.begin()));
}

```



### StackTest.cpp

```c++
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

```



### QueueTest.cpp

```c++
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
```



### BinaryTreeTest.cpp

```c++
#include <gtest/gtest.h>
#include <sstream>
#include "BinaryTree.hpp"

using namespace ds;

// Helper function to capture standard output
std::string captureStdout(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
}

TEST(BinaryTreeTest, Insert) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // The tree structure should be:
    //         10
    //        /  \
    //       5    15
    //      / \   / \
    //     3   7 12  18
}

TEST(BinaryTreeTest, PreOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::string output = captureStdout([&tree]() { tree.pre_order(); });
    EXPECT_EQ(output, "10 5 3 7 15 12 18 \n");
}

TEST(BinaryTreeTest, InOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::string output = captureStdout([&tree]() { tree.in_order(); });
    EXPECT_EQ(output, "3 5 7 10 12 15 18 \n");
}

TEST(BinaryTreeTest, PostOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::string output = captureStdout([&tree]() { tree.post_order(); });
    EXPECT_EQ(output, "3 7 5 12 18 15 10 \n");
}

TEST(BinaryTreeTest, LevelOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::string output = captureStdout([&tree]() { tree.level_order(); });
    EXPECT_EQ(output, "10 5 15 3 7 12 18 \n");
}

TEST(BinaryTreeTest, SearchTest) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.search(7));
    EXPECT_TRUE(tree.search(12));
    EXPECT_TRUE(tree.search(18));

    EXPECT_FALSE(tree.search(20));
    EXPECT_FALSE(tree.search(0));
    EXPECT_FALSE(tree.search(8));
}

TEST(BinaryTreeTest, FindMaxValueTest) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    EXPECT_EQ(tree.find_max_value(), 18);

    BinaryTree<int> emptyTree;
    EXPECT_THROW(emptyTree.find_max_value(), std::runtime_error);
}

TEST(BinaryTreeTest, FindMinValueTest) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    EXPECT_EQ(tree.find_min_value(), 3);

    BinaryTree<int> emptyTree;
    EXPECT_THROW(emptyTree.find_min_value(), std::runtime_error);
}

TEST(BinaryTreeTest, FindMin) {
    ds::BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    ds::BinaryTreeNode<int>* min_node = tree.find_min();
    ASSERT_NE(min_node, nullptr); // 确保返回的节点不为空
    EXPECT_EQ(min_node->data_, 3);
}

TEST(BinaryTreeTest, FindMax) {
    ds::BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    ds::BinaryTreeNode<int>* max_node = tree.find_max();
    ASSERT_NE(max_node, nullptr); // 确保返回的节点不为空
    EXPECT_EQ(max_node->data_, 18);
}

TEST(BinaryTreeTest, CalculateHeight) {
    BinaryTree<int> tree;

    // Empty tree height should be 0
    EXPECT_EQ(tree.calculate_height(), 0);

    // Single node tree height should be 1
    tree.insert(10);
    EXPECT_EQ(tree.calculate_height(), 1);

    // Tree with multiple levels
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // The tree structure should be:
    //         10
    //        /  \
    //       5    15
    //      / \   / \
    //     3   7 12  18
    // Height should be 3
    EXPECT_EQ(tree.calculate_height(), 3);

    // Adding more nodes to increase the height
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(11);
    tree.insert(13);
    tree.insert(17);
    tree.insert(19);

    // The tree structure should be:
    //               10
    //            /      \
    //           5        15
    //          / \      /  \
    //         3   7    12   18
    //        / \ / \  / \   / \
    //       2  4 6 8 11 13 17 19
    // Height should be 4
    EXPECT_EQ(tree.calculate_height(), 4);
}

TEST(BinaryTreeTest, EmptyTreeIsBST) {
    BinaryTree<int> tree;
    EXPECT_TRUE(tree.is_bst());
}

TEST(BinaryTreeTest, SingleNodeTreeIsBST) {
    BinaryTree<int> tree;
    tree.insert(10);
    EXPECT_TRUE(tree.is_bst());
}

TEST(BinaryTreeTest, ValidBST) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    EXPECT_TRUE(tree.is_bst());
}

TEST(BinaryTreeTest, InvalidBST) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // Manually modify the tree to make it invalid
    tree.find_max()->data_ = 5; // This makes the tree invalid

    EXPECT_FALSE(tree.is_bst());
}

TEST(BinaryTreeTest, LeftSkewedTreeIsBST) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(9);
    tree.insert(8);
    tree.insert(7);
    tree.insert(6);

    EXPECT_TRUE(tree.is_bst());
}

TEST(BinaryTreeTest, RightSkewedTreeIsBST) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);

    EXPECT_TRUE(tree.is_bst());
}

TEST(BinaryTreeTest, EraseLeafNode) {
    ds::BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    tree.erase(3); // 删除叶子节点
    std::string output = captureStdout([&tree]() { tree.in_order(); });
    EXPECT_EQ(output, "5 7 10 12 15 18 \n");
}

TEST(BinaryTreeTest, EraseNodeWithOneChild) {
    ds::BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    tree.erase(5); // 删除只有一个右子节点的节点
    std::string output = captureStdout([&tree]() { tree.in_order(); });
    EXPECT_EQ(output, "3 7 10 12 15 18 \n");

    tree.erase(18); // 删除只有一个左子节点的节点
    output = captureStdout([&tree]() { tree.in_order(); });
    EXPECT_EQ(output, "3 7 10 12 15 \n");
}

TEST(BinaryTreeTest, EraseNodeWithTwoChildren) {
    ds::BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    tree.erase(15); // 删除有两个子节点的节点
    std::string output = captureStdout([&tree]() { tree.in_order(); });
    EXPECT_EQ(output, "3 5 7 10 12 18 \n");

    tree.erase(10); // 删除根节点，它有两个子节点
    output = captureStdout([&tree]() { tree.in_order(); });
    EXPECT_EQ(output, "3 5 7 12 18 \n");
}

TEST(BinaryTreeTest, EraseNonExistentNode) {
    ds::BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    tree.erase(20); // 尝试删除不存在的节点
    std::string output = captureStdout([&tree]() { tree.in_order(); });
    EXPECT_EQ(output, "3 5 7 10 12 15 18 \n");
}









```



### PairTest.cpp

```c++
//
// Created by lsx31 on 24-12-14.
//
#include <gtest/gtest.h>
#include "Pair.hpp"

namespace ds {

TEST(PairTest, DefaultConstructor) {
    Pair<int, std::string> pair;
    EXPECT_EQ(pair.first, 0);
    EXPECT_EQ(pair.second, "");
}

TEST(PairTest, ParameterizedConstructor) {
    Pair<int, std::string> pair(42, "Hello");
    EXPECT_EQ(pair.first, 42);
    EXPECT_EQ(pair.second, "Hello");
}

TEST(PairTest, AssignmentOperator) {
    Pair<int, std::string> pair1(42, "Hello");
    Pair<int, std::string> pair2;
    pair2 = pair1;
    EXPECT_EQ(pair2.first, 42);
    EXPECT_EQ(pair2.second, "Hello");
}

TEST(PairTest, SelfAssignment) {
    Pair<int, std::string> pair(42, "Hello");
    pair = pair;
    EXPECT_EQ(pair.first, 42);
    EXPECT_EQ(pair.second, "Hello");
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

```



### HashTableTest.cpp

```c++
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






```



### GraphTest.cpp

```c++
#include <gtest/gtest.h>
#include "Graph.hpp"

// 测试Graph类的构造函数
TEST(GraphTest, Constructor) {
    Graph g(5);
    EXPECT_EQ(g.V, 5);
    for (const auto& row : g.adj_matrix) {
        for (int val : row) {
            EXPECT_EQ(val, 0);
        }
    }
}

// 测试添加边
TEST(GraphTest, AddEdge) {
    Graph g(5);
    g.add_edge(1, 2);
    EXPECT_EQ(g.adj_matrix[1][2], 1);
    EXPECT_EQ(g.adj_matrix[2][1], 1);
}

// 测试删除边
TEST(GraphTest, RemoveEdge) {
    Graph g(5);
    g.add_edge(1, 2);
    g.remove_edge(1, 2);
    EXPECT_EQ(g.adj_matrix[1][2], 0);
    EXPECT_EQ(g.adj_matrix[2][1], 0);
}

// 测试检查边的存在
TEST(GraphTest, HasEdge) {
    Graph g(5);
    g.add_edge(1, 2);
    EXPECT_TRUE(g.has_edge(1, 2));
    EXPECT_TRUE(g.has_edge(2, 1));
    EXPECT_FALSE(g.has_edge(1, 3));
}

// 测试获取邻居节点
TEST(GraphTest, GetNeighbors) {
    Graph g(5);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    std::vector<int> expected_neighbors = {2, 3};
    std::vector<int> actual_neighbors = g.get_neighbors(1);
    EXPECT_EQ(actual_neighbors, expected_neighbors);
}

```





























