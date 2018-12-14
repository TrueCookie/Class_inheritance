#include <iostream>
#include <conio.h>
#include <Windows.h>
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

