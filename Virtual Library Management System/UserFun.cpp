//Name: Group 2
//Date: 05/04/2024

//UserFun.cpp: implementation file for user functions
#include <iostream>
#include <string>
#include "Book.h"
#include "UserFun.h"
#include "linkedQueue.h"
#include "user.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"

using namespace std;

//PLACE the implementation for your user function here

void searchBook(bSearchTreeType<Book>& tree) // Implement search book functions
{

    string title = "";
    Book searchTemp;

    cin.ignore();
    cout << endl << "Please enter the title you would like to search for." << endl;
    getline(cin, title);
    cout << endl;
    searchTemp.setTitle(title);

    if (tree.search(searchTemp) != nullptr)
    {
        searchTemp = *tree.search(searchTemp);
        cout << "The following was found:" << endl;
        cout << "--------------------------------" << endl;
        cout << searchTemp;
        cout << "--------------------------------" << endl;
    }
    else
    {
        cout << title << " Could not be found in the libary." << endl << endl;
    }
}


void borrowBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, User user) {    // Implement borrow book functions


    string title = "";
    Book searchTemp;

    cin.ignore();
    cout << endl << "What book would you like to borrow ?" << endl;
    getline(cin, title);
    cout << endl;
    searchTemp.setTitle(title);

    if (tree.search(searchTemp) != nullptr)
    {
        searchTemp = *tree.search(searchTemp);
        searchTemp.setBorrower(user.getUsername());
        tree.search(searchTemp)->setBorrower(user.getUsername());
        queue.addQueue(searchTemp);
    }
    else
    {
        cout << title << " Could not be found in the libary." << endl << endl;
    }
}

void returnBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, User user) // Implement return book functions
{
    tree.search(queue.front())->returnBook();
    queue.deleteQueue();
}

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
void updateProfile(User &myUser)
{
    int choice;
    char error[] = "The input stream has invalid data";
    string newName, newPass;

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

	cin >> newPass;
	do
	{
	    cout << "Please re-type your password to confirm: ";
	    cin >> newName;
	}
	while(newPass != newName);
	myUser.setPassword(newName);

	cin >> newName;
	myUser.setPassword(newName);

    }
    //Add user to hash

    cout << "Exiting update profile" << endl;
}
