// Nick Brouwer
// Assignment 5


#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;


template <class T>
struct node{
	T data;
	node* next;

	node():data(), next(NULL) {}
};

template <class T>
class LinkedList{
	private:
		LinkedList(const LinkedList&) = delete; //copy constructor

	protected:
		int count;
		node<T> *head, *last;
	public:
		LinkedList();
		bool isEmpty();
		int length();
		void insert(T&);
		T find(T&);
		void deleteNode(T&);
		void destroylist();
		LinkedList<T>& operator=(LinkedList<T>&);
		template <class U>
		friend ostream& operator<<(ostream& os, LinkedList<U>& list);
		~LinkedList();
};

// Main constructor for LinkedList used in HashTable array
template <class T>
LinkedList<T>::LinkedList(){
     head = last = NULL;
     count = 0;
}

// Returns true or false based on whether or not the list is empty
template <class T>
bool LinkedList<T>::isEmpty(){
	return head == NULL;
}

// Returns the length of the list
template <class T>
int LinkedList<T>::length(){
	return count;
}

// Function to insert into the list
template <class T>
void LinkedList<T>::insert(T& item){
	node<T> *temp = new node<T>;
	temp->data = item;
	temp->next = head;
	head = temp;
	count++;
	if(last == NULL)
		last = temp;
}

// Function to find an item in the list
template <class T>
T LinkedList<T>::find(T& item){
	node<T>* q = head;
	while(q != NULL){
		if(q->data == item){
			return q->data;
		}else{
			q = q->next;
		}
	}
	return item;
}

// Function to delete a node in the list
template <class T>
void LinkedList<T>::deleteNode(T& item){
	if(head == NULL)
		cerr << "empty list";
	else{
		if(head->data == item){
			node<T>* p = head;
			head = head->next;
			delete p;
			count--;
			if(head == NULL) last = NULL;
		}else{
			node<T>* p = head;
			node<T>* q = p->next;
			while(q != NULL && q->data != item){
				p = q;
				q = q->next;
			}
			if(q != NULL){
				p->next = q->next;
				count--;
				if(last == q) last = p;
				delete q;
			}
		}
	}
}

// Function to destroy an entire list
template <class T>
void LinkedList<T>::destroylist(){
	node<T> *p;
	while(head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}

// Overloaded = operator
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list){
	if(this != &list){
		copylist(list);
	}
	return *this;
}

// Overloaded << operator
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
	node<T> *p = list.head;
	while(p != NULL){
		os << p->data << " " << endl;
		p = p->next;
	}
	return os;
}

// Destructor for LinkedList
template <class T>
LinkedList<T>::~LinkedList(){
	destroylist();
}


#endif /* LINKEDLIST_H_ */
