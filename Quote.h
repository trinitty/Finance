#ifndef _QUOTE
#define _QUOTE

#include <string>

using std::string;

#include "DownloadHandler.h"

class Quote {
private:
	Quote();	

	string symbol, name, date, time;
	double change, price;

	bool init;
	static DownloadHandler *mDH;

	// Decodes the given string into appropriate fields
	void decode(string); 
	string encode();

public:
	Quote(string);												// Build From String
	Quote(string, string, string, string, double, double);		// Build from values

	// Quote Factory method
	static Quote get(char *);

	bool update();
	string toString();

	// Checks if the quote object is initiated properly
	bool isInit();

	// Getters
	string getSymbol();
	string getName();
	string getDateTime();
	string getDate();
	string getTime();
	double getChange();
	double getPrice();
};


#endif
