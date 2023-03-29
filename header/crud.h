#ifndef CRUD_H
#define CRUD_H

#include <iostream>
#include <fstream>
#include "account.h"

/* CRUD {create, read, update, delete} */

/**
* Create Function
* @brief creates the file if not exists otherwise write the data into the file
*
* @param fname file name to be created
* @param obj <object> to be written in the file
*
* @return returns boolean true if file successfully written else boolean false
*/
bool create(const char *fname, Account &obj);

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
Account& read(const char *fname, Account &obj, std::streamoff offset, std::ios_base::seekdir dir);

/**
* Update Function
* @brief updates the file data
*
* @param fname file name to be updated
* @param obj <object> to be appended in the file ( assuming the content have a getKey() method defined in it )
*
* @return returns boolean true if the file is updated successfully else boolean false
*/
bool update(const char *fname, Account &obj);

/**
* Del Function
* @brief deletes the bytes of data from the file
*
* @param fname file name from which the data to be deleted
* @param obj <object> to be deleted from the file
*/
void del(const char *fname, Account &obj);

#endif
