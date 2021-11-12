#pragma once
#include "Book.h"
#include "LListNode.h"
#include <string>
class LList
{
public:
	//constructors and deconstructor
	LList();
	LList(Book* book);
	~LList();

	//adds a node to the end of the linked list, either without a book, with a book that was already constructed, or constructing a book at function call.
	void addNode();
	void addNode(Book* book);
	void addNode(std::string title, std::string author, std::string publisher);
	void addNode(LListNode* node);

	//remove node or list
	void removeList();
	void removeNode();
	void removeFinalNode();

	//display info in nodes
	void displayNode();
	void displayNode(int i);

	//count nodes in Linked List
	int countNodes();
	int countNodes(LListNode* node);

private:
	LListNode* head;
	void addNodeToEnd(LListNode* newNode);

	//does what the can says
	void removeNodeByInt(int x);
	void removeNodeByTitle(std::string book);
	void removeNode(LListNode *nodeBeforeTarget);
};