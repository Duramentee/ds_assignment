#pragma once

#include "../SeqTable/SeqTable.hpp"

namespace ds {

template <typename ElemType>
struct Stack {
	SeqTable<ElemType>* vec_;

	explicit Stack(size_t size) {
		vec_ = new SeqTable<ElemType>();
		vec_->size_ = 0;
		vec_->resize(size);
	}

	~Stack() {
		delete vec_;
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