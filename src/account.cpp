#include <iostream>
#include <boost/algorithm/string.hpp>
#include <cstring>
#include <string>
#include <filesystem>
#include <fstream>
#include "../header/account.h"

#define BIN "record.bin"


/* Default object of <account-class> to control those functions which are not allowed to be called using <class-name> */
Account DOBJ;

/**
 * fileSize Method
 * @brief to check the total size of the given file in bytes
 *
 * @param fname name of the file
 *
 * @return returns the number of bytes the file has taken <return-type> is size_t
 */
size_t Account::fileSize(const char *fname) {
	if(!std::filesystem::exists(BIN)) {
		std::ofstream file(BIN, std::ios::binary);
		file.close();
	}

	size_t bytes;
	std::ifstream file(fname, std::ios::binary | std::ios::in | std::ios::ate);
	bytes = file.tellg();
	file.close();
	if(!file.good()) {
			std::cout << "ERROR: facing issue while checking the 'total members'" << std::endl;
	}

	return bytes;
}

/* Reinitializing the number of total accounts created */
unsigned short int Account::t_mem = DOBJ.fileSize(BIN)/sizeof(Account);


/**
 * UpgName Method
 * @brief increment the data variable t_mem by 1
 */
void Account::upgMem() {
	Account::t_mem++;
}

/**
 * DegMem Method
 * @brief decrement the data variable t_mem by 1
 */
void Account::degMem() {
	Account::t_mem--;
}


/**
 * GetTotalAcc Method
 * @brief To get value of data variable t_mem
 *
 * @return returns the total account objects created
 */
unsigned short int Account::getTotalAcc() {
	return Account::t_mem;
}

/* ----------------  @Constructor ---------------- */

/**
 * Account Constructor
 * @brief to create the instance of the object, doesnot initializes the data members
 */
Account::Account() {
	time_t ttime = time(0);
	tm *localTime = localtime(&ttime);
	
	this->jHrs = localTime->tm_hour;
	this->jMin = localTime->tm_min;
	this->jSec = localTime->tm_sec;

	this->jDate = localTime->tm_mday;
	this->jMonth = localTime->tm_mon+1;
	this->jYear = localTime->tm_year+1900;
	this->jDay = localTime->tm_wday;

	localTime = nullptr;
};


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
Account::Account(const std::string name, const std::string address, const unsigned long int mobile_no, const unsigned short int dob_year, const unsigned short int dob_month, const unsigned short int dob_date, const char account_type, const unsigned long long int balance) {
	
	std::string _n = name;
	boost::algorithm::trim(_n);
	std::string _addr = address;
	boost::algorithm::trim(_addr);

	strncpy(this->name, _n.c_str(), sizeof(this->name));
	strncpy(this->address, _addr.c_str(), sizeof(this->address));
	this->mob = mobile_no;
	this->dob_y = dob_year;
	this->dob_m = dob_month;
	this->dob_d = dob_date;
	this->acc_t = account_type;
	this->balance = balance;

	time_t ttime = time(0);
	tm *localTime = localtime(&ttime);
	
	this->jHrs = localTime->tm_hour;
	this->jMin = localTime->tm_min;
	this->jSec = localTime->tm_sec;

	this->jDate = localTime->tm_mday;
	this->jMonth = localTime->tm_mon+1;
	this->jYear = localTime->tm_year+1900;
	this->jDay = localTime->tm_wday;

	localTime = nullptr;

	this->generateAccNo();
	this->generateCstId();
}

/**
 * Account Copy Constructor Overload
 * @brief copies the instance of <account-class> within its another instance
 *
 * @param obj <object> of the <account-class>
 */
Account::Account(Account &obj) {
	*this = obj;
}


/* ---------------- @Operators Overloading ------------------ */

/**
 * Assignment Operator Overloading 
 * @brief assgins instance within the instance of <account-class>
 *
 * @return returns the instance of <account-class>
 */
Account& Account::operator=(Account& obj) {
	this->balance = obj.balance;
	this->cst_id = obj.cst_id;
	strcpy(this->acc_n, obj.acc_n);

	strcpy(this->name, obj.name);
	strcpy(this->address, obj.address);
	strcpy(this->pin, obj.pin);
	this->mob = obj.mob;
	this->acc_t = obj.acc_t;
	this->dob_d = obj.dob_d;
	this->dob_m = obj.dob_m;
	this->dob_y = obj.dob_y;

	this->jHrs = obj.jHrs;
	this->jMin = obj.jMin;
	this->jSec = obj.jSec;
	this->jDate = obj.jDate;
	this->jMonth = obj.jMonth;
	this->jYear = obj.jYear;
	this->jDay = obj.jDay;

	return *this;
}

/* ------------------- @Setter Methods ---------------------------- */

/**
 * SetName Method
 * @brief changes the value name
 *
 * @param name new name of the user
 */
void Account::setName(const std::string name) {
	std::string _n = name;
	boost::algorithm::trim(_n); 
	strncpy(this->name, _n.c_str(), sizeof(this->name));
	this->name[29] = 0;
}

