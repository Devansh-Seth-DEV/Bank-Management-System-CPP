#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream> /* To make use of stringstream built-in function */
#include <fstream>
#include <iomanip> /* To manupulate input and output stream accordingly */
#include <boost/algorithm/string.hpp>
#include "../header/task.h"
#include "../header/account.h"
#include "../header/crud.h"

#define BIN "record.bin"

/**
 * TitleBar Function
 * @brief displays the title of the program on the console
 */
void titleBar() {
	std::cout << std::endl;
	std::cout << "			 O      B A N K    M A N A G E M E N T    S Y S T E M      O 		" << std::endl;
	std::cout << "			|$|                                                       |$|		" << std::endl;
	std::cout << "			--- $===================================================$ ---		" << std::endl;
	std::cout << std::endl;
}

/**
 * UpdateRecord Function
 * @brief updates the records
 *
 * @param action 1 for creation of new account and other for account updation
 *
 * @return returns boolean true if records successfully updated else boolean false
 */	
bool updateRecord(const int action) {

	/* Flag for successfull updation of account */
	bool flag = false;
	bool uflag = false; /* flag for checking whether the account to be updated exists */

	while(true) {
		/* Flag for checking if any changes to be made */
		std::string change;

		Account user;
		std::string str;

		printf("\e[1;1H\e[2J");
		titleBar();
	
		if(action == 1) {
			std::cout << "				N E W    A C C O U N T    M E N U" << std::endl;
			std::cout << "				 -------------------------------" << std::endl << std::endl;
		}
		else {
			std::string pin;
			std::string acc_n;

			while(true) {
				printf("\e[1;1H\e[2J");
				titleBar();

				std::cout << "				U P D A T E    A C C O U N T    M E N U" << std::endl;
				std::cout << "				 -------------------------------------" << std::endl << std::endl;
			
				std::cout << "			Press <esc + enter> to go back to previous menu" << std::endl << std::endl;	
			
				std::cout << "				Enter the Account Number: ";
				std::getline(std::cin, acc_n);

				/* To remove the spaces of the account number */
				acc_n.erase(std::remove_if(acc_n.begin(), acc_n.end(), isspace), acc_n.end());
	
				if(acc_n.back() == 27) { return false; }

				std::cout << "				Enter the 4-digit PIN: ";
				std::getline(std::cin, pin);

				/* To remove the spaces of PIN */
				pin.erase(std::remove_if(pin.begin(), pin.end(), isspace), pin.end());

				if(pin.back() == 27) { return false; }

				size_t bytes = 0;
				while(bytes<user.fileSize(BIN)) {
					user = read(BIN, user, bytes, std::ios::beg);
					if(user.getAccN() == acc_n && user.getPin() == pin) {
						uflag = true;
						break;
					}
					bytes += sizeof(user);
				}

				/* Checking whether the given account data exists or not */
				if(!uflag) {
					std::cout << std::endl;
					std::cout << "				ACCOUNT NOT FOUND !" << std::endl;
					std::cout << std::endl;
					std::cout << "<Please enter correct Account Number or PIN> !" << std::endl;
					std::string buff; /* buffer for taking <enter> key press */
					std::getline(std::cin, buff);
					continue;
				}
				
				else { break; }
			}

			printf("\e[1;1H\e[2J");
			titleBar();
		} 
		
		if(uflag) {
			std::cout <<"				U P D A T E    R E C O R D    M E N U" << std::endl;
			std::cout << "				 -----------------------------------" << std::endl << std::endl;
		}
			
		std::cout << "			Press <esc + enter> to go back to previous menu" << std::endl << std::endl;

		std::cout << "				Enter Account Holder's Name: ";
		user.setName(std::cin);
		if(user.getName().back() == 27) { break; }
	
		std::cout << "				Enter Account Holder's Address: ";
		user.setAddress(std::cin);
		if(user.getAddress().back() == 27) { break; }
	
		std::cout << "				Enter Account Holder's Mobile Number: ";
		std::getline(std::cin, str);
		if(str.back() == 27) { break; }
bool mFlag = false; /* Flag for checking the <esc + escape> key press */

		/* Looping until the input number contains 10-digits */
		while(str.length() != 10) {
			str = "";

			std::cout << std::endl;
			std::cout << "			Please enter valid Mobile Number !" << std::endl;
			std::cout << std::endl;

			std::cout << "				Enter Account Holder's Mobile Number: ";
			std::getline(std::cin, str);
			if(str.back() == 27) {
				mFlag = true; /* encountered the <esc + escape> key press */
				break;
			 }

			/* To Remove the spaces from the number */
			str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());			
		}

		if(mFlag) { break; }
		user.setMob(std::stoul(str));

		str = "";
	
		std::cout << "				Enter Account Holder's Date of Birth <dd-mm-yy>: ";
		std::getline(std::cin, str);
		if(str.back() == 27) { break; }
		/* To Remove the spaces of the account number */
		str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

		bool dFlag = false; /* Flag for checking the <esc + enter> key press */

		/* Checking whether the date of birth is in format <dd-mm-yy> or not */
		while(str.length() != 8) {
			str = "";

			std::cout << std::endl;
			std::cout << "			Please enter Date of Birth in <dd-mm-yy> format !" << std::endl << std::endl;
			std::cout << "				Enter Account Holder's Date of Birth <dd-mm-yy>: ";
			std::getline(std::cin, str);
			if(str.back() == 27) {
				dFlag = true; /* enountered the <esc + escape> key press */
				break;
			 }

			/* To Remove the spaces from the format */
			str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
		}
		
		if(dFlag) { break; }

		/* Typecasting the string into unsigned short integer */
		unsigned short int d, m, y;

		/* Extracting the first two characters representing the date */
		d = static_cast<unsigned short int>(std::stoul(str.substr(0,2)));

		/* Extracting the third and fourth characters representing the month */
		m = static_cast<unsigned short int>(std::stoul(str.substr(2,2)));

		/* Extracting the last four characters representing the year */
		y = static_cast<unsigned short int>(std::stoul(str.substr(4,4)));

		user.setDob(y, m, d);
	
		std::cout << "				Enter the Account Type [ 'c' for current | 's' for saving ]: ";
		user.setAccT(std::cin);
		if(user.getAccT() == 27) { break; }
	
		if(action == 1) {
			printf("\e[1;1H\e[2J");
			titleBar();

			/* Condition for opening amount with respect to the account type */
			if(user.getAccT() == 'c') {
				std::cout << std::endl;
				std::cout << "			NOTE: Minimum amount for current account >= 5000" << std::endl;
				std::cout << std::endl;

				unsigned long long int balance;

				/* Looping until the entered amount satisfies the minimun requirement type */
				while(true) {
					std::cout << "				Enter the Opening Balance: ";
					std::cin >> balance;

					/* checking the minimum balance required for a current account */
					if(balance >= 5000) { 
						user.setBalance(balance);
						break;
					}
					else {
						balance = 0;
						std::cout << std::endl;
						std::cout << "			Please enter the amount >= 5000" << std::endl << std::endl;
					}
				}
			}

			else {
				std::cout << std::endl;
				std::cout << "			NOTE: Minimum amount for saving account >= 2500" << std::endl;
				std::cout << std::endl;

				unsigned long long int balance;

				/* checking the minimum balance required for a saving account */
				while(true) {
					std::cout << "				Enter the Opening Balcnce: ";
					std::cin >> balance;

					/* Checking the minimum balance required for a saving account */
					if(balance >= 2500) {
						user.setBalance(balance);
						break;
					}
					else {
						balance = 0;
						std::cout << std::endl;
						std::cout << "			Please enter the amount >= 2500" << std::endl << std::endl;
					}
				}
			}
		}	
		
		bool pinFlag = false; /* Flag for checking the <esc + enter> key press */

		/* Looping until the pin contains 4-digits */
		while(true) {
			std::string pin;

			std::cout << std::endl;	
			std::cout << "				Enter the 4-digit PIN: ";
			std::cin >> pin;

			if(pin.back() == 27) {
				pinFlag = true; /* encountered the <esc + enter> key press */
				break;
			}

			/* Setting the PIN only when it contains 4-digits */
			else if(pin.length() == 4) {
				user.setPin(pin);
				break;
			}
			
			else {
				std::cout << std::endl << "			PIN MUST BE OF 4-digits !" << std::endl;
			}
		}

		if(pinFlag) { break; }
				
		std::cin.get();
	
		if(action == 1) {
			user.generateAccNo();
			user.generateCstId();
		}
	
		/* ---------------------- @Displaying the Account Details -------------------------- */
		
		bool flag2 = false; /* Flag for checking whether the changes to be made or proceed further */

		while(true) {
			printf("\e[1;1H\e[2J");
			titleBar();

			std::cout << "				A C C O U N T    D E T A I L S" << std::endl;
			std::cout << "				 ----------------------------" << std::endl << std::endl;
			std::cout << "					Account NO: ";
	
			int i = 0;
			for(auto &ch : user.getAccN()) {
				if(i>0 && i%4==0) { std::cout << " "; }
				std::cout << ch;
				i++;
			}
			std::cout << std::endl;
	
			std::cout << "					Customer ID: " << user.getCstId() << std::endl;
			std::cout << "					PIN: " << user.getPin() << std::endl << std::endl;
			std::cout << "					Name: " << user.getName() << std::endl;
			std::cout << "					Address: " << user.getAddress() << std::endl;
			std::cout << "					Mobile No.: " << user.getMob() << std::endl;
			std::cout << "					Date of Birth <dd-mm-yy>: " << user.getDobD() << "-" << user.getDobM() << "-" << user.getDobY() << std::endl << std::endl;
			std::cout << "					Joined Date <dd-mm-yy>: " << user.getJDate() << "-" << user.getJMonth() << "-" << user.getJYear() << std::endl;
			std::cout << "					Joined Day: ";

			switch(user.getJDay()) {
				case 1:
					std::cout << "Monday";
					break;
				case 2:
					std::cout << "Tuesday";
					break;
				case 3:
					std::cout << "Wednesday";
					break;
				case 4:
					std::cout << "Thursday";
					break;
				case 5:
					std::cout << "Friday";
					break;
				case 6:
					std::cout << "Saturday";
					break;
				default:
					std::cout << "Sunday";
			}
	
			std::cout << std::endl;

			std::cout << "					Joined Time <hour:min:sec>: " << user.getJHour() << ":" << user.getJMin() << ":" << user.getJSec() << std::endl;
			std::cout << std::endl;
			std::cout << "					Account Type: ";
	
			if(user.getAccT() == 'c') { std::cout << "Current" << std::endl; }
			else { std::cout << "Saving" << std::endl; }
			std::cout << std::endl;
			std::cout << "					Balance: " << user.getBalance() << std::endl;
			std::cout << std::endl;
	
			if(action == 1) {
				std::cout << "Press <enter> to register, or type [ Y/y ] for changes ? ";
			}
			else {
				std::cout << "Press <enter> to update, or type [ Y/y ] for changes ? ";
			}

			std::getline(std::cin, change);

			if(change == "Y" || change == "y") {
				flag2 = true;
				break;
			}
			else if(change != "") { continue; }
			else { break; } 
		}
		
		if(flag2) { continue; }

		/* ---------------------- @Updating Record ---------------------- */

		printf("\e[1;1H\e[2J");
		titleBar();
		
		if(action == 1) { flag = create(BIN, user); }
		else { flag = update(BIN, user); }

		std::cout << std::endl << std::endl;
		if(flag) {
			if(action == 1) {
				std::cout << "				ACCOUNT SUCCESSFULLY REGISTERED !" << std::endl << std::endl;
			}
			else {
				std::cout << "				ACCOUNT SUCCESSFULLY UPDATED !" << std::endl << std::endl;
			}
		}

		else {
			if(action == 1) {
				std::cout << "				ERROR: Account registration failed !" << std::endl << std::endl;
			}
			else {
				std::cout << "				ERROR: Account updation failed !" << std::endl << std::endl;
			}
		}
		
		std::cout << "Press <enter> to exit" << std::endl;

		std::string buff; /* For checking the <enter> key press */
		std::getline(std::cin, buff);
		break;
	}
	
	return flag;
}

/**
 * TransactionMenu Function
 * @brief to credit/debit the amount into/from the account
 *
 * @param action 1 for depositing, 2 for withdrawing, any other integer for transfer
 * 
 * @return returns boolean true if amount successfully credited/debited otherwise boolean false
 */
bool transactionMenu(const int action) {
	printf("\e[1;1H\e[2J");
	titleBar();
	
	/* Flag to check whether the transaction processed successfully or not */
	bool flag = false;

	while(true) {
		printf("\e[1;1H\e[2J");
		titleBar();
		
		Account user;
		std::string acc_n;
		std::string pin;

		if(action == 1) {
			std::cout << "				D E P O S I T E    M E N U" << std::endl;
		}

		else if(action == 2) {
			std::cout << "				W I T H D R A W    M E N U" << std::endl;
		}

		else {
			std::cout << "				T R A N S F E R    M E N U" << std::endl;
		}

		std::cout << "				 ------------------------" << std::endl << std::endl;
	
		std::cout << "			  Press <esc + enter> to go back to previous menu" << std::endl << std::endl;

		std::cout << "				Enter the Account Number: ";
		std::getline(std::cin, acc_n);

		/* To remove the spaces of the account number */
		acc_n.erase(std::remove_if(acc_n.begin(), acc_n.end(), isspace), acc_n.end());

		if(acc_n.back() == 27) { return false; }

		std::cout << "				Enter the 4-digit PIN: ";
		std::getline(std::cin, pin);

		/* To remove the spaces of PIN */
		pin.erase(std::remove_if(pin.begin(), pin.end(), isspace), pin.end());

		if(pin.back() == 27) { return false; }


		bool fileflag = false; /* Flag for checking whether the input account exists or not */
		
		std::ifstream file(BIN, std::ios::binary | std::ios::out);
	
		/* Checking if the file stream is opened successfully */
		if(file) {
			while(file.read((char*)&user, sizeof(user))) {
				/* Comparing the given account data with the existing */
				if(user.getAccN() == acc_n && user.getPin() == pin) { 
					fileflag = true;
					break;
				}
			}
		}

		else {
			std::cout << std::endl;
			std::cout << "			------------------------------" << std::endl;
			std::cout << "			ERROR: Unable to read the file while checking for account existence" << std::endl;
			std::cout << "			------------------------------" << std::endl;
			std::cout << std::endl;
		}
		
		file.close();

		/* Checking whether the given account data exists or not */
		if(!fileflag) {
			std::cout << std::endl;
			std::cout << "				ACCOUNT NOT FOUND !" << std::endl;
			std::cout << std::endl;
			std::cout << "<Please enter correct Account Number or PIN> !" << std::endl;
			std::string buff; /* buffer for taking <enter> key press */
			std::getline(std::cin, buff);
			continue;
		}
		
		printf("\e[1;1H\e[2J");
		titleBar();

		if(action == 1) {
			std::cout << "				D E P O S I T E    M E N U" << std::endl;
		}

		else if(action == 2) {
			std::cout << "				W I T H D R A W    M E N U" << std::endl;
		}

		else {
			std::cout << "				T R A N S F E R    M E N U" << std::endl;
		}

		std::cout << "				 ------------------------" << std::endl << std::endl;
		std::cout << std::endl;

		std::cout << "					A C C O U N T    S T A T U S" << std::endl;
		std::cout << "					 --------------------------" << std::endl << std::endl;
		
		std::cout << "				 	   Account Holder: " << user.getName() << std::endl;
		std::cout << "				 	   Account Type: ";
		if(user.getAccT() == 'c') { std::cout << "Current"; }
		else { std::cout << "Saving"; }
		std::cout << std::endl;

		std::cout << "				  	   Balance Amount: " << user.getBalance() << std::endl << std::endl;
		std::cout << "					 --------------------------" << std::endl << std::endl;

		if(action == 1) {
			std::cout << "				Enter the Credit Amount: ";
			user.credit(std::cin);
			flag = update(BIN, user); /* Updating flag and user account file */
		}

		else if(action == 2) {
			unsigned long long int amount;

			while(true) {
				std::cout << "				Enter the Debit Amount: ";
				std::cin >> amount;
				if(amount>user.getBalance()) {
					std::cout << std::endl;
					std::cout << "			NOT ENOUGH BALANCE TO DEBIT !" << std::endl;
					std::cout << std::endl;
					continue;
				}
				else { break; }
			}

			user.debit(amount);
			flag = update(BIN, user); /* Updating flag and user account file */
		}
		
		else {
			acc_n = "";
			Account t_user;
			unsigned long long int amount;

			while(true) {
				printf("\e[1;1H\e[2J");
				titleBar();

				std::cout << "				T R A N S F E R    M E N U" << std::endl;

				std::cout << "				 ------------------------" << std::endl << std::endl;
				std::cout << std::endl;

				std::cout << "					A C C O U N T    S T A T U S" << std::endl;
				std::cout << "					 --------------------------" << std::endl << std::endl;
				
				std::cout << "				 	   Account Holder: " << user.getName() << std::endl;
				std::cout << "				 	   Account Type: ";
				if(user.getAccT() == 'c') { std::cout << "Current"; }
				else { std::cout << "Saving"; }
				std::cout << std::endl;

				std::cout << "				  	   Balance Amount: " << user.getBalance() << std::endl << std::endl;
				std::cout << "					 --------------------------" << std::endl << std::endl;

				std::cout << "				Enter the Transmittal Account Number: ";
				std::getline(std::cin, acc_n);

				/* To remove the spaces of the account number */
				acc_n.erase(std::remove_if(acc_n.begin(), acc_n.end(), isspace), acc_n.end());

				while(true) {
					std::cout << "				Enter the Transfer Amount: ";
					std::cin >> amount;
					if(amount>user.getBalance()) {
						std::cout << std::endl;
						std::cout << "			NOT ENOUGH BALANCE TO TRANSFER !" << std::endl;
						std::cout << std::endl;
						continue;
					}
					else {
						break;
					}
				}

				bool fileflag = false; /* Flag for checking whether the input account exists or not */
				
				std::ifstream file(BIN, std::ios::binary | std::ios::out);
			
				/* Checking if the file stream is opened successfully */
				if(file) {
					while(file.read((char*)&t_user, sizeof(t_user))) {
						/* Comparing the given account data with the existing */
						if(t_user.getAccN() == acc_n) { 
							fileflag = true;
							break;
						}
					}
				}

				else {
					std::cout << std::endl;
					std::cout << "			------------------------------" << std::endl;
					std::cout << "			ERROR: Unable to read the file while checking for account existence" << std::endl;
					std::cout << "			------------------------------" << std::endl;
					std::cout << std::endl;
				}
				
				file.close();

				/* Checking whether the given account data exists or not */
				if(!fileflag) {
					std::cout << std::endl;
					std::cout << "				ACCOUNT NOT FOUND !" << std::endl;
					std::cout << std::endl;
					std::cout << "<Please enter correct transmittal Account Number !>" << std::endl;
					std::cin.get(); /* clearing the input stream buffer */
					std::string buff; /* buffer for taking <enter> key press */
					std::getline(std::cin, buff);
					continue;
				}

				else if(t_user.getAccN() == user.getAccN()) {
					printf("\e[1;1H\e[2J");
					titleBar();

					std::cout << "				SELF TRANSFER NOT ALLOWED !" << std::endl;
					std::cout << std::endl;

					std::cout << "Press <enter> to continue" << std::endl;
					std::cin.get(); /* clearing the input stream buffer */
					std::string buff; /* buffer for taking <enter> key press */
					std::getline(std::cin, buff);
					continue;
				}

				user.debit(amount);
				t_user.credit(amount);

				flag = update(BIN, user);
				flag = update(BIN, t_user);
				break;
			}
		}

		printf("\e[1;1H\e[2J");
		titleBar();
		
		/* For checking whether the amount successfull transaction */
		if(flag) {
			std::cout << std::endl;
			std::cout << "				AMOUNT SUCCESSFULLY ";

			if(action == 1) {
				std::cout << "CREDITED !" << std::endl;
			}

			else if(action == 2) {
				std::cout << "DEBITED !" << std::endl;
			}

			else {
				std::cout << "TRANSFERED !" << std::endl;
			}
		}
		else {
			std::cout << std::endl;
			std::cout << "				AMOUNT ";

			if(action == 1) {
				std::cout << "CREDIT FAILED !" << std::endl;
			}

			else if(action == 2) {
				std::cout << "DEBIT FAILED !" << std::endl;
			}

			else {
				std::cout << "TRANSFER FAILED !" << std::endl;
			}
		}

		std::cout << "Press <enter> to exit" << std::endl;
		std::cin.get(); /* flusing the input stream */

		std::string buff; /* buffer for taking the <enter> input*/
		std::getline(std::cin, buff);
		break;
	}
	
	return flag;
}


/**
 * BalanceEnquiry Function
 * @brief displays the current balance status of the account
 *
 * @return True if displayed successfully else False
 */
bool balanceEnquiry() {
	bool flag = false; /* flag for function status */
	Account user;
	std::string acc_n = "";

	while(true) {
		printf("\e[1;1H\e[2J");
		titleBar();

		
		std::cout << "				B A L A N C E    E N Q U I R Y" << std::endl;
		std::cout << "				 ----------------------------" << std::endl << std::endl;

		std::cout << "			Press <esc + enter> to go back to previous menu" << std::endl << std::endl;

		std::cout << "					Enter the Account Number: ";
		std::getline(std::cin, acc_n);
		if(acc_n.back() == 27) { break; }
		/* To remove the spaces of the account number */
		acc_n.erase(std::remove_if(acc_n.begin(), acc_n.end(), isspace), acc_n.end());

		bool fileflag = false; /* Flag for checking whether the input account exists or not */
		size_t bytes = 0;
		size_t MAX_FSIZE = user.fileSize(BIN);
	
		/* Searching the account number in record */	
		while(bytes<=MAX_FSIZE) {
			user = read(BIN, user, bytes, std::ios::beg);
			if(user.getAccN() == acc_n) {
				fileflag = true;
				break;
			}
			bytes += sizeof(user);
		}
				
		/* Checking whether the given account data exists or not */
		if(!fileflag) {
			std::cout << std::endl;
			std::cout << "				ACCOUNT NOT FOUND !" << std::endl;
			std::cout << std::endl;
			std::cout << "Press <enter> to continue" << std::endl;
			std::string buff; /* buffer for taking <enter> key press */
			std::getline(std::cin, buff);
			continue;
		}
		
		flag = fileflag; /* Updating the flag with fileflag */

		printf("\e[1;1H\e[2J");
		titleBar();
	
		std::cout << "				A C C O U N T    S T A T U S" << std::endl;
		std::cout << "				 --------------------------" << std::endl << std::endl;
				
		std::cout << "				  Account Holder: " << user.getName() << std::endl;
		std::cout << "				  Account Type: ";
		if(user.getAccT() == 'c') { std::cout << "Current"; }
		else { std::cout << "Saving"; }
		std::cout << std::endl;

		std::cout << "				  Balance Amount: " << user.getBalance() << std::endl << std::endl;

		std::cout << "				 --------------------------" << std::endl << std::endl;

		std::cout << "Press <enter> to exit" << std::endl;
		std::string buff; /* buffer for taking <enter> key press */
		std::getline(std::cin, buff);
		break;
	}

	return flag;
}	

/**
 * ShowAccountHolders Function
 * @brief abstracts and displays the account holders data in a tabular format
 */
void showAccountHolders() {
	size_t bytes = 0; /* To read this much bytes from the records */
	Account user;
	
	printf("\e[1;1H\e[2J");
	titleBar();

	std::cout << "				A C C O U N T    H O L D E R S    L I S T" << std::endl;
	std::cout << "			 	 ---------------------------------------" << std::endl << std::endl;

	std::cout << "			";

	std::cout << std::setfill('-') << std::setw(103);
	std::cout << "" << std::endl;

	std::cout << "				";
	std::cout << std::left << std::setfill(' ') << std::setw(23);
	std::cout << "   Account Number";

	std::cout << "| ";
	
	std::cout << std::left << std::setfill(' ') << std::setw(31);
	std::cout << "        Account Holder";

	std::cout << "| ";

	std::cout << std::left << std::setfill(' ') << std::setw(13);
	std::cout << "Account Type";
	
	std::cout << "| ";

	std::cout << "	Balance" << std::endl;

	std::cout << "			";
	std::cout << std::setfill('-') << std::setw(103);
	std::cout << "" << std::endl;

	std::string acc_n = "";

	while(bytes<user.fileSize(BIN)) {
		user = read(BIN, user, bytes, std::ios::beg);
		acc_n = user.getAccN().substr(0, 4);
		acc_n += " "+user.getAccN().substr(4, 4);
		acc_n += " "+user.getAccN().substr(8, 4);
		acc_n += " "+user.getAccN().substr(12, 4);

		std::cout << "				";
		std::cout << std::left << std::setfill(' ') << std::setw(23);
		std::cout << acc_n;

		std::cout << "| ";

		std::cout << std::left << std::setfill(' ') << std::setw(31);
		std::cout << user.getName();

		std::cout << "| ";

		std::cout << std::left << std::setfill(' ') << std::setw(13);
		if(user.getAccT() == 'c') { std::cout << "Current"; }
		else { std::cout << "Saving"; }

		std::cout << "| ";
		
		std::cout << user.getBalance() << std::endl;

		bytes += sizeof(user);
	}

	std::cout << std::endl << std::endl;
	std::cout << "Press <enter> to exit" << std::endl;
	std::string buff; /* buffer to input <enter> key press */
	std::getline(std::cin, buff);
}
		

