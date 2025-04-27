#pragma once
#include <memory>
namespace sNode {
	template <typename T>
	struct Snode {
		T data;
		std::unique_ptr<Snode<T>> nextNode;
		Snode(const T& value) : data{ value }, nextNode{ nullptr } {};
	};
}

namespace dNode {
	template<typename T> 
	struct Dnode {
		T data;
		std::shared_ptr<Dnode<T>> nextNode;
		std::shared_ptr<Dnode<T>> previousNode;
		Dnode(const T& value) : data{ value }, nextNode{ nullptr }, previousNode{ nullptr } {};
	};
}