
#include "User.h"

// Singleton Utilities
User * User::mInstance = NULL;

User * User::getInstance() {
	if(mInstance == NULL)
		mInstance = new User();

	return mInstance;
}

// DEBUG CODE
User::User() {
	cashInHand = 10000;
	stockWorth = 0;
}

void User::buy(Quote q, int n) {
	q.refresh();
	double change = q.getnPrice() * n;

	cashInHand -= change;
	stockWorth += change;

	q.setNum(n);
	portfolio.push_back(q);
}

float User::sell(string s, int n) {
	int pos = getIndex(s);
	// Quote not in Portfolio. This should never happen
	if(pos == -1) return pos;

	Quote *q = &portfolio.at(pos);
	q->refresh();

	// Price to be sold at
	int price = q->getnPrice();
	int number = q->getNum();

	// Selling all the stocks
	if(number <= n) {
		portfolio.erase(portfolio.begin() + pos);

	} else {
		q->setNum(number - n);
	}

	double change = n * price;
	cashInHand += change;
	stockWorth -= change;

	return price;
}

Quote User::getQuote(int i) {
	return portfolio[i];
}

int User::getIndex(string s) {
	for(vector<Quote>::iterator i = portfolio.begin(); i != portfolio.end(); ++i)
		if(i->getSymbol() == s)
			return i - portfolio.begin();

	return -1;
}

vector<Quote> User::getPortfolio() { return portfolio; }

// Getters and setters
const char * User::getName()	{ return name.c_str(); }
double User::getStockWorth()	{ return stockWorth; }
double User::getCashInHand()	{ return cashInHand; }
double User::getTotalWorth()	{ return stockWorth + cashInHand; }

void User::setName(char *n) {
	name = n;
}