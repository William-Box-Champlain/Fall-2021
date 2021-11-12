#pragma once
#include "Book.h"
class LListNode
{
public:
	LListNode();
	LListNode(Book* book);
	~LListNode();
	void DisplayNodeData();
	Book* nBook;
	LListNode* next;
};