#include "Book.h"
#include "LList.h"
#include "LListNode.h"
#include <iostream>

int main() {
	int x{ 1 };
	LList linkedList;
	while (x != 0) {
		std::cout << "What would you like to do?" << std::endl
			<< "1: Add a book to the end of the list" << std::endl
			<< "2: Remove a book from the list" << std::endl
			<< "3: Remove node at end of list" << std::endl
			<< "4: Display info from all books" << std::endl
			<< "5: Display info from a specific book" << std::endl
			<< "6: Count Nodes in list" << std::endl
			<< "0: End Program" << std::endl;
		std::cout << "Input: ";
		std::cin >> x;
		switch (x)
		{
		case 1: linkedList.addNode();
			break;
		case 2: linkedList.removeNode();
			break;
		case 3: linkedList.removeFinalNode();
			break;
		case 4: linkedList.displayNode();
			break;
		case 5: break;
		case 6: std::cout << "Number of Nodes: " << linkedList.countNodes() << std::endl;
		case 0: break;
		default:
			break;
		}
	}
	return 0;
}