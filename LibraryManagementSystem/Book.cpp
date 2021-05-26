#include "Book.h"
#include<string>
using namespace std;
Book::Book(string bookName, string bookISBN)
{
	this->bookName = bookName;
	this->bookISBN = bookISBN;
}

Book::Book()
{
	this->bookName = "book name";
	this->bookISBN = "bookISBN";
}

Book::Book(const Book& book)
{
	this->bookName = book.bookName;
	this->bookISBN = book.bookISBN;
}

string Book::getBookName()
{
	return bookName;
}

string Book::getBookISBN()
{
	return bookISBN;
}

void Book::setBookName(string name)
{
	this->bookName = name;
}

void Book::getBookISBN(string ISBN)
{
	this->bookISBN = ISBN;
}

void Book::operator=(const Book& book)
{
	this->bookName = book.bookName;
	this->bookISBN = book.bookISBN;
}



istream & operator>>(istream &in, Book &book)
{
	string temp;
	cout << "Enter book name(spaces are not allowed):..";

	in>>temp;
	book.bookName= temp;
	cout << "Enter book ISBN:  ";
	in >> temp;
	book.bookISBN = temp;
	return in;
}

ostream & operator<<(ostream &out, const Book &book)
{
	out << "book name : " << book.bookName
		<< "\nbookISBN : " << book.bookISBN << endl;
	return out;
}
