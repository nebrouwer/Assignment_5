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
		T front();
		T back();
		void insert(T&);
		T find(T&);
		void deleteNode(T&);
		void destroylist();
		LinkedList<T>& operator=(LinkedList<T>&);
		template <class U>
		friend ostream& operator<<(ostream& os, LinkedList<U>& list);
		~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList(){
     head = last = NULL;
     count = 0;
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return head == NULL;
}

template <class T>
int LinkedList<T>::length(){
	return count;
}

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

template <class T>
T LinkedList<T>::find(T& item){
	node<T>* q = head;
	while(q != NULL){
		if(q->data == item){
			return q->data;
		}else{
			q = q->next;
		}
		delete q;
	}
	return item;
}

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
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list){
	if(this != &list){
		copylist(list);
	}
	return *this;
}
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
	node<T> *p = list.head;
	while(p != NULL){
		os << p->data << " " << endl;
		p = p->next;
	}
	return os;
}

template <class T>
LinkedList<T>::~LinkedList(){
	destroylist();
}


#endif /* LINKEDLIST_H_ */
