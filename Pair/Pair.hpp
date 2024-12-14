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
