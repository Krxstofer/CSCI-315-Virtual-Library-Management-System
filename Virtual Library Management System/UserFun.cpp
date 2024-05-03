//Name: Group 2
//Date: 05/04/2024

//UserFun.cpp: implementation file for user functions
#include <iostream>
#include <string>
#include "Book.h"
#include "UserFun.h"
#include "linkedQueue.h"
#include "user.h"
#include "hash.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "nullBuffer.h"

using namespace std;


bool searchBook(bSearchTreeType<Book>& tree, istream& inStream, bool print) // Implement search book functions
{
    NullBuffer nullBuffer;
    ostream nullStream(&nullBuffer);
    ostream& outStream = print ? cout : nullStream;

    string title;
    Book searchTemp;
    cin.ignore();
    outStream << endl << "Please enter the title you would like to search for." << endl;
    getline(inStream, title);
    outStream << endl;
    searchTemp.setTitle(title);

    if (tree.search(searchTemp) != nullptr)
    {
        searchTemp = *tree.search(searchTemp);
        outStream << "The following was found:" << endl;
        outStream << "--------------------------------" << endl;
        outStream << searchTemp;
        outStream << "--------------------------------" << endl;
        return true;
    }
    else
    {
        outStream << title << " Could not be found in the libary." << endl << endl;
        return false;
    }
}

// Implement borrow book functions
bool borrowBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, User user, istream& inStream, bool print)
{
    NullBuffer nullBuffer;
    ostream nullStream(&nullBuffer);
    ostream& outStream = print ? cout : nullStream;

    string title;
    Book searchTemp;

    cin.ignore();
    outStream << endl << "What book would you like to borrow ?" << endl;
    getline(inStream, title);
    outStream << endl;
    searchTemp.setTitle(title);

    if (tree.search(searchTemp) != nullptr)
    {
        searchTemp = *tree.search(searchTemp);
        if (!searchTemp.getBorrowed())
        {
            searchTemp.setBorrower(user.getUsername());
            tree.search(searchTemp)->setBorrower(user.getUsername());
            queue.addQueue(searchTemp);
            outStream << "You have borrowed:" << endl;
            outStream << "--------------------------------" << endl;
            outStream << searchTemp;
            outStream << "--------------------------------" << endl;
            return true;
        }
        else
        {
            outStream << title << " is already borrowed by another user." << endl << endl;
            return false;
        }
    }
    else
    {
        outStream << title << " Could not be found in the libary." << endl << endl;
        return false;
    }
}

void returnBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, User user, bool print) // Implement return book functions
{
    NullBuffer nullBuffer;
    ostream nullStream(&nullBuffer);
    ostream& outStream = print ? cout : nullStream;

    if (!queue.isEmptyQueue())
    {
        if (user.getUsername() == queue.front().getBorrower())
        {
            tree.search(queue.front().getTitle())->returnBook();
            outStream << "Returned:" << endl;
            outStream << "--------------------------------" << endl;
            outStream << *tree.search(queue.front().getTitle());
            outStream << "--------------------------------" << endl;
            queue.deleteQueue();
        }
        else
        {
            outStream << endl << "Only the borrower of the first book in the queue may return it. Return Canceled" << endl << endl;
        }
    }
    else
    {
        outStream << "There are no books to return." << endl << endl;
    }
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
void updateProfile(HashTable userHash, User& myUser, istream& inStream, bool display)
{
    int choice, max = 3;
    char error[] = "The input stream has invalid data";
    string newName, newPass;

    cout << "What user setting would you like to change" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Username" << endl;
    cout << "2. Password" << endl;
    cout << "3. Return to User Menu" << endl;

    try
    {
	cout << "Please select an option: ";
	inStream >> choice;
        if(!inStream.good() || (choice < 1 || choice > 3))
	    throw error;
    }
    catch (const char errorStr[])
    {
	cout << errorStr << endl;
	if(!inStream.good())
	    cout << "***Cannot accept characters or fractional values.***" << endl;
	else if(choice < 1 || choice > 2)
	    cout << "***Choice must be between 1 and 2.***" << endl;
	cout << "    Clearing out the input stream" << endl;
	inStream.clear();
	inStream.ignore(200, '\n');
    }
    if(choice == 1)
    {
	cout << "Please enter your new username: ";
	inStream >> newName;
	if((!userHash.isEmpty()) && 1) //remove old user if it exists.
	    userHash.removeUser(myUser.getUsername());
	myUser.setUsername(newName);
	userHash.insertUser(myUser);
    }
    else if(choice == 2)
    {
	cout << "Please enter your new password: ";

	inStream >> newPass;
	do
	{
	    cout << "Please re-type your password to confirm: ";
	    inStream >> newName;
	}
	while(newPass != newName && --max);
	if(max > 0)
	{
	    if((!userHash.isEmpty()) && 1) //remove old user if it exists.
		userHash.removeUser(myUser.getUsername());
	    myUser.setPassword(newName);
	    userHash.insertUser(myUser);
	    cout << endl << "***Password was succesfully changed***" << endl;
	    cout << "Returning to user menu" << endl;
	}
	else if(max <= 0)
	{
	    cout << endl << "***Maximum number of attempts exceeded***" << endl;
	    cout << "Password was not changed; returning to user menu" << endl;
	}
    }
    else if(choice == 3)
    {
	cout << "***Exiting update profile***" << endl;
    }
}
