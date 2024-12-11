//
// Created by lsx31 on 24-12-9.
//

#pragma once

#include <iostream>

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

	void insert_util(BinaryTreeNode<ElemType>*& node, const ElemType& value) {
		if (node == nullptr) {
			node = new BinaryTreeNode<ElemType>(value);
		} else if (value < node->data_) {
			insert_util(node->left_, value);
		} else {
			insert_util(node->right_, value);
		}
	}

	void visit(BinaryTreeNode<ElemType>* node) const {
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

	void destroy_tree(BinaryTreeNode<ElemType>* node) {
		if (node != nullptr) {
			destroy_tree(node->left_);
			destroy_tree(node->right_);
			delete node;
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
	ElemType find_max_util(const BinaryTreeNode<ElemType>* node) const {
		if (node->right_ == nullptr)
			return node->data_;
		return find_max_util(node->right_);
	}
	ElemType find_min_util(const BinaryTreeNode<ElemType>* node) const {
		if (node->left_ == nullptr)
			return node->data_;
		return find_min_util(node->left_);
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

	ElemType find_max() const {
		if (root_ == nullptr)
			throw std::runtime_error("can't find on empty tree.");

		return find_max_util(root_);
	}

	ElemType find_min() const {
		if (root_ == nullptr)
			throw std::runtime_error("can't find on empty tree.");

		return find_min_util(root_);
	}
};





}





















