// Nick Brouwer
// Assignment 5


#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <string>
#include <functional>
#include <array>
#include "LinkedList.h"
#include "UPC.h"
using namespace std;

template <class T>
class HashTable {
  private:
	array<LinkedList<T>, 1000> *buckets;
    int hash(T& value);
  public:
    HashTable();
    ~HashTable();
    T find(T& value);
    void insert(T& value);
};

// Main HashTable constructor
template <class T>
HashTable<T>::HashTable(){
	buckets = new array<LinkedList<T>, 1000>;
}

// Hash function
template <class T>
int HashTable<T>::hash(T& value) {
	size_t hash = std::hash<string>{}(value.code);
	return (int)(hash % 1000);
}

// Function to find a UPC in the HashTable and then calls a find in the LinkedList at that array element
template <class T>
T HashTable<T>::find(T& value) {
  int hashCode = hash(value);
  LinkedList<T>& list = buckets->at(hashCode);
  return list.find(value);
}

// Function to insert into the HashTable
template <class T>
void HashTable<T>::insert(T& value) {
  int hashCode = hash(value);
  LinkedList<T>& list = buckets->at(hashCode);
  list.insert(value);
}

// Destructor
template <class T>
HashTable<T>::~HashTable(){
	delete buckets;
}



#endif /* HASHTABLE_H_ */
