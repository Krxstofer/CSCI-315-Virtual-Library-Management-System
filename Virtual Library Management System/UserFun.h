//Name: Group 2
//Date: 05/04/2024

#ifndef H_UserFun
#define H_UserFun
//userFun.h: header file for user functions

#include <iostream>
#include <string>
#include "Book.h"
#include "linkedQueue.h"

using namespace std;


void viewBorrowedBooks(linkedQueueType<Book>&, string username);
//function for users; it displays all books borrowed by that user
//Postcondition: None

void updateProfile(/*StandardUser&*/ );
//function for users; it allows users limited control to update their profile settings
//Postcondition: if the correct input is provided, it changes the username or password
//	based on the user's choice. If the input is incorrect, the postcondition is none.

//PLACE your user prototype(s) here.

#endif
