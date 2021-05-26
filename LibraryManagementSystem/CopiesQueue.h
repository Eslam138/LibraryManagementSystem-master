#pragma once
#include<iostream>
using namespace std;
struct Date
{
	int day;
	int month;
	int year;
};

class CopiesQueue
{
	struct Node
	{
		Date date;
		bool flag;
		string borrower;
		Date borrowDate;		int returnDayes=15;		Node* next;
	};
	Node* head, *tail;
	int copiesNUM;
	int num; // to count the borrowerd books
public:
	CopiesQueue();
	void inQueue(int day, int month, int year);//to add copies without borrowing
	void deQueue(string name);//to borrow the first book that is still avali
	void search(string borrwer);//to adding book return searched by name 
	~CopiesQueue();
	bool isEmpyt();
	void inventory();
};

