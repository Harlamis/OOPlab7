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
	void addB( const T& value) {
		unique_ptr<Snode<T>> newNode = make_unique<Snode<T>>(value);
		newNode->nextNode = move(head);
		head = move(newNode);
		size++;
	};
	void addE(const T& value) {
		unique_ptr<Snode<T>> newNode = make_unique<Snode<T>>(value);
		Snode* current = head.get();
		if (!current) {
			head = std::move(newNode);
			size++;
			return;
		}
		while (current->nextNode) {
			current = current->nextNode.get();
		}
		current->nextNode = move(newNode);
		size++;
	};
	void addI(int index, const T& value) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
			if (index == 0) {
				addB(value);
				return;
			}
			else if (index == size) {
				addE(value)
				return;
			}
			else {
				unique_ptr<Snode<T>> newNode = make_unique<Snode<T>>(value);
				Snode* current = head.get();
				for (int i; i < index - 1; i++) {
					current = current->nextNode.get();
				}
				newNode->nextNode = move(current->nextNode);
				current->nextNode = move(newNode);
				size++;
			}

		
	}
	T operator[](int index) const {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		Snode* current = head.get();
		for (int i = 0; i < index; i++) {
			current = current->nextNode.get();
		}
		return current->data;
	}
	void rmB{
		if (!head) {
		throw std::out_of_range("List is empty!");
	}
		head = std::move(head->nextNode);
	--size;
	}
	void rmE{
		 if (!head) {
		throw std::out_of_range("List is empty!");
	}
	if (size == 1) {
		head.reset();
		--size;
		return;
	}
	Snode* current = head.get();
	while (current->nextNode->nextNode) {
		current = current->nextNode.get();
	}
	current->nextNode.reset();
	--size;
	}	
	void rmI{
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		if (index == 0) {
			rmB();
			return;
		}
		else if (index == size) {
			rmE()
			return;
		}
		Snode* current = head.get();
		for (int i = 0; i < index - 1; i++) {
			current = current->nextNode.get();
		}
		current->nextNode = move(current->nextNode->nextNode);
		--size;

	}
	bool search(const T& value) {
		Snode* current = head.get();
		while (current) {
			if (current->data == value) {
				return true;
			}
			current = current->nextNode.get();
		}
		return false;
	}
	int getSize() {
		return size;
	}
	friend ostream& operator<<(ostream& os, SL_list& obj) {
		Snode* current = obj.head.get();
		os << "List data: " << endl;
		while (current != nullptr) {
			os << current->data << " ";
			current = current->nextNode.get();
		}
		os << endl;
		return os;
	}

};
