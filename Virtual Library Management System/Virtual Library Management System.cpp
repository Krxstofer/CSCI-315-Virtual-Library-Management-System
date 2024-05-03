//Name: Group 2
//Description: Week 8 CSCI Group Project
//Date: May 4, 2024

// Virtual Library Management System Project.cpp :
// This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "LoadSave.h"
#include "UserFun.h"
#include "AdminFun.h"
#include "GeneralFunctions.h"
#include "user.h"
#include "hash.h"

//tOut is a global in LoadSave since the binary tree's inorderTraversal() with a function
//parameter only takes one parameter and out must be opened outside of
//saveTree (where it is used) since it is recurisive and thus called multiple times

using namespace std;

// Function prototypes
void preLoginMenu();

//User functions
void userMenu(ifstream& qIn, linkedQueueType<Book> borrowedBooks, ifstream& tIn, 
	bSearchTreeType<Book> bookCatalog, User& user, HashTable userDatabase); //made user not constant because updateProfile needs to change user

//Admin functions
void adminMenu(ifstream& qIn, linkedQueueType<Book> borrowedBooks, ifstream& tIn, 
	bSearchTreeType<Book> bookCatalog, User& admin, HashTable userDatabase); //added admin object as a parameter


int main() {

    preLoginMenu();

    return 0;
}

void preLoginMenu() {

    //setup
    ifstream qIn, tIn;
    HashTable userDatabase;
    linkedQueueType<Book> borrowedBooks;
    bSearchTreeType<Book> bookCatalog;
    User user("","","user"), admin("","","admin");
    char c;

    //loading queue
    qIn.open("Borrowed.txt"); //storage file for borrowed books
    qIn.get(c); //detect eof in existing, empty file
    if(!qIn)
    {
      cout << "Borrowed books file not found! Shutting down." << endl;
      exit(1);
    }
    loadQueue(qIn, borrowedBooks);

    //loading tree
    tIn.open("Library.txt"); //storage file for all books
    tIn.get(c); //detect eof in exisitng empty file
    if(!tIn)
    {
      cout << "Library file not found, or the file is empty! Shutting down." << endl;
      exit(1);
    }
    loadTree(tIn, bookCatalog);
    //setup

    int choice;
    cout << "Welcome to the Virtual Library Management System" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Please select an option: ";
    cin >> choice;

    switch (choice) {
    case 1:
        // Implemenet Login functionality
	userMenu(qIn, borrowedBooks, tIn, bookCatalog, user, userDatabase); //for testing
	//adminMenu(qIn, borrowedBooks, tIn, bookCatalog, admin, userDatabase); //for testing
        break;
    case 2:
        if(registerUser(userDatabase, user))//if registration succeeds proceed to the user menu
	//(only users register here, admins register in addRemoveAdmin for security)
	//user's credentials are set by register for use in userMenu below
        {

	  userMenu(qIn, borrowedBooks, tIn, bookCatalog, user, userDatabase);

	}
	//if registration did not succeed fall through and exit
        //no break
    case 3:
        cout << "Exiting program..." << endl;
        exit(0);
    default:
        cout << "Invalid choice. Please try again." << endl;
        preLoginMenu();
    }
}

void userMenu(ifstream& qIn, linkedQueueType<Book> borrowedBooks, ifstream& tIn, 
	bSearchTreeType<Book> bookCatalog, User& user, HashTable userDatabase) {
    
    cout << "Welcome " << user.getUsername() << " Thanks for using our Virtual Library!" << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Search for Books" << endl;
    cout << "2. Borrow a Book" << endl;
    cout << "3. Return a Book" << endl;
    cout << "4. View Borrowed Books" << endl;
    cout << "5. Update Profile" << endl;
    cout << "6. Logout" << endl;
    cout << "Please select an option: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        searchBook(bookCatalog);
        break;
    case 2:
        borrowBook(bookCatalog, borrowedBooks, user);
        break;
    case 3:
        returnBook(bookCatalog, borrowedBooks, user);
        break;
    case 4:
        viewBorrowedBooks(borrowedBooks, user.getUsername());
        break;
    case 5:
        updateProfile(user);
        break;
    case 6:
	cout << "Logging out..." << endl; //Kristofer
        logout(qIn, "Borrowed.txt", tIn, "Library.txt", borrowedBooks, bookCatalog);
	preLoginMenu();
	break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
    if(choice != 6)
	userMenu(qIn, borrowedBooks, tIn, bookCatalog, user, userDatabase);
}


void adminMenu(ifstream& qIn, linkedQueueType<Book> borrowedBooks, ifstream& tIn, 
	bSearchTreeType<Book> bookCatalog, User& admin, HashTable userDatabase) {
    
    cout << "Admin Dashboard" << endl;
    cout << "---------------" << endl;
    cout << "1. Add a Book" << endl;
    cout << "2. Remove a Book" << endl;
    cout << "3. Update Book Information" << endl;
    cout << "4. View All Loans" << endl;
    cout << "5. Add/Remove User (Admins)" << endl;
    cout << "6. Logout" << endl;
    cout << "Please select an option: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        addBook(bookCatalog);
        break;
    case 2:
        removeBook(bookCatalog);
        break;
    case 3:
        updateBookInfo(bookCatalog);
        break;
    case 4:
        viewAllLoans(borrowedBooks);
	break;
    case 5:
        addOrRemoveUser(userDatabase);
	break;
    case 6:
	cout << "Logging out..." << endl;
        logout(qIn, "Borrowed.txt", tIn, "Library.txt", borrowedBooks, bookCatalog);
	preLoginMenu();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
    if(choice != 6)
	adminMenu(qIn, borrowedBooks, tIn, bookCatalog, admin, userDatabase);
}
