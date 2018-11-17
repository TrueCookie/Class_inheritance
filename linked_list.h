#pragma once
#include "collection.h"
#include "data.h"

class linked_list : public collection {
private:
	data* head;
	data* tail;
public:
	linked_list() {
		head = nullptr;
		tail = head;
	}
	bool is_empty();
	void reverse();
	size_t size();

	void read();
	void push_back(int);
	void push_front(int);
	data* find(int);
	int remove(int);
};