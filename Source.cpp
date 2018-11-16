#include <iostream>
#include <conio.h>

struct data{
	data() {
		prev = nullptr;
		next = nullptr;
	}
	int value;
	data* prev;
	data* next;
};

class collection{
protected:
	collection() {}
	virtual ~collection() {}

	virtual bool is_empty() = 0;
	//virtual size_t size() = 0;
	//virtual void reverse() = 0;
};

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
	//int* remove();
};

int main() {
	linked_list list;

	for (int i = 0; i < 5; ++i) {
		list.push_front(i);
	}
	list.read();
	list.reverse();
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