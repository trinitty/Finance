#include <iostream>
#include <string>
#include <conio.h>

#include "Quote.h"

using namespace std;

int Amain() {
	
	Quote q = Quote::get("AAPL");

	if(!q.isInit())
		cout << q.getError();
	else
		cout << q.getName() << endl << q.getPrice();

	getch();
	return 0;
}