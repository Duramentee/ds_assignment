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
		capacity_{2 * size},
		array_{size ? new ElemType[2 * size] : nullptr} {
			if (size == 0)
				throw std::invalid_argument("size of SeqTable can't be zero");
	}

	~SeqTable() {
		delete[] array_;
	}

	SeqTable(const SeqTable& ano_table) :
		size_{ano_table.size_},
		capacity_{ano_table.capacity_},
		array_{ano_table.size_ ? new ElemType[2 * ano_table.size_] : nullptr} {
			if (ano_table.size_ == 0)
				throw std::invalid_argument("size of SeqTable can't be zero");

			std::copy(ano_table.array_, ano_table.array_ + size_)
	}

	[[nodiscard]] size_t          size()   const { return size_; }

	[[nodiscard]] ElemType*       begin()        { return array_; }
	[[nodiscard]] const ElemType* cbegin() const { return array_; }

	[[nodiscard]] ElemType*       end()          { return array_ + size_; }
	[[nodiscard]] const ElemType* cend()   const { return array_ + size_; }
};



}