#ifndef _USER
#define _USER

#include <string>
#include <vector>

#include "Quote.h"

using std::string;
using std::vector;

/*
 * Keeps track of all the details of the current User
 */
class User {
	// Singleton methods
	static User *mInstance;				// The instance of the user object to be used
	User();								// Private constructor, singleton class

	vector<Quote> portfolio;			// Keeps Track of all the Quotes the user owns
	double cInHand;						// Cash the user has in hand

	string name;
	double stockWorth, totalWorth, cashInHand;

public:
	
	static User * getInstance();

	// IMPORTANT : All Error checking should be done before calling sell() or buy(). 

	// Buys n of the given Quote. 
	// Expect a lag
	void buy(Quote, int);	

	// Will return a float with the price it was sold for
	// the sold stock (included price sold at)
	// Takes in two params, the name of stock and number to sell
	float sell(string, int);				


	// Utility Functinos
	int getIndex(string);					// Returns the index of the Quote object in the portfolio
											// IMPORTANT : Make sure it is not -1, which means not found

	Quote getQuote(int);					// Returns the Quote at the corrosponding portfolio position
											// MUST be a valid index

	vector<Quote> getPortfolio();			// Returns a vector of all the Quotes in the portfolio

	// Getters and setters
	const char * getName();
	double getStockWorth();
	double getCashInHand();
	double getTotalWorth();

	void setName(char *);
	
	string getError();

};

#endif
