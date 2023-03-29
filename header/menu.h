#ifndef MENU_H
#define MENU_H

/**
 * IntroScreen Function
 * @brief the introduction screen of the program
 */
void introScreen();

/**
 * MainMenu Function
 * @brief main menu of program in which you can perform the following options:
 *		 [1] New Account
 *		 [2] Deposite Amount
 *		 [3] Withdraw Amount
 *		 [4] Transfer Amount
 *		 [5] Balance Enquiry
 *		 [6] All Account Holder List
 *		 [7] Close An Account
 *		 [8] Modify An Account
 *		 [9] EXIT
 *
 * @return returns the option number which gets selected
 */
int mainMenu();

#endif