/**
 * SetAddress Method
 * @brief changes the address
 *
 * @param address new address of the user
 */
void Account::setAddress(const std::string address) {
	std::string _addr = address;
	boost::algorithm::trim(_addr);
	strncpy(this->address, _addr.c_str(), sizeof(this->address));
	this->address[119] = 0;
}

/**
 * SetMob Method
 * @brief changes the mobile number
 *
 * @param mobile_no new mobile number of the user
 */
void Account::setMob(const unsigned long int mobile_no) {
	this->mob = mobile_no;
}

/**
 * SetDob Method
 * @brief changes the date of birth
 *
 * @param dob_year new year of birth of the user
 * @param dob_month new month of birth of the user
 * @param dob_date new date of birth of the user
 */
void Account::setDob(const unsigned short int dob_year, const unsigned short int dob_month, const unsigned short int dob_date) {
	this->dob_y = dob_year;
	this->dob_m = dob_month;
	this->dob_d = dob_date;
}

/**
 * SetAccT Method
 * @brief changes the type of account ( current | saving )
 *
 * @param account_type new account type of the user
 */
void Account::setAccT(const char account_type) {
	this->acc_t = account_type;
}

/**
 * SetBalance Method
 * @brief changes the balance of user's bank account
 *
 * @param balance new balance of the user
 */
void Account::setBalance(const unsigned long long int balance) {
	this->balance = balance;
}

/**
 * SetPin Method
 * @brief sets the 4-digit pin for the user's account using std::istream
 *
 * @param pin password for account
 */
void Account::setPin(std::string pin) {
	strncpy(this->pin, pin.c_str(), sizeof(this->pin));
}
	

/* -------------------- @Overloaded Setter Methods --------------- */

/**
 * SetName Method
 * @brief changes the value name using std::istream
 *
 * @param stream input stream
 */
void Account::setName(std::istream &stream) {
	std::string _name;
	std::getline(stream, _name);
	this->setName(_name);
}

/**
 * SetAddress Method
 * @brief changes the address using std::istream
 *
 * @param stream input stream
 */
void Account::setAddress(std::istream &stream) {
	std::string _address;
	std::getline(stream, _address);
	this->setAddress(_address);
}

/**
 * SetMob Method
 * @brief changes the mobile number using std::istream
 *
 * @param stream input stream
 */
void Account::setMob(std::istream &stream) {
	stream >> this->mob;
}

/**
 * SetDobY Method
 * @brief changes the year of birth using std::istream
 *
 * @param stream input stream
 */
void Account::setDobY(std::istream &stream) {
	stream >> this->dob_y;
}

/**
 * SetDobM Method
 * @brief changes the month of birth using std::istream
 *
 * @param stream input stream
 */
void Account::setDobM(std::istream &stream) {
	stream >> this->dob_m;
}

/**
 * SetDobD Method
 * @brief changes the date of birth using std::istream
 *
 * @param stream input stream
 */
void Account::setDobD(std::istream &stream) {
	stream >> this->dob_d;
}

/**
 * SetAccT Method
 * @brief changes the type of account ( current | saving ) using std::istream
 *
 * @param stream input stream
 */
void Account::setAccT(std::istream &stream) {
	stream >> this->acc_t;
}

/**
 * SetBalance Method
 * @brief changes the balance of the user's bank account using std::istream
 *
 * @param stream input stream
 */
void Account::setBalance(std::istream &stream) {
	stream >> this->balance;
}

/**
 * SetPin Method
 * @brief sets the 4-digit pin for the user's account using std::istream
 *
 * @param pin password for account
 */
void Account::setPin(std::istream &stream) {
	std::string _pin;
	stream >> _pin;
	strncpy(this->pin, _pin.c_str(), sizeof(this->pin));
}
	


/* -------------------- @Getter Methods -------------------------- */

/**
 * GetName Method
 * @brief to get the name of the user
 *
 * @return returns the name of the user in std::string type
 */
std::string Account::getName() {
	std::string __name(this->name);
	return __name;
}

/**
 * GetAddress Method
 * @brief to get the address of the user
 *
 * @return returns the addresss of ther user in std::string type
 */
std::string Account::getAddress() {
	std::string __address(this->address);
	return __address;
}

/**
 * GetMob Method
 * @brief to get the mobile number of the user
 *
 * @return returns the mobile number of the user 
 */
unsigned long int Account::getMob() {
	return this->mob;
}

/**
 * GetAccT Method
 * @brief to get the user's account type
 *
 * @return returns a character of account type ( 'c' for current | 's' for saving )
 */
char Account::getAccT() {
	return this->acc_t;
}

/**
 * GetBalance Method
 * @brief to get the current balance in user's account
 *
 * @return returns current user balance
 */
unsigned long long int Account::getBalance() {
	return this->balance;
}

/**
 * GetAccN Mehtod
 * @brief to get the account number of the user
 *
 * @return returns the user's account number of 16 digit long
 */
std::string Account::getAccN() {
	std::string _acc_n(this->acc_n);
	return _acc_n;
}

