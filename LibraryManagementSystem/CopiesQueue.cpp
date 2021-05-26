#include "CopiesQueue.h"
#include<string>
#include<iostream>
using namespace std;

CopiesQueue::CopiesQueue()
{
	tail = head = NULL;
	num = copiesNUM = 0;
}

void CopiesQueue::inQueue(int day, int month, int year)
{
	CopiesQueue::Node* newptr = new CopiesQueue::Node;
	newptr->date.day=day;
	newptr->date.month = month;
	newptr->date.year = year;
	newptr->flag = false;
	newptr->borrower = "NULL";
	newptr->returnDayes = 15;
	copiesNUM++;
	newptr->next = NULL;
	if (isEmpyt())
		tail = head = newptr;
	else {
		tail->next = newptr;
		tail = newptr;
	}
}

void CopiesQueue::deQueue(string name)
{
	if (isEmpyt())
		cout << "no copies in the libeary\n";
	else
	{
		if (num == copiesNUM)
			cout << "all copies is borrwed\n";
		else
		{
			CopiesQueue::Node *current = head;
			int i = 0;
			while (i<copiesNUM) {
				if (current->flag==false)
				{
					current->borrower = name;
					cout << "for borrower :" << current->borrower << endl;
					bool date= false,day=false,year= false,month = false;
					cout << "Enter borrow date\n";
					while (!date)
					{
						if (!day)
						{
							cout << "Enter borrow day :.. ";
							cin >> current->borrowDate.day;
							if (current->borrowDate.day > 0 && current->borrowDate.day < 32)
								day = true;
						}
						if (!month)
						{
							cout << "Enter borrow month :.. ";
							cin >> current->borrowDate.month;
							if (current->date.month > 0 && current->borrowDate.month < 13)
								month = true;
						}
						if (!year)
						{
							cout << "Enter borrow year :.. ";
							cin >> current->borrowDate.year;
							if (current->borrowDate.year > 2000 && current->borrowDate.day <3000)
								year = true;
						}
						if (year == true && month == true && day == true)
							date = year;	  
					}					cout << "Enter return dayes :..";
					cin >> current->returnDayes;
					current->flag = true;
					num++;
					break;
				}
				else
				{
					i++;
					if (current->next!=NULL)
					{
						current = current->next;
					}
				}
			}
		}
	}
}

void CopiesQueue::search(string borrwer)
{
	if (isEmpyt())
		cout << "no copies\n";
	else
	{
		CopiesQueue::Node *current = head;
		while (true)
		{
			if (current->borrower==borrwer)
			{
				current->borrowDate.day = 0;
				current->borrowDate.month = 0;
				current->borrowDate.year = 0;
				current->flag = false;
				current->borrower = "NULL";
				num--;//to delte borrowed copiy
				break;
			}
			else
			{
				if (current==tail)
				{
					cout << "this borrower "<<borrwer<<" doesn't exist\n";
					break;
				}
				else
				{
					current = current->next;
				}
			}
		}
	}
}

CopiesQueue::~CopiesQueue()
{
	while (head!=NULL)
	{
		CopiesQueue::Node* temp = head;
		head = head->next;
		delete temp;
	}
}

bool CopiesQueue::isEmpyt()
{
	return head == NULL;
}

void CopiesQueue::inventory()
{
	CopiesQueue::Node* temp = head;
	int i = 1;
	if (temp)
	{
		cout << "\n-------------------------------\n";

		cout << "copies number: " << copiesNUM
			<< "\n borrowed copies: " << num << endl;
		cout<< "-------------------------------\n";
	}
	while (temp != NULL)
	{
		cout << "copy Number" << i
			<< "\n copy Date " << temp->date.year << "/" << temp->date.month<<"/"<< temp->date.day << endl;
		if (temp->flag)
		{
			cout << "status: borrowed\n borrwer name : " << temp->borrower << endl;
			cout << "borrow Date " << temp->borrowDate.year << "/" << temp->borrowDate.month << "/" 
				 << temp->borrowDate.day << endl;
		}
		else
			cout << "status:available\n";
		cout << "------------------\n";
		i++;
		temp = temp->next;
	}
	cout << "-------------------------------\n"
	     << "-------------------------------\n";
}
