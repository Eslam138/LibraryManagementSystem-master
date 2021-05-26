#include <iostream>
#include<cassert>
using namespace std;
template<class T>
struct node
{
    T item;
    node* next;
};
template<class T>
class LinkedList
{
    node<T>* head, * tail;
public:
    LinkedList() {
        head = tail = NULL;
    }
    void insert(T item) {
        node<T>* newptr = new node<T>;
        newptr->item = item;
        newptr->next = NULL;
        if (head==NULL)
        {
            head = tail = newptr;
        }
        else
        {
            tail->next = newptr;
            tail = newptr;
        }
    }
    void insertPos(int data, int position) {
        if (head==NULL&&position!=0)
        {
            assert(head);
        }
        else if(position == 0)
        {
            insert(data);
        }
        else
        {
            int counter=0;
            node<T>*current = head;
            node<T>* newptr;
            while (current!=NULL)
            {
                if (counter==position-1)
                {
                    newptr = new node<T>;
                    newptr->item = data;

                    newptr->next = current->next;
                    current->next = newptr;
                    return;
                }
                else
                {
                    current = current->next;
                    counter++;
                }
            }
            assert(current);
        }
    }
    void deletePos( int position)
    {
        if (head == NULL)
            return;
         node<T>* temp = head;
        if (position == 0)
        {
            head = temp->next;
            delete temp;
            return;
        }

        for (int i = 0; temp != NULL && i < position - 1; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL)
            return;
        if (temp->next == tail)
            tail = temp;
         node<T>* next = temp->next->next;

        delete temp->next;

        temp->next = next;
    }

    void deleteVal(T value)
    {
        node<T>* temp = head,* prev=new node<T>;
 
        if (temp != NULL && temp->item == value)
        {
            head= temp->next;   // Changed head 
            delete temp;               // free old head 
            return;
        }
 
        while (temp != NULL && temp->item != value)
        {
            prev = temp;
            temp = temp->next;
        }
 
        if (temp == NULL) return;
        if (temp==tail)
        {
            tail = prev;
        }
        prev->next = temp->next;

        delete temp; 
    }
    void print() {
        assert(head);
        node<T>*current = head;
        cout<<"{";
        while (current!=NULL)
        {
            if (current==tail)
                cout << " " << current->item << " }\n";
            else
                cout << " " << current->item << " ,";

            current = current->next;
        }
    }
    node<T>* getHead() {
        return head;
    }
    node<T>* getTail() {
        return tail;
    }
    static void printLL(node<T>* head) {
        if (head!=NULL)
        {
            cout << head->item<<" ";
            if (head->next == NULL) cout << "\n";
            printLL(head->next);
        }
    }
};
int main()
{
    LinkedList<int> a;
    a.insert(0);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    a.printLL(a.getHead());
    a.insertPos(9, 8);
    a.printLL(a.getHead());
    a.deleteVal(9);
    a.printLL(a.getHead());
    a.deletePos(8);
    a.printLL(a.getHead());
    return 0;

}
