#pragma once
#include <ostream>
namespace dNode {
	template<typename T>
	struct Dnode {
		T data;
		std::shared_ptr<Dnode<T>> nextNode;
		std::shared_ptr<Dnode<T>> previousNode;
		Dnode(T& value) : data{ value }, nextNode{ nullptr }, previousNode{ nullptr } {};
	};
}

using namespace std;
using namespace dNode;
template<typename T>
class DL_list {
private:
	shared_ptr<Dnode<T>> head;
	shared_ptr<Dnode<T>> tail;
	int size;
public:
	DL_lis() : head{ nullptr }, tail{ nullptr }, size{ 0 } {};
	DL_list(T& value) : head{ make_shared<Dnode<T>>(value) }, tail{ head }, size{ 1 } {};
	void addB(T& value) {
		shared_ptr<Dnode<T>> newNode = make_shared<Dnode<T>>(value);
		if (!head) {
			head = tail = newNode;
		}
		else {
			newNode->nextNode = head;
			head->previousNode = newNode;
			head = newNode;
		}
		++size
	};
	void addE(T& value) {
		shared_ptr<Dnode<T>> newNode = make_shared<Dnode<T>>(value);
		if (!tail) {
			head = tail = newNode;
		}
		else {
			tail->nextNode = newNode;
			newNode->previousNode = tail;
			tail = newNode;
		}
		++size;
	};
	void addI(int index, T value) {
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
			shared_ptr<Dnode<T>> newNode = make_shared<Dnode<T>>(value);
			shared_ptr<Dnode<T>> current = head;
			for (int i; i < index - 1; i++) {
				current = current->nextNode;
			}
			newNode->nextNode = current->nextNode;
			newNode->previousNode = current;
			current->nextNode->previousNode = newNode;
			current->nextNode = newNode;
			++size;
		}


	}
	T operator[](int index) const {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		shared_ptr<Dnode<T>> current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->nextNode;
		}
		return current->data;
	}
	void rmB{
		if (!head) {
		return;
	}
	if (head == tail) {
		head = tail = nullptr;
	}
	 else {
       head = head->nextNode;
       head->previousNode.reset();
}
	--size;
	}
	void rmE{
		if (!tail) {
		return;
	}
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		tail = tail->previous.lock();
		tail->next = nullptr;
	}
	--size;
	}
	void rmI{
		if (index == 0) {
		head = head->nextNode;
		if (head) {
			head->previousNode.reset();
		}
		else {
			tail.reset();
		}
	}
		else if (index == size - 1) {
			tail = tail->previousNode.lock();
			tail->nextNode.reset();
		}
		else {
		shared_ptr<Dnode<T>> current = head;
	 for (int i = 0; i < index; i++) {
	 current = current->nextNext;
	}
	 current->previousNode.lock()->nextNode = current->nextNode;
	 current->nextNode->previousNode = current->previousNode;
	}
	--size;
	}
	bool search(int value) const {
		shared_ptr<Dnode<T>> current = head;
		while (current) {
			if (current->data == value) {
				return true;
			}
			current = current->nextNode;
		}
		return false;
	}
	int getSize() {
		return size;
	}
	friend ostream& operator<<(ostream& os, DL_list& obj) {
		os << "List data: " << endl;
		shared_ptr<Dnode<T>>? current = obj.head;
		while (current) {
			os << current->data << " ";
			current = current->nextNode;
		}
		os << endl;
		return os;
	}
};
