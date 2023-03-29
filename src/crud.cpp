#include <iostream>
#include <fstream>
#include <filesystem> /* For checking the existence of the file */
#include <stdio.h>
#include "../header/crud.h"
#include "../header/account.h"

/**
 * Create Function
 * @brief creates the file if not exists otherwise write the data into the file
 *
 * @param fname file name to be created
 * @param obj <object> to be written in the file
 *
 * @return return boolean true if file successfully written else boolean false
 */
bool create(const char *fname, Account &obj) {
	std::ofstream file(fname, std::ios::binary | std::ios::app);
	if (file.fail()) { 
		file.close();
		return false;
	}
	file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
	file.close();

	/* Checking whether the file closed without any error or not */
	if(!file.good()) {
		std::cout << "ERROR: facing issue while creating the " << fname << " file" << std::endl;
	}
	return true;
}


/**
 * Read function
 * @brief reads the data from the file according to the given offset with respect to the dir
 *
 * @param fname file name to be read
 * @param obj <object> to be written in from the file
 * @param offset amounts of bytes moved with respect to the 'dir'
 * @param dir position of the file pointer ( ios_base::beg, ios_base::end, ios_base::cur)
 *
 * @return instance of <account-class>
 */
Account& read(const char *fname, Account &obj, std::streamoff offset, std::ios_base::seekdir dir) {
	/* Checking the existence of the file */
	if(!std::filesystem::exists(fname)) {
		std::cout << "Error: no such file or directory: ";
		std::cout << fname <<std::endl;
		return obj; 
	}

	std::ifstream file(fname, std::ios::binary | std::ios::out);
	
	/* Checking whether the file stream opened successfully or not */
	if(file) {
		/* Setting the file pointer to the offset with respect to the dir */
		file.seekg(offset, dir);
		if(!file.eof()) {
			file.read(reinterpret_cast<char*>(&obj), sizeof(obj));
		}
	}
	else {
		std::cout << "ERROR: facing issue while reading the file " << fname << " file" << std::endl;
	}

	file.close();

	return obj;
}


/**
 * Update Function
 * @brief updates the file data
 *
 * @param fname file name to be updated
 * @param obj <object> to be appended in the file ( assuming the content have a getKey() method defined in it )
 *
 * @return returns boolean true if the file is updated successfully else boolean false
 */
bool update(const char *fname, Account &obj) {
	/* Flag for whether a file is updated successfully or not */
	bool flag = false;
	
	/* Checking the file existence */	
	if(!std::filesystem::exists(fname)) {
	    std::cout << "Error: no such file or directory: ";
		std::cout << fname << std::endl;	
		return flag; 
	}

	std::fstream file(fname, std::ios::in | std::ios::out | std::ios::binary);
	Account tempObj;
	
	/* Checking the file stream successfully opened or not */
	if(file) {
		/* Parsing the file with respect to the getkey() method defined in <object> */
		while(file.read(reinterpret_cast<char*>(&tempObj), sizeof(tempObj))) {
			if(tempObj.getKey() == obj.getKey()) {
				flag = true;
				tempObj.assign(obj);
				file.seekp(file.tellg() - static_cast<long int>(sizeof(tempObj)), std::ios::beg);
				file.write(reinterpret_cast<char*>(&tempObj), sizeof(tempObj));
				break;
			}
		}
	}
	else {
		std::cout << "ERROR: facing issue while updating the file " << fname << " file" << std::endl;
	}

	file.close();

	return flag;
}


/**
 * Del Function
 * @brief deletes the bytes of data from the file
 *
 * @param fname file name from which the data to be deleted
 * @param obj <object> to be deleted from the file
 */
void del(const char *fname, Account &obj) {
	/* Checking the file existence */
	if(!std::filesystem::exists(fname)) {
		std::cout << "Error: no such file or directory: ";
		std::cout << fname << std::endl;
		return;
	}

	std::ifstream file(fname, std::ios::binary | std::ios::out);
	std::string t_path = fname;
	t_path = t_path + ".swp";
	std::ofstream t_file(t_path, std::ios::binary | std::ios::app);
	Account tempObj;

	/* Checking if the file stream opened successfully or not */
	if(file) {
		/* Parsing the file with respect to getKey() method defined in the <object> */
		while(file.read(reinterpret_cast<char*>(&tempObj), sizeof(tempObj))) {
			if(tempObj.getKey() != obj.getKey()) {
				t_file.write(reinterpret_cast<char*>(&tempObj), sizeof(tempObj));
			}

			else { tempObj.degMem(); }
		}
	}

	else {
		std::cout << "ERROR: facing issue while deleting the file element " << fname << " file" << std::endl;
	}

	file.close();
	t_file.close();
	
	remove(fname);
	rename(t_path.c_str(), fname);
}
