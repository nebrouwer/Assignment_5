// Nick Brouwer
// Assignment 5


#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <string>
#include <array>
#include "LinkedList.h"
#include "UPC.h"
#include "HashTableScanner.h"
using namespace std;

template <class T>
class HashTable {
  private:
	array<LinkedList<T>, 1000> *buckets;
    int hash(T& value);
  public:
    HashTable();
    T find(T& value);
    void insert(T& value);
};

template <class T>
HashTable<T>::HashTable(){
	buckets = 0;
}

template <class T>
int HashTable<T>::hash(T& value) {
	int upc = stoi(value.code);
	return upc % 1000;
}

template <class T>
T HashTable<T>::find(T& value) {
  int hashCode = hash(value);
  LinkedList<T>& list = buckets[hashCode];
  return list.find(value);
}

template <class T>
void HashTable<T>::insert(T& value) {
  int hashCode = hash(value);
  LinkedList<T>& list = buckets[hashCode];
  list.insert(value);
}



#endif /* HASHTABLE_H_ */
