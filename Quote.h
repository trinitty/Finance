#ifndef _QUOTE
#define _QUOTE

#include <string>

#include "DownloadHandler.h"

using std::string;

/*
 * The Quote Object. holds the data for a stock
 */
class Quote {
private:
	Quote();									// Cannot be instantiated without parameters

	// Private data variables
	string symbol, name, date, time;
	double change, price;
	int number;

	bool init;
	
	static DownloadHandler *mDH;				// The instance of the singleton Downloadhandler

	void decode(string);						// Populates the data variables with the given csv string
	string encode();							// Converts the current data variables to a csv string

public:
	Quote(string, int n = 1);												// Build From csv string, second param = num
	Quote(string, string, string, string, double, double, int n = 1);		// Build from values

	static Quote get(char *, int n = 1);		// Quote Factory. Creates a Quote object from the given symbol

	bool update();								// Refreshes the stock data
	string toString();							// returns a csv string representation of the object

	bool isInit();								// Is the Quote object's data members populated properly

	// Getters
	string getSymbol();
	string getName();
	string getDateTime();
	string getDate();
	string getTime();
	double getChange();
	double getPrice();
	int getNum();

	int setNum(int);							// Returns the previous number value
};


#endif