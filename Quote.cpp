#include <string>

#include "Quote.h"
#include "DownloadHandler.h"

using std::string;

DownloadHandler* Quote::mDH = DownloadHandler::getDownloadHandler();

// Constructors

// Should not be used
Quote::Quote() {}

Quote::Quote(string mSymbol, string mName, string mDate, string mTime, double mPrice, double mChange) {
	symbol	= mSymbol;
	name	= mName;
	date	= mDate;
	time	= mTime;
	price	= mPrice;
	change	= mChange;

	init = true;
}

Quote::Quote(string s) {
	decode(s);
}

// Decodes Quote data from a CSV string
void Quote::decode(string s) {
	int x;

	// Symbol
	x = s.find(',');
	symbol = s.substr(1, x-2);
	s.erase(0, x+1);

	// Name
	x = s.find(',');
	name =  s.substr(1, x-2);
	s.erase(0, x+1);

	// Price
	x = s.find(',');
	price =  atof(s.substr(0, x).c_str());
	s.erase(0, x+1);

	// Date
	x = s.find(',');
	date =  s.substr(1, x-2);
	s.erase(0, x+1);

	// Time
	x = s.find(',');
	time =  s.substr(1, x-2);
	s.erase(0, x+1);

	// Change
	x = s.find(',');
	change =  atof(s.substr(0, x).c_str());
	s.erase(0, x+1);

	if(price == 0)
		init = false;
	else
		init = true;
}

// Convert current Quote object to a CSV format string
string Quote::encode() {
	if(!isInit())
		return "\"ERROR\",\"N/A\",0.00,\"N/A\",\"N/A\",N/A";

	char buffer[250];
	sprintf(buffer, "\"%s\",\"%s\",%g,\"%s\",\"%s\",%g", symbol.c_str(), name.c_str(), price, date.c_str(), time.c_str(), change);

	string out(buffer);
	return out;
}

Quote Quote::get(char *symbol) {
	string res = mDH->download(symbol);

	if(mDH->success()) {
		Quote q(res);
		return q;
	}

	// In case of download Failure return empty object
	Quote q;
	return q;
}

bool Quote::update() {
	string res = Quote::mDH->download(symbol.c_str());

	if(mDH->success()) {
		decode(res);
		return true;
	}

	// Update Failed
	return false;
}


string Quote::toString() {
	if(!isInit())
		return "Not Initiated";
	else
		return encode();
}

// Getters
bool Quote::isInit()		{ return init; }
string Quote::getSymbol()	{ return symbol; }
string Quote::getName()		{ return name; }
string Quote::getDateTime() { return date + " " + time; }
string Quote::getDate()		{ return date; }
string Quote::getTime()		{ return time; }
double Quote::getChange()	{ return change; }
double Quote::getPrice()	{ return price; }
