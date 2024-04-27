//Name: Group 2
//Date: 05/04/2024

//UserFun.cpp: implementation file for user functions
#include <iostream>
#include <string>
#include "Book.h"
#include "UserFun.h"
#include "linkedQueue.h"

using namespace std;

//PLACE the implementation for your user function here

void viewBorrowedBooks(linkedQueueType<Book>& queue, string username)
{
    //printing a queue requires deleting a queue, so a temporary queue is used.
    linkedQueueType<Book> tempQueue = queue;
    Book tempBook;
    string user = username;

    cout << "Here are all of the books you, " << user << ", have borrowed: " << endl;
    while(!tempQueue.isEmptyQueue())
    {
	tempBook = tempQueue.front();
	//every book in the queue is assumed to be borrowed,
	//    so book.borrowed() does not need to be checked.
	if(user == tempBook.getBorrower())
	{
	    cout << tempBook;
	    cout << "Borrowed by: " << tempBook.getBorrower() << endl << endl;
	}
	tempQueue.deleteQueue();
    }
    //If a user has not borrowed any books, no books would be printed.
}
void updateProfile(StandardUser &myUser)
{
    int choice;
    char error[] = "The input stream has invalid data";
    string newName;

    cout << "What user setting would you like to change" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Username" << endl;
    cout << "2. Password" << endl;

    try
    {
	cout << "Please select an option: ";
	cin >> choice;
        if(!cin.good() || (choice < 1 || choice > 2))
	    throw error;
    }
    catch (const char errorStr[])
    {
	cout << errorStr << endl;
	if(!cin.good())
	    cout << "***Cannot accept characters or fractional values.***" << endl;
	else if(choice < 1 || choice > 2)
	    cout << "***Choice must be between 1 and 2.***" << endl;
	cout << "    Clearing out the input stream" << endl;
	cin.clear();
	cin.ignore(200, '\n');
    }
    if(choice == 1)
    {
	cout << "Please enter your new username: ";
	cin >> newName;
	myUser.setUsername(newName);
    }
    else if(choice == 2)
    {
	cout << "Please enter your new password: ";
	cin >> newName;
	myUser.setPassword(newName);
    }
    cout << "Exiting update profile" << endl;
}
