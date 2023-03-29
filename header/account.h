#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <ctime>
#include <iostream>

class Account {

private:
	static unsigned short int t_mem; // Total accounts

	int jHrs;
	int jMin;
	int jSec;

	int jDate;
	int jMonth;
	int jYear;
	int jDay;

	unsigned long long int balance = 0;
	char pin[5];

	unsigned long int cst_id; /* Customer ID */
	char acc_n[18] = {0}; /* Account Number */

	char name[30] = {0};
	char address[120] = {0};
	unsigned long int mob; /* Mobile Number */
	char acc_t; /* Account Type */
	unsigned short int dob_d; /* Date of birth */
	unsigned short int dob_m; /* Month of birth */
	unsigned short int dob_y; /* Year of birth */
	
	/**
	 * UpgName Method
	 * @brief increment the data variable t_mem by 1
	 */	
	static void upgMem();	

public:

	/**
	 * DegMem Method
	 * @brief decrement the data variable t_mem by 1
	 */
	static void degMem();

	/**
	 * FileSize Method
	 * @brief to check the total size of the given file in bytes
	 * 
	 * @param fname name of the file
	 *
	 * @return return the number of bytes the file has taken <return-type> is size_t
	 */
	size_t fileSize(const char *fname) ;


	/* ----------------  @Constructor ---------------- */

	/**
	 * Account Constructor
	 * @brief to create the instance of <account-class>, doesnot initializes the data members
	 */
	Account();
	
	/**
	 * Account Overloaded Constructor
	 * @brief creates the instance of <account-class>, initializes the data members
	 *
	 * @param name name of user whose account is going to create
	 * @param address address of the user
	 * @param mobile_no mobile number of the user
	 * @param dob_year year of birth of the user
	 * @param dob_month month of birth of the user
	 * @param dob_date date of birth of the user
	 * @param account_type type of account user wants to create ( current | saving )
	 * @param balance starting amount to starts the user new bank account
	 */
	Account(const std::string name, const std::string address, const unsigned long int mobile_no, const unsigned short int dob_year, const unsigned short int dob_month, const unsigned short int dob_date, const char account_type, const unsigned long long int balance);

	/**
	 * Account Copy Constructor Overload
	 * @brief copies the instance of <account-class> within its another instance
	 *
	 * @param obj <object> of the <account-class>
	 */
	Account(Account &obj);
		
	/* ---------------- @Operators Overloading ------------------ */

	/**
	 * Assignment Operator Overloading
	 * @brief assigns instance within the instance of <account-class>
	 *
	 * @return returns the instance of <account-class>
	 */
	Account& operator=(Account& obj);

	/* ------------------- @Setter Methods ---------------------------- */

	/**
	 * SetName Method
	 * @brief changes the value name
	 *
	 * @param name new name of the user
	 */
	void setName(const std::string name);
	
	/**
 	 * SetAddress Method
	 * @brief changes the address
	 *
	 * @param address new address of the user
	 */
	void setAddress(const std::string address);
	
	/**
	 * SetMob Method
	 * @brief changes the mobile number
	 *
	 * @param mobile_no new mobile number of the user
	 */
	void setMob(const unsigned long int mobile_no);

	/**
	 * SetDob Method
	 * @brief changes the date of birth
	 *
	 * @param dob_year new year of birth of the user
	 * @param dob_month new month of birth of the user
	 * @param dob_date new date of birth of the user
	 */
	void setDob(const unsigned short int dob_year, const unsigned short int dob_month, const unsigned short int dob_date);
	
	/**
	 * SetAccT Method
	 * @brief changes the type of account ( current | saving )
	 *
	 * @param account_type new account type of the user
	 */
	void setAccT(const char account_type);
	
	/**
	 * SetBalance Method
	 * @brief changes the balance of user's bank account
	 *
	 * @param balance new balance of the user
	 */
	void setBalance(const unsigned long long int balance);

	/**
	 * SetPin Method
	 * @brief sets the 4-digit pin for the user's account
	 *
	 * @param pin password for account
	 */
	void setPin(std::string pin);


	/* -------------------- @Overloaded Setter Methods -------------------- */

	/**
	 * SetName Method
	 * @brief changes the value name using std::istream
	 *
	 * @param stream input stream
	 */
	void setName(std::istream &stream);
	
	/**
	 * SetAddress Method
	 * @brief changes the address using std::istream
	 *
	 * @param stream input stream
	 */
	void setAddress(std::istream &stream);
	
	/**
	 * SetMob Method
	 * @brief changes the mobile number using std::istream
	 *
	 * @param stream input stream
	 */
	void setMob(std::istream &stream);

	/**
	 * SetDobY Method
	 * @brief changes the year of birth using std::istream
	 *
	 * @param stream input stream
	 */
	void setDobY(std::istream &stream);

	/**
	 * setDobM Method
	 * @brief changes the month of birth using std::istream
	 *
	 * @param stream input stream
	 */
	void setDobM(std::istream &stream);
	
	/**
	 * SetDobD Method
	 * @brief changes the date of birth using std::istream
	 *
	 * @param stream input stream
	 */
	void setDobD(std::istream &stream);
	
	/**
	 * SetAccT Method
	 * @brief changes the type of account ( current | saving ) using std::istream
	 *
	 * @param stream input stream
	 */
	void setAccT(std::istream &stream);
	
