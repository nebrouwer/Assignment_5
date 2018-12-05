// Nick Brouwer
// Assignment 5


#include <iostream>
#include <fstream>
#include <time.h>
#include "HashTable.h"
using namespace std;

int main() {
	HashTable<UPC> table;

		ifstream file("upc_corpus.txt");
		string token1;
		string token2;
		while(file.good()) { //uses , as splitter instead of white space
			getline(file, token1, ',');
			getline(file, token2);
			UPC upc = UPC(token1, token2);
			table.insert(upc);
			//cout << token1 << token2 << endl;
		}
		file.close();

		HashTableScanner<UPC> scanner = HashTableScanner<UPC>(table);


		string code;
		cout << "Enter UPC: ";
		cin >> code;

		clock_t t;
		t = clock();

		UPC upc(code, "");
		scanner.scan(upc);
		cout << upc.value << endl;

		t = clock() - t;
		cout << "time: " << t << " milliseconds" << endl;
		cout << CLOCKS_PER_SEC << " clocks per second" << endl;
		cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;


	return 0;
}
