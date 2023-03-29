#ifndef TASK_H
#define TASK_H

/**
 * TitleBar Function
 * @brief displays the title of the program on the console
 */
void titleBar();

/**
 * CreateNewAccount Function
 * @brief updates the records
 *
 * @param action 1 for creation of new account and other for account updation
 *
 * @return returns boolean true if the records successfully updated else boolean false
 */
bool updateRecord(const int action);

/**
 * TransactionMenu Function
 * @brief to credit/debit the amount into/from the account
 *
 * @param action 1 for depositing, 2 for withdrawing and others for transfer
 * 
 * @return returns boolean true if amount successfully credited/debited otherwise boolean false
 */
bool transactionMenu(const int action);

/**
 * BalanceEnquiry Function
 * @brief displays the current balance status of the account
 *
 * @return True if displayed successfully else False
 */
bool balanceEnquiry();

/**
 * ShowAccountHolders Function
 * @brief abstract and displays the account holders data in a tabular format
 */
void showAccountHolders();

/**
 * CloseAccount Function
 * @brief deletes the account from the record
 *
 * @return True if the account successfully deleted from the record otherwise False
 */
bool closeAccount();

#endif
