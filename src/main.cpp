#include <iostream>
#include <stdio.h>
#include "../header/account.h"
#include "../header/menu.h"
#include "../header/crud.h"
#include "../header/task.h"

#define BIN "record.bin"

int main() {
	int ch;
	bool run = true; /* to run the program until not exited */
	introScreen();
	
	while(run) {
		ch = mainMenu();

		if(ch == 1) { updateRecord(ch); }

		else if(ch == 2) { transactionMenu(1); }

		else if(ch == 3) { transactionMenu(2); }

		else if(ch == 4) { transactionMenu(3); }

		else if(ch == 5) { balanceEnquiry(); }
		
		else if(ch == 6) { showAccountHolders(); }

		else if(ch == 7) { closeAccount(); }

		else if(ch == 8) { updateRecord(ch); }

		else { run = false; }
	}
	
	printf("\e[1;1H\e[2J");

	return 0;	
}