	/**
	 * SetBalance Method
	 * @brief changes the balance of user's bank account using std::istream
	 *
	 * @param stream input stream
	 */
	void setBalance(std::istream &stream);

	/**
	 * SetPin Method
	 * @brief sets the 4-digit pin for the user's account using std::istream
	 *
	 * @param pin password for account
	 */
	void setPin(std::istream &stream);
	

	/* -------------------- @Getter Methods -------------------------- */

	/**
	 * GetName Method
	 * @brief to get the name of the user
	 *
	 * @return returns the name of the user in std::string type
	 */
	std::string getName();
	
	/**
	 * GetAddress Method
	 * @brief to get the address of the user
	 *
	 * @return returns the addresss of ther user in std::string type
	 */
	std::string getAddress();

	/**
	 * GetMob Method
	 * @brief to get the mobile number of the user
	 *
	 * @return returns the mobile number of the user 
	 */
	unsigned long int getMob();

	/**
	 * GetAccT Method
	 * @brief to get the user's account type
	 *
	 * @return returns a character of account type ( 'c' for current | 's' for saving )
	 */
	char getAccT();

	/**
	 * GetBalance Method
	 * @brief to get the current balance in user's account
	 *
	 * @return returns current user balance
	 */
	unsigned long long int getBalance();
	
	/**
	 * GetAccN Mehtod
	 * @brief to get the account number of the user
	 *
	 * @return returns the user's account number of 16 digit long
	 */
	std::string getAccN();

	/**
	 * GetCstId Method
	 * @brief to get the customer id of the user
	 *
	 * @return returns the user customer id of 8 digit long
	 */
	unsigned long int getCstId();

	/**
	 * GetPin Method
	 * @brief to get the pin of the user's account
	 *
	 * @return returns the 4-digit pin
	 */
	std::string getPin();

	/**
	 * GetDobY Method
	 * @brief to get the year of birth of the user
	 *
	 * @return returns the user's birth year
	 */
	unsigned short int getDobY();

	/**
	 * GetDobM Method
	 * @brief to get the month of birth of the user
	 *
	 * @return returns the user's birth month
	 */
	unsigned short int getDobM();

	/**
	 * GetDobD Method
	 * @brief to get the date of birth of the year
	 *
	 * @return returns the user's birth date
	 */
	unsigned short int getDobD();

	/**
	 * GetJHour Method
	 * @brief to get the joined hour when user account created
	 *
	 * @return returns the account's joined hour of the user
	 */
	int getJHour();

	/**
	 * GetJMin Method
	 * @brief to get the joined minutes when user's account created
	 *
	 * @return returns the account's joined minutes of the user
	 */
	int getJMin();

	/**
	 * GetJSec Method
	 * @brief to get the joined seconds when user's account created
	 *
	 * @return returns the account's joined seconds of the user
	 */
	int getJSec();

	/**
	 * GetJYear Method
	 * @brief to get the joined year when user's account created
	 *
	 * @return returns the account's joined year of the user
	 */
	int getJYear();

	/**
	 * GetJDate Method
	 * @brief to get the joined date when user's account created
	 *
	 * @return returns the account's joined date of the user
	 */
	int getJDate();

	/**
	 * GetJMonth Method
	 * @brief to get the joined month when user's account created
	 *
	 * @return returns the account's joined month of the user
	 */
	int getJMonth();

	/**
	 * GetJDay Method
	 * @brief to get the joined day when user's account created
	 *
	 * @return returns the respective integer values of the day { "sunday" = 0, "monday" = 1, "tuesday" = 2, "wednesday" = 3,	"thursday" = 4, "friday" = 5, "saturday" = 6 }
	 */
	int getJDay();

	/**
	 * GetKey Method
	 * @brief to get the unique identification of the user's account
	 *
	 * @return returns the user's customer id
	 */	
	unsigned long int getKey();

	/**
	 * GetTotalAcc Method
	 * @brief To get value of data variable t_mem
	 *
	 * @return returns the total account objects created
	 */	
	static unsigned short int getTotalAcc();


	/* --------------- @Methods -------------------- */

	/**
	 * GenerateAccNo Method
 	 * @brief generate the account number of 16 digits
 	 */
	void generateAccNo();

	/**
	 * GenerateCstId Method
	 * @brief generate the customer id of 8 digits
	 */
	void generateCstId();
	
	/**
	 * Credit Method
	 * @brief credit the amount into the account
	 *
	 * @param amount amount to be credit
	 */
	void credit(const unsigned long long int amount);

	/**
	 * Credit Method
	 * @brief credit the amount into the account using std::istream
	 *
	 * @param amount amount to be credit
	 */
	void credit(std::istream &stream);

	/* ------------------- @Overloaded Methods ------------------ */
	
	/**
	 * Debit Method
	 * @brief debit the amount from the account
	 *
	 * @param amount amount to be debit
	 */
	void debit(const unsigned long long int amount);

	/**
	 * Debit Method
	 * @brief debit the amount from the account using std::istream
	 *
	 * @param amount amount to be debit
	 */
	void debit(std::istream &stream);

	/**
	 * Assign Method
	 * @brief updates the data members except the joining data, account number and customer id
	 *
	 * @param obj reference <object> of who's data is assigned
	 */
	void assign(Account &obj);

};

#endif