/**
 * GetCstId Method
 * @brief to get the customer id of the user
 *
 * @return returns the user customer id of 8 digit long
 */
unsigned long int Account::getCstId() {
	return this->cst_id;
}

/**
 * GetPin Method
 * @brief to get the pin of the user's account
 *
 * @return returns the 4-digit pin
 */
std::string Account::getPin() {
	std::string _pin(this->pin);
	return _pin;
}

/**
 * GetDobY Method
 * @brief to get the year of birth of the user
 *
 * @return returns the user's birth year
 */
unsigned short int Account::getDobY() {
	return this->dob_y;
}

/**
 * GetDobM Method
 * @brief to get the month of birth of the user
 *
 * @return returns the user's birth month
 */
unsigned short int Account::getDobM() {
	return this->dob_m;
}

/**
 * GetDobD Method
 * @brief to get the date of birth of the year
 *
 * @return returns the user's birth date
 */
unsigned short int Account::getDobD() {
	return this->dob_d;
}

/**
 * GetJHour Method
 * @brief to get the joined hour when user account created
 *
 * @return returns the account's joined hour of the user
 */
int Account::getJHour() {
	return this->jHrs;
}

/**
 * GetJMin Method
 * @brief to get the joined minutes when user's account created
 *
 * @return returns the account's joined minutes of the user
 */
int Account::getJMin() {
	return this->jMin;
}

/**
 * GetJSec Method
 * @brief to get the joined seconds when user's account created
 *
 * @return returns the account's joined seconds of the user
 */
int Account::getJSec() {
	return this->jSec;
}

/**
 * GetJYear Method
 * @brief to get the joined year when user's account created
 *
 * @return returns the account's joined year of the user
 */
int Account::getJYear() {
	return this->jYear;
}

/**
 * GetJDate Method
 * @brief to get the joined date when user's account created
 *
 * @return returns the account's joined date of the user
 */
int Account::getJDate() {
	return this->jDate;
}

/**
 * GetJMonth Method
 * @brief to get the joined month when user's account created
 *
 * @return returns the account's joined month of the user
 */
int Account::getJMonth() {
	return this->jMonth;
}

/**
 * GetJDay Method
 * @brief to get the joined day when user's account created
 *
 * @return returns the respective integer values of the day { "sunday" = 0, "monday" = 1, "tuesday" = 2, "wednesday" = 3, "thursday" = 4, "friday" = 5, "saturday" = 6 }
 */
int Account::getJDay() {
	return this->jDay;
}

/**
 * GetKey Method
 * @brief to get the unique identification of the user's account
 *
 * @return returns the user's customer id
 */
unsigned long int Account::getKey() {
	return this->cst_id;
}

/* --------------- @Methods -------------------- */

/**
 * GenerateAccNo Method
 * @brief generate the account number of 16 digits
 */
void Account::generateAccNo() {
	this->upgMem();
	std::string acc_n;
	acc_n = std::to_string(this->getJYear());
	acc_n +=std::to_string((10000000+Account::t_mem)+ ((this->getJHour()+this->getJMin())*1000000));
	acc_n += std::to_string(this->getJHour()%10) + std::to_string(this->getJMin()%10) + std::to_string(this->getJSec()%10) + std::to_string(this->getJDay());
	strncpy(this->acc_n, acc_n.c_str(), sizeof(this->acc_n));
	this->acc_n[17] = 0;
}

/**
 * GenerateCstId Method
 * @brief generate the customer id of 8 digits
 */
void Account::generateCstId() {
	this->cst_id = this->getJYear() * 10000;
	this->cst_id += this->getJHour() + this->getJMin() + this->getJSec() + Account::t_mem;
}

/**
 * Credit Method
 * @brief credit the amount into the account
 * 
 * @param amount amount to be credit
 */
void Account::credit(const unsigned long long int amount) { this->balance += amount; }

/**
 * Debit Method
 * @brief debit the amount from the account
 * 
 * @param amount amount to be debit
 */
void Account::debit(const unsigned long long int amount) { this->balance -= amount; }


/**
 * Credit Method
 * @brief credit the amount into the account using std::istream
 * 
 * @param amount amount to be credit
 */
void Account::credit(std::istream &stream) { 
	unsigned long long int amount;
	stream >> amount;
	this->balance += amount; 
}

/**
 * Debit Method
 * @brief debit the amount from the account using std::istream
 * 
 * @param amount amount to be debit
 */
void Account::debit(std::istream &stream) {
	unsigned long long int amount;
	stream >> amount;
	this->balance -= amount; 
}

/**
 * Assign Method
 * @brief updates the data members except the joining data, account number and customer id
 *
 * @param obj reference <object> of who's data is assigned
 */
void Account::assign(Account &obj) {
	this->balance = obj.balance;
	strcpy(this->name, obj.name);
	strcpy(this->address, obj.address);
	strcpy(this->pin, obj.pin);
	this->mob = obj.mob;
	this->acc_t = obj.acc_t;
	this->dob_d = obj.dob_d;
	this->dob_m = obj.dob_m;
	this->dob_y = obj.dob_y;
}
