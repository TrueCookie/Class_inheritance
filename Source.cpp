#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "data.h"
#include "linked_list.h"

int main() {
	linked_list list;

	for (int i = 0; i < 5; ++i) {
		list.push_front(i);
	}
	list.read();
	list.reverse();
	list.read();
	list.remove(2);
	list.read();

	_getch();
	return 0;
} 

void linked_list::push_back(int input) {
	data* nData = new data;
	nData->value = input;
	if (this->is_empty()) {
		head = nData;
		tail = new data;
	}else{
		tail->prev->next = nData;
	}
	tail->prev = nData;
	nData->next = tail;
}

void linked_list::push_front(int input) {
	data* nData = new data;
	nData->value = input;
	if (this->is_empty()) {
		tail = new data;
		tail->prev = nData;
		nData->next = tail;
	}else{
		head->prev = nData;
		nData->next = head;
	}
	head = nData;
}

void linked_list::read() {
	data* tmp = head;
	while (tmp != tail){
		std::cout << tmp->value << "; ";
		tmp = tmp->next;
	}std::cout << std::endl;
}

void linked_list::reverse() {
	data* move = head;
	data* tmp = nullptr;
	while (move != tail) {
		tmp = move->next;
		move->next = move->prev;
		move->prev = tmp;

		move = move->prev;
	}
	data* tmp_end = head;
	head = tail->prev;
	head->prev = nullptr;
	tail->next = nullptr;
	tmp_end->next = tail;
}

bool linked_list::is_empty() {
	return head == tail;
}

size_t linked_list::size() {
	size_t count = 0;
	data* tmp = head;
	while (tmp != tail) {
		count++;
		tmp = tmp->next;
	}
	return count;
}

int linked_list::remove(int val) {
	data* p_val = find(val);
	if (p_val != tail) {
		p_val->prev->next = p_val->next;
		p_val->next->prev = p_val->prev;
		//delete p_val;
	}else {
		std::cout << "Value has not been found" << std::endl;
	}return p_val->value;
}

data* linked_list::find(int val) {
	data* tmp = head;
	while (tmp != tail) {
		if (tmp->value == val) {
			break;
		}else {
			tmp = tmp->next;
		}
	}return tmp;
}

