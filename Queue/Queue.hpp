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
