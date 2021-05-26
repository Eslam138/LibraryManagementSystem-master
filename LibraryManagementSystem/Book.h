#pragma once
#include<iostream>
using namespace std;
class Book
{
	string bookName;
	string bookISBN;
public:
	Book(string bookName,string bookISBN);
	Book();
	Book(const Book &book);
	friend istream &operator>>(istream &in, Book &book);
	friend ostream &operator<<(ostream &out, const Book &book);
	string getBookName();
	string getBookISBN();
	void setBookName(string name);
	void getBookISBN(string ISBN);
	void operator = (const Book &book);
};

