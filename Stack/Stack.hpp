#pragma once

#include "../SeqTable/SeqTable.hpp"

namespace ds {

template<typename ElemType>
struct stack {
	SeqTable<ElemType> array_;
	size_t top_{0};


};




}