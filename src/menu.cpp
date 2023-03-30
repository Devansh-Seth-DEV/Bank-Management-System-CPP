#include <iostream>
#include <stdio.h>
#include <string> /* To use stoi and function */
#include "../header/menu.h"

/**
 * IntroScreen Function
 * @brief the introduction screen of the program
 */
void introScreen() {
	system("clear");
	std::cout << std::endl;
	std::cout << "              ------------------------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "                                      B A N K" << std::endl;
	std::cout << std::endl;
	std::cout << "                                M A N A G E M E N T" << std::endl;
	std::cout << std::endl;
	std::cout << "                                    S Y S T E M" << std::endl;
	std::cout << std:: endl << std::endl;
	std::cout << "              -----------------------------------------------------------" << std::endl;
	
	std::cout << std::endl;
	std::cout << " Developed By : D E V A N S H   S E T H" << std::endl;
	std::cout << " University   : G A L G O T I A S   U N I V E R S I T Y" << std::endl;

	std::cin.get();
}

/**
 * MainMenu Function
 * @brief main menu of program in which you can perform the following options:
 *			[1] New Account
 *			[2] Deposite Amount
 *			[3] Withdraw Amount
 *			[4] Transfer Amount
 *			[5] Balance Enquiry
 *			[6] All Account Holder List
 *			[7] Close An Account
 *			[8] Modify An Account
 *			[9] EXIT
 *
 * @return returns the option number which gets selected
 */
int mainMenu() {
	system("clear");
	std::string choice="1";
	std::string prev_choice = choice;
	std::string cur = "$";

	/* flag for checking whether the user done its selection */
	bool flag = true;
	
	while(flag) {
		system("clear");
		std::cout << std::endl;
		std::cout << "			 O      B A N K    M A N A G E M E N T    S Y S T E M      O 		" << std::endl;
		std::cout << "			|$|                                                       |$|		" << std::endl;
		std::cout << "			--- $===================================================$ ---		" << std::endl;
		std::cout << std::endl;
		std::cout << "				" << ((choice == "1" ? cur : " ")) << " [1] New Account" << std::endl;
		std::cout << " 				" << ((choice == "2" ? cur : " ")) << " [2] Deposite Amount" << std::endl;
		std::cout << "				" << ((choice == "3" ? cur : " ")) << " [3] Withdraw Amount" << std::endl;
		std::cout << "				" << ((choice == "4" ? cur : " ")) << " [4] Transfer Amount" << std::endl;
		std::cout << "				" << ((choice == "5" ? cur : " ")) << " [5] Balance Enquiry" << std::endl;
		std::cout << "				" << ((choice == "6" ? cur : " ")) << " [6] All Account Holder List" << std::endl;
		std::cout << "				" << ((choice == "7" ? cur : " ")) << " [7] Close An Account" << std::endl;
		std::cout << "				" << ((choice == "8" ? cur : " ")) << " [8] Modify An Account" << std::endl;
		std::cout << "				" << ((choice == "9" ? cur : " ")) << " [9] EXIT" << std::endl;
		std::cout << std::endl << std::endl;
	
		std::cout << "Press <enter> to select the current choice[$], or type selection number: ";
		
		/* Assigning value to prev_choice only when the given input is in between 1-9 */
		if(stoi(choice) <= 9 && stoi(choice) >0) { prev_choice = choice; }

		std::getline(std::cin, choice);
		if(choice !="" && !isdigit(choice.back())) {
			choice = prev_choice;
			continue;
		}

		if(choice == "9" && choice == "") { flag = false; }
		else if(choice == "") { flag = false; }
		else if(stoi(choice) > 9) { choice = prev_choice; }
	}		
	
	/* Checking if the given input is NULL then assigning the false value to it */
	if(choice == "") { choice = prev_choice; }	
	int ch = stoi(choice);
	return ch;		
}
