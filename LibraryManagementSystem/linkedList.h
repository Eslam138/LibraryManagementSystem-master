#pragma once
#include "CopiesQueue.h"
#include<string>
#include<iostream>
#include"Book.h"
using namespace std;
class linkedList
{
	struct Node
	{
		Book book;
		int copiesNumber;
		CopiesQueue copies;
		Node* next;
	};
	Node* head, * tail;
public:
	linkedList();
	~linkedList();
	void insert();
	bool isEmpty();
	Node* searchByName();// brrow books by name
	Node* searchByISBN();
	void borrow();
	void AddingBookReturn();
	void LibraryInventory();
};