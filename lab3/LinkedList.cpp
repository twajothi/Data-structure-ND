#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() //constructor for a linked list
{
    this->head = nullptr;
}

LinkedList::~LinkedList() // deconstructor for  a linked ist
{
    Node* current = head;

    while (current != 0)
    { 
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;     // reassigning head to nullptr after use
}
template < class T > 
void LinkedList<T>::pushFront(T value) // function that helps to add values in a linkedlisth
{
    if (head == NULL)
    {
        head = new Node();
        tail = head;
        head->next = nullptr;
        head->data = value;
    }
    else
    {
        tail->next = new Node();
        tail = tail->next;
        tail->data = value;
        tail->next = nullptr;
    }
}

template < class T>
void LinkedList<T>::print() // function that prints values in a linked list
{
    Node* temp;

    if (head == NULL)
    {
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }

    std::cout << std::endl;
}

template < class T >
void LinkedList<T>::lenList ( Node* head)
{
	Node*temp = head;
	int len = 0; 
	while ( temp ) {
		temp = temp->next; 
		len++

}
	return len; 

}
template <class T>
void LinkedList<T>::padList ( Node* list, T pad ) {   // add zeros in case there lengths of lists are different 
	int count = 0; 
	Node*temp = list;
	
	while ( temp -> next)
	{
		temp = temp->next;

	}	
	
	while ( count != pad )	{

		temp->next = new Node();
		temp = temp->next;
		temp->data = 0;
		temp->next = nullptr;
		count++;

	}
}

template <class T>
void LinkedList<T>::addLinks ( Node* list1, Node* list2){

	if ( list1 = NULL && list2 = NULL ) 
	{
		return;
	}

	int carry = 0; // initiate different variable 
	int val = 0; 
	Node* l1 = list1;
	Node* l2 = list2;

	//check the length of the list .. if found short  pad
	int l1Len = lenList(l1);
	int l2Len = lenList(l2);

	if ( l1len > l2len )
	{
		padList( l2, l1len - l2len ); 
	}
	
	if ( l2len > l1len ) 
	{
		padList( l1, l2Len - l1len);
	}
	
	while ( l1 || l2)
	{
		l1->data += carry;
		val = l1->data + l2->data;
		if ( val > 9 )
		{
			carry = 1;
			val = val - 10;
		}
		else {
			carry = 0;
		}
			l1->data = val;
			l1 = l1->next;
			l2 = l2->next;
	if ( carry ) // if there is an extra number after sum ... add this to the end  
		{
			l1 = list1;
			while ( l1->next){
				l1 = l1->next;
			}
			l1->next = new Node();
			l1->next->data = 1;
			l1->next->next = nullptr;
		}
	}
}

int main () {
	
	 LinkedList* list1 = new LinkedList();
	 LinkedList* list2 = new LinkedList();

	
	 string numbString1, numbString2, holder;
	 int val; 
 
while ( !cin.eof()){
 	cout << " enter the under " << endl;
	cin >> numbString1, numbString2; 
for ( int i = numbString1.length()-1; i > -1 ; i++ ){
	holder = numbString1[i];
	val = stoi(holder);
	list1.pushFront(val);
}


for ( int i = numbString2.length()-1; i > -1 ; i++ ){
	holder = numbString2[i];
	val = stoi(holder);
	list2.pushFront(val);
}

	cout << " the imput digit in our linked lists are " << endl;
	list1.print();
	list2.print();

	return 0;
}
