// Nick Brouwer
// Assignment 5


#include "UPC.h"

UPC::UPC() : code(""), value("") {}
UPC::UPC(string upc, string product):code(upc), value(product){

}
UPC::UPC(const UPC& upc):code(upc.code), value(upc.value){}

bool operator<(UPC& upc1, UPC& upc2){
	return upc1.code < upc2.code;
}
bool operator>(UPC& upc1, UPC& upc2){
	return upc1.code > upc2.code;
}
bool operator==(UPC& upc1, UPC& upc2){
	return upc1.code == upc2.code;
}
ostream& operator<<(ostream& os, UPC& u){
	os << u.code << ":" << u.value;
	return os;
}

