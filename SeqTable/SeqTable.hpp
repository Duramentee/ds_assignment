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