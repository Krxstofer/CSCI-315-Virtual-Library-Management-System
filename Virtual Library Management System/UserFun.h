//Name: Group 2
//Date: 05/04/2024

#ifndef H_UserFun
#define H_UserFun
//userFun.h: header file for user functions

#include <iostream>
#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "user.h"

using namespace std;


bool searchBook(bSearchTreeType<Book>& tree, istream& inStream = cin, bool print = true);
//funciton to search for a book, and prints the book's information if found

bool borrowBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, User user, istream& inStream = cin, bool print = true);
//function for a user to borrow a book

void returnBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, User user, bool print = true);
//function to return the oldest book in the borrowed queue

void viewBorrowedBooks(linkedQueueType<Book>&, string username);
//function for users; it displays all books borrowed by that user
//Postcondition: None

void updateProfile(User&);
//function for users; it allows users limited control to update their profile settings
//Postcondition: if the correct input is provided, it changes the username or password
//	based on the user's choice. If the input is incorrect, the postcondition is none.

//PLACE your user prototype(s) here.

#endif
