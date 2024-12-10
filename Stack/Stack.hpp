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