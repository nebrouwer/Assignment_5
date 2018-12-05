// Nick Brouwer
// Assignment 5


#ifndef HASHTABLESCANNER_H_
#define HASHTABLESCANNER_H_
#include <iostream>
#include "Scanner.h"
#include "HashTable.h"
#include "LinkedList.h"
using namespace std;


template <class T>
class HashTableScanner: public Scanner<T>{
	array<LinkedList<T>, 1000> *buckets;

public:
     HashTableScanner<T>(T* _buckets):buckets(_buckets){}

	void scan(T& product){
		T found = buckets->find(product);
		product = found;
	}
};



#endif /* HASHTABLESCANNER_H_ */
