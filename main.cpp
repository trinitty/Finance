#include <iostream>
#include <string>
#include <conio.h>

#include "Quote.h"

using namespace std;

int main() {
	
	Quote q = Quote::get("AAPL");
	
	if(!q.isInit())
		cout << "Incorrect stock symbol!";
	else
		cout << q.getName() << endl << q.getPrice();

	getch();
	return 0;
}