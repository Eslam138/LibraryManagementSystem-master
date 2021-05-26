#pragma once
#include "linkedList.h"
#include<string>
#include<iostream>
class LibrarySystem
{
	string name;
	linkedList books;
public:
	LibrarySystem();
	LibrarySystem(string name);
	void system();
};

