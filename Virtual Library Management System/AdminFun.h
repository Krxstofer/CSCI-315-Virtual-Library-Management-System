//Name: Group 2
//Date: 05/04/2024

#ifndef H_AdminFun
#define H_AdminFun

//adminFun.h: header file for admin functions
#include <iostream>
#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "UserFun.h"
//#include "hash.h" broken

using namespace std;

void addBook(bSearchTreeType<Book>& tree);  
// Function to add a book

void removeBook(bSearchTreeType<Book>& tree);
// Function to remove a book

void updateBookInfo(bSearchTreeType<Book>& tree);  
// Function to edit book info

void viewAllLoans(linkedQueueType<Book>& );
//function for admin; it displays all books currently borrowed by users
//Postcondition: none

//PLACE your admin prototype(s) here
void addOrRemoveUser(/*HashTable& hash*/);


#endif
