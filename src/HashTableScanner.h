// Nick Brouwer
// Assignment 5


#ifndef HASHTABLESCANNER_H_
#define HASHTABLESCANNER_H_
#include <iostream>
#include <array>
#include "Scanner.h"
#include "HashTable.h"
#include "LinkedList.h"
using namespace std;


template <class T>
class HashTableScanner: public Scanner<T>{
	HashTable<T> *buckets;

public:
	// Constructor for HashTableScanner object
    HashTableScanner<T>(HashTable<T> *_buckets):buckets(_buckets){}

    // Function to scan the HashTable
	void scan(T& product){
		T found = buckets->find(product);
		product = found;
	}
};



#endif /* HASHTABLESCANNER_H_ */
