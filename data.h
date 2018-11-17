#pragma once
struct data {
	data() {
		prev = nullptr;
		next = nullptr;
	}
	int value;
	data* prev;
	data* next;
};