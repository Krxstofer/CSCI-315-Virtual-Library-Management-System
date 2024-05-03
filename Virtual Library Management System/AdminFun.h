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
#include "hash.h"

using namespace std;

Book* addBook(bSearchTreeType<Book>& tree, istream& inStream = cin, bool print = true);
// Function to add a book

bool removeBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, istream& inStream = cin, bool print = true);
// Function to remove a book

void updateBookInfo(bSearchTreeType<Book>& tree, istream& inStream = cin, bool print = true);
// Function to edit book info

void viewAllLoans(linkedQueueType<Book>& );
//function for admin; it displays all books currently borrowed by users
//Postcondition: none

void addOrRemoveUser(HashTable& hash, istream& in_stream = cin, bool display = true);


#endif
