#include "LList.h"
#include <iostream>
//constructors
LList::LList() {
	head = NULL;
}
LList::LList(Book* book) {
	LListNode* firstNode = new LListNode(book);
	head = firstNode;
}
LList::~LList() {
	delete head;
}
//adds a node to the end of the linked list, either without a book, with a book that was already constructed, or constructing a book at function call.
void LList::addNode() {
	LListNode* newNode = new LListNode();
	newNode->next = NULL;
	addNodeToEnd(newNode);
}
void LList::addNode(Book* book) {
	LListNode* newNode = new LListNode(book);
	newNode->next = NULL;
	addNodeToEnd(newNode);
}
void LList::addNode(std::string title, std::string author, std::string publisher) {
	Book* newBook = new Book(title, author, publisher);
	LListNode* newNode = new LListNode(newBook);
	addNodeToEnd(newNode);
}
void LList::addNode(LListNode* node) {
	addNodeToEnd(node);
}

void LList::removeNode() {
	int x;
	std::cout << "Which node would you like to remove? (count starts at 0) " << std::endl;
	std::cin >> x;
	removeNodeByInt(x);
}

void LList::removeFinalNode() {
	int x = countNodes();
	x--;
	removeNodeByInt(x);
}

//display info in nodes
void LList::displayNode() {
	LListNode* current;
	LListNode* next;
	if (this->head == NULL) return;
	current = head;
	next = head->next;
	while (current != NULL) {
		std::cout << current->nBook->getInfo() << std::endl;
		current = next;
		if (next == NULL) {
			break;
		}
		next = current->next;
	}
	return;
}
void LList::displayNode(int i) {

}
//count nodes in Linked List
int LList::countNodes() {
	LListNode* current;
	LListNode* next;
	int x{ 0 };
	if (this->head == NULL) return 0;
	current = head;
	next = head->next;
	while (next != NULL) {
		x++;
		current = next;
		next = current->next;
	}
	x++;
	return x;
}
int LList::countNodes(LListNode* node) {
	if (node->next == NULL) return 0;
	else {
		LListNode* temp = node->next;
		return 1 + countNodes(temp);
	}
}
void LList::addNodeToEnd(LListNode* newNode) {
	if (head == NULL) {
		head = newNode;
	}
	else {
		LListNode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
void LList::removeNodeByInt(int i) {
	int x{ 0 };
	int nodeBeforeTarget = i-1;
	if (nodeBeforeTarget < 0) nodeBeforeTarget = 0;
	LListNode* current;
	LListNode* target;
	LListNode* next;
	current = head;
	if (head == NULL) return;
	next = head->next;
	if (i == 0) {
		target = current;
		next = target->next;
		delete target;
		return;
	}
	while (x != i) {
		if (x == nodeBeforeTarget) {
			target = next;
			next = target->next;
			delete target;
			current->next = next;
			break;
		}
		x++;
		current = next;
		next = current->next;
	}	
	
}
void LList::removeNodeByTitle(std::string book) {

}
void LList::removeNode(LListNode* nodeBeforeTarget) {

}