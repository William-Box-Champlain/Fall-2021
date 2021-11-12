#include "LListNode.h"
#include <iostream>
#include <string>
LListNode::LListNode() {
	next = NULL;
	nBook = new Book();
	std::string temp;
	std::cout << "Title: ";
	std::cin >> temp;
	nBook->addTitle(temp);
	std::cout << "Author: ";
	std::cin >> temp;
	nBook->addAuthor(temp);
	std::cout << "Publisher: ";
	std::cin >> temp;
	nBook->addPublisher(temp);
}
LListNode::LListNode(Book* book) {
	this->nBook = book;
	this->next = NULL;
}
LListNode::~LListNode() {
	delete nBook;
	delete next;
}
void LListNode::DisplayNodeData() {
	std::cout << nBook->getInfo();
}