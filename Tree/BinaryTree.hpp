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





















