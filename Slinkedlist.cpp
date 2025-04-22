#pragma once
#include "Nodes.h"
#include <memory>
using namespace std;
using namespace sNode;

template<typename T>
class SL_list {
private:
	unique_ptr<Snode<T>> head;
	int size;
public:
	SL_list() : head{ nullptr }, size{ 0 } {};
	SL_list(T& value) : head{ make_unique<Snode<T>>(value) }, size{ 1 } {};
	void addB(T& value);
	void addE(T& value);


		
 };