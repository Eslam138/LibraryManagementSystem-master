#include "linkedList.h"

linkedList::linkedList()
{
	head = tail = NULL;
}

linkedList::~linkedList()
{
	linkedList::Node *current;
	while (head!=NULL)
	{
		current = head;
		head = head->next;
		delete current;
	}
}

void linkedList::insert()
{
	Book book;
	cout << "Enter book data................\n";
	cin >> book;
	linkedList::Node *newptr = new Node;
	newptr->book = book;
	cout << "how many copies :..";
	cin >> newptr->copiesNumber;
	int counter = 1;//to tell user the number of copy he will add
	for (size_t i = 0; i < newptr->copiesNumber; i++)
	{
		cout << "copy Number: " << counter << endl;
		counter++;
		int dayDate, monthDate, yearDate;
		bool date = false, day = false, year = false, month = false;
		cout << "Enter date\n";
		while (!date)
		{
			if (!day)
			{
				cout << "Enter day :.. ";
				cin >> dayDate;
				if (dayDate > 0 &&dayDate < 32)
					day = true;
			}
			if (!month)
			{
				cout << "Enter month :.. ";
				cin >> monthDate;
				if (monthDate > 0 && monthDate < 13)
					month = true;
			}
			if (!year)
			{
				cout << "Enter borrow year :.. ";
				cin >>yearDate;
				if (yearDate > 2000 && yearDate < 3000)
					year = true;
			}
			if (year == true && month == true && day == true)
				date = year;
		}
		newptr->copies.inQueue(dayDate, monthDate, yearDate);
	}
	newptr->next = NULL;
	if (isEmpty())
	{
		head = tail = newptr;
	}
	else
	{
		tail->next = newptr;
		tail = newptr;
	}
}

bool linkedList::isEmpty()
{
	return head==NULL;
}

linkedList::Node* linkedList::searchByName()
{
	if (isEmpty())
		cout << "no books to serch\n";
	else
	{
		cout << "book name\n";
		string bookName;
		cin >> bookName;
		linkedList::Node *current = head;
		while (current!=NULL)
		{
			if (bookName==current->book.getBookName())
			{
				return current;
			}
			else
			{
				current = current->next;
			}
		}
	}
	cout << "There is no such book\n";
	return NULL;
}

linkedList::Node* linkedList::searchByISBN()
{
	if (isEmpty())
		cout << "no books to serch\n";
	else
	{
		cout << "book ISBN\n";
		string bookISBN;
		cin>>bookISBN;
		linkedList::Node* current = head;
		while (current != NULL)
		{
			if (current->book.getBookISBN() == bookISBN)
			{
				return current;
			}
			else
			{
				current = current->next;
			}
		}
	}
	cout << "There is no such book\n";
	return NULL;
}

void linkedList::borrow()
{
	if (isEmpty())
	{
		cout << "ther is no books in library\n";
		return;
	}
	linkedList::Node* current = new Node;//to know the address of book
	char option;//to know wich type user will use to search
	error:
	cout << "Any way you want to search\n"
		<< "[1] By Book Name\n"
		<< "[2]BY Book ISBN\nyour choice :...";
	cin >> option;
	switch (option)
	{
	case'1':
		current = searchByName();
		break;
	case'2':
		current = searchByISBN();
		break;
	default:
		cout << "invalid option\n";
		cin.ignore(123, '\n');
		goto error;
		break;
	}
	if (current!=NULL)
	{
		string name;
		cout << "Enter borrower Name(space not allowed):..";
		cin >> name;
		current->copies.deQueue(name);
	}
}

void linkedList::AddingBookReturn()
{
	if (isEmpty())
	{
		cout << "ther is no books in library\n";
		return;
	}
	linkedList::Node* current = new Node;//to know the address of book
	char option;//to know wich type user will use to search
error:
	cout << "Any way you want to search\n"
		<< "[1] By Book Name\n"
		<< "[2]BY Book ISBN\nyour choice :...";
	cin >> option;
	switch (option)
	{
	case'1':
		current = searchByName();
		break;
	case'2':
		current = searchByISBN();
		break;
	default:
		cout << "invalid option\n";
		cin.ignore(123, '\n');
		goto error;
		break;
	}
	if (current != NULL)
	{
		string name;
		cout << "Enter borrower Name(nospaces):..";
		cin >> name;
		current->copies.search(name);
	}
}

void linkedList::LibraryInventory()
{
	linkedList::Node* current = head;//to know the address of book
	if (current == NULL)
		cout << "ther is no books in library\n";
	while (current!=NULL)
	{

		cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n" 
			<< current->book;
		if(current->copiesNumber==0)
			cout <<"copies Number: "<< current->copiesNumber << endl;
		current->copies.inventory();
		current = current->next;
		cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	}
}
