//
// Created by lsx31 on 24-12-14.
//

#pragma once

namespace ds {

template <typename T1, typename T2>
struct  Pair {
	T1 first_;
	T2 second_;

	Pair() : first_(), second_() {}
	Pair (const T1& a, const T2& b) : first_{a}, second_{b} {}

	Pair& operator=(const Pair<T1, T2>& ano_pair) {
		if (this != &ano_pair) {
			first_ = ano_pair.first_;
			second_ = ano_pair.second_;
		}
		return *this;
	}

	bool operator==(const Pair& ano_pair) const {
		return first_ == ano_pair.first_ && second_ == ano_pair.second_;
	}

	bool operator!=(const Pair& ano_pair) const {
		return !(*this == ano_pair);
	}
};

}
