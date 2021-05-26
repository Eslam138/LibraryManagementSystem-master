#include "LibrarySystem.h"
LibrarySystem::LibrarySystem()
{
	name = "Library";
}

LibrarySystem::LibrarySystem(string name)
{
	this->name = name;
}

void LibrarySystem::system()
{
	cout << "      - - - - - - -Hello in- - - - - - - " << name << "library\n";
BackHome:
	cout << "Menu\n"
		<< "[1]add book\n"
		<< "[2]borrow book\n"
		<< "[3]add return book\n"
		<< "[4]Library inventory\n"
		<< "[5]Exit\n";
	char option;
	cin >> option;
	switch (option)
	{
	case'1':
		books.insert();
		goto BackHome;
	case'2':
		books.borrow();
		goto BackHome;
	case'3':
		books.AddingBookReturn();
		goto BackHome;
	case'4':
		books.LibraryInventory();
		goto BackHome;
	case'5':
		break;
	default:
		cout << "you enterd wrong option\n";
		cin.ignore(123, '\n');
		goto BackHome;
		break;
	}
}