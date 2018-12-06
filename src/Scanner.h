// Nick Brouwer
// Assignment 5


#ifndef SCANNER_H_
#define SCANNER_H_

template <class T>
class Scanner{

public:
	// Declaration for scan function
	virtual void scan(T& product) = 0;
    virtual ~Scanner(){}
};




#endif /* SCANNER_H_ */
