// Nick Brouwer
// Assignment 4

#ifndef UPC_H_
#define UPC_H_
#include <string>
#include <iostream>
using namespace std;

class UPC {
public:
	string code;
	string value;
	UPC();
	UPC(string, string);
	UPC(const UPC& upc);
	friend bool operator<(UPC& upc1, UPC& upc2);
	friend bool operator>(UPC& upc1, UPC& upc2);
	friend bool operator==(UPC& upc1, UPC& upc2);
	friend ostream& operator<<(ostream& os, UPC& u);
};



#endif /* UPC_H_ */