/**
 * CloseAccount Function
 * @brief deletes the account from the record
 *
 * @return True if account successfully deleted from the record otherwise False
 */
bool closeAccount() {
	bool tflag = false; /* flag for transfer status */
	bool flag = false; /* flag for <function> status */
	std::string acc_n;
	std::string pin;
	std::string confirm;
	Account user;

	while(true) {
		printf("\e[1;1H\e[2J");
		titleBar();

		std::cout << "				C L O S E    A C C O U N T    M E N U" << std::endl;
		std::cout << "				 -----------------------------------" << std::endl << std::endl;

		std::cout << "			Press <esc + enter> to go back to previous menu" << std::endl << std::endl;

		std::cout << "				Enter the Account Number: ";
		std::getline(std::cin, acc_n);
		if(acc_n.back() == 27) { return false; }
		/* To remove the spaces of the account number */
		acc_n.erase(std::remove_if(acc_n.begin(), acc_n.end(), isspace), acc_n.end());

		std::cout << "				Enter the 4-digit PIN: ";
		std::getline(std::cin, pin);
		/* To remove the spaces of PIN */
		pin.erase(std::remove_if(pin.begin(), pin.end(), isspace), pin.end());
		if(pin.back() == 27) { return false; }
	
		size_t bytes = 0;
		bool found = false; /* flag for checking the account existence in record */
		while(bytes<user.fileSize(BIN)) {
			user = read(BIN, user, bytes, std::ios::beg);
			if(user.getAccN() == acc_n && user.getPin() == pin) {
				found = true;
				break;
			}
			bytes += sizeof(user);
		}
		
		/* Checking whether the given account data exists or not */
		if(!found) {
			std::cout << std::endl;
			std::cout << "				ACCOUNT NOT FOUND !" << std::endl;
			std::cout << std::endl;
			std::cout << "Press <enter> to continue" << std::endl;
			std::string buff; /* buffer for taking <enter> key press */
			std::getline(std::cin, buff);
			continue;
		}
	
		std::cout << std::endl << std::endl;	
		std::cout << "Press <enter> to proceed or <esc + enter> to go back to previous menu" << std::endl;
		std::getline(std::cin, confirm);
		if(confirm.back() == 27) { return false; }

		if(user.getBalance() != 0) {
			printf("\e[1;1H\e[2J");
			titleBar();
			
			std::cout << "				TRANSFER YOUR BALANCE IN YOUR ANOTHER ACCOUNT TO PROCEED" << std::endl << std::endl;
			
			std::cout << "Press <enter> to continue" << std::endl;
			std::string buff;
			std::getline(std::cin, buff);
			
			Account t_user;

			while(true) {
				printf("\e[1;1H\e[2J");
				titleBar();

				std::cout << "				T R A N S F E R    M E N U" << std::endl;
	
				std::cout << "				 ------------------------" << std::endl << std::endl;
				std::cout << std::endl;

				std::cout << "					A C C O U N T    S T A T U S" << std::endl;
				std::cout << "					 --------------------------" << std::endl << std::endl;
				
				std::cout << "				 	   Account Holder: " << user.getName() << std::endl;
				std::cout << "				 	   Account Type: ";
				if(user.getAccT() == 'c') { std::cout << "Current"; }
				else { std::cout << "Saving"; }
				std::cout << std::endl;

				std::cout << "				  	   Balance Amount: " << user.getBalance() << std::endl << std::endl;
				std::cout << "					 --------------------------" << std::endl << std::endl;

				std::cout << "				Enter the Transmittal Account Number: ";
				std::getline(std::cin, acc_n);

				/* To remove the spaces of the account number */
				acc_n.erase(std::remove_if(acc_n.begin(), acc_n.end(), isspace), acc_n.end());

				bool fileflag = false; /* Flag for checking whether the input account exists or not */
				
				std::ifstream file(BIN, std::ios::binary | std::ios::out);
			
				/* Checking if the file stream is opened successfully */
				if(file) {
					while(file.read((char*)&t_user, sizeof(t_user))) {
						/* Comparing the given account data with the existing */
						if(t_user.getAccN() == acc_n) { 
							fileflag = true;
							break;
						}
					}
				}

				else {
					std::cout << std::endl;
					std::cout << "			------------------------------" << std::endl;
					std::cout << "			ERROR: Unable to read the file while checking for account existence" << std::endl;
					std::cout << "			------------------------------" << std::endl;
					std::cout << std::endl;
				}
				
				file.close();

				/* Checking whether the given account data exists or not */
				if(!fileflag) {
					std::cout << std::endl;
					std::cout << "				ACCOUNT NOT FOUND !" << std::endl;
					std::cout << std::endl;
					std::cout << "<Please enter correct transmittal Account Number !>" << std::endl;
					std::string buff; /* buffer for taking <enter> key press */
					std::getline(std::cin, buff);
					continue;
				}

				else if(t_user.getAccN() == user.getAccN()) {
					printf("\e[1;1H\e[2J");
					titleBar();

					std::cout << "				SELF TRANSFER NOT ALLOWED !" << std::endl;
					std::cout << std::endl;

					std::cout << "Press <enter> to continue" << std::endl;
					std::string buff; /* buffer for taking <enter> key press */
					std::getline(std::cin, buff);
					continue;
				}
				
				unsigned long long int amount = user.getBalance();
				user.debit(amount);
				t_user.credit(amount);

				tflag = update(BIN, user);
				tflag = update(BIN, t_user);

				if(tflag) {
					printf("\e[1;1H\e[2J");
					titleBar();
					std::cout << std::endl;	
					std::cout << "				AMOUNT SUCCESSFULLY TRANSFERED" << std::endl << std::endl;
					std::string buff;
					std::cout << "Press <enter> to continue" << std::endl;
					std::getline(std::cin, buff);
				}
				break;
			}
		}

		else { tflag = true; }

		flag = tflag;
		if(flag) { del(BIN, user); }
		printf("\e[1;1H\e[2J");
		titleBar();
		
		/* For checking whether the amount successfull transaction */
		if(flag) {
			std::cout << std::endl;
			std::cout << "				ACCOUNT SUCCESSFULLY CLOSED"; 
		} 
		else {
			std::cout << std::endl;
			std::cout << "				ACCOUNT CLOSING FAILED ! ";
		}

		std::cout << std::endl << std::endl;
		std::cout << "Press <enter> to exit" << std::endl;

		std::string buff; /* buffer for taking the <enter> input*/
		std::getline(std::cin, buff);
		break;
	}

	return flag;
}
