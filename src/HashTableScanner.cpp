// Nick Brouwer
// Assignment 5


#include <iostream>
#include <fstream>
#include <time.h>
#include "HashTable.h"
#include "HashTableScanner.h"
using namespace std;

int main() {
	HashTable<UPC> table;

	ifstream file("upc_corpus.txt");
	string token1;
	string token2;

	// While loop to read from the file into a HashTable
	while(file.good()) {
		getline(file, token1, ',');	//uses , as splitter instead of white space
		getline(file, token2);
		UPC upc = UPC(token1, token2);
		table.insert(upc);
	}
	file.close();

	HashTableScanner<UPC> scanner = HashTableScanner<UPC>(&table);	// Puts the HashTable into a scanner object for searching


	string code;
	cout << "Enter UPC: ";		// Takes a UPC input and searches the HashTable to get the product
	cin >> code;

	clock_t t;
	t = clock();

	UPC _upc(code, "");
	scanner.scan(_upc);
	cout << _upc.value << endl;		// Prints the product if found

	t = clock() - t;
	cout << "time: " << t << " milliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;


	return 0;
}
