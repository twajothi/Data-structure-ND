#ifndef __LINKEDLIST_h__
#define __LINKEDLIST_h__
#include <iostream>

using namespace std;

template < typename T >
struct Node  // define a structre node 
{
    T  data;
    Node* next;
};

template < typename T > 
class LinkedList  // class linked list create 
{
    public:
        Node* head;
        LinkedList();
        ~LinkedList();
        void print();
        void pushFront( T value);
	void padList( Node* list, T pad);
	void lenList( Node* head);
	void addinks( Node* list1, Node* list2);

    private:
    //  in case need ... since i have defined tail 
        Node* tail;
}; 

#endif // __LINKEDLIST_h__
