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

//tOut is a global in LoadSave since the binary tree's inorderTraversal() with a function
//parameter only takes one parameter and out must be opened outside of 
//saveTree (where it is used) since it is recurisive and thus called multiple times

using namespace std;

// Book class is now in Book.h

//Admin and User class were removed here since they are implemented in AdminFun.h and
//	UserFun.h, respectively. The relevant functions are also under those header files

// Define global variables
//unordered_map<int, Book> bookCatalog; //bookCatalog is now a binary Search Tree

//unordered_map<string, User> userDatabase;
//vector<string> borrowedBooks; //borrowedBooks is now a queue
// Add more as needed

// Function prototypes
void preLoginMenu();

//User functions
void userMenu(StandardUser& user); //made user not constant because updateProfile needs to change user
void searchBook(bSearchTreeType<Book>& tree);
void borrowBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, StandardUser user);
static void returnBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, StandardUser user);

//Admin functions
void adminMenu(Admin& admin); //added admin object as a parameter
void addBook();
void removeBook();
void updateBookInfo();

void addOrRemoveUser();
// Add more function prototypes for other functionalities

int main() {
    // Populate book catalog and user database with sample data for testing
    // You can replace this with actual data loading from files or databases

    preLoginMenu();
    //updateProfile(); //Andrew - commented out for testing purposes; feel free to test this function.

    //Testing latest commit (requires queue)
    ifstream in;
    ofstream out;
    char c;
    linkedQueueType<Book> borrowedQueue;

    //open file
    in.open("Borrowed.txt");

    in.get(c); //detect eof in exisitng empty file
    if(!in)
    {
        cout << "File was not found, or the file is empty! Shutting down." << endl;
        exit(1);
    }
    loadQueue(in, borrowedQueue);

    //viewBorrowedBooks(borrowedQueue, "Me"); //new function that displays books borrowed by user
    //viewAllLoans(borrowedQueue); //Andrew - new function that dispalys all borrowed books

    return 0;
}

void preLoginMenu() {
//User me; //for testing
Admin you("you", "N3ssi3"); //for testing
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
	//userMenu(me); //for testing
	adminMenu(you); //for testing
        break;
    case 2:
        // Implement registration functionality
        break;
    case 3:
        cout << "Exiting program..." << endl;
        exit(0);
    default:
        cout << "Invalid choice. Please try again." << endl;
        preLoginMenu();
    }
}

void userMenu(StandardUser& user) {
    ifstream qIn, tIn;
    linkedQueueType<Book> borrowedBooks;
    bSearchTreeType<Book> bookCatalog;
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
        logout(qIn,tIn, borrowedBooks, bookCatalog);
    default:
        cout << "Invalid choice. Please try again." << endl;
        userMenu(user);
    }
}

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

void borrowBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, StandardUser user) {    // Implement borrow book functions

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

static void returnBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, StandardUser user) // Implement return book functions
{
    tree.search(queue.front())->returnBook();
    queue.deleteQueue();
}

void adminMenu(Admin& admin) {
    ifstream qIn, tIn;
    linkedQueueType<Book> borrowedBooks;
    bSearchTreeType<Book> bookCatalog;
    char c;

    //Loading queue
    qIn.open("Borrowed.txt"); //storage file for borrowed books
    qIn.get(c); //detect eof in existing, empty file
    if(!qIn)
    {
      cout << "Borrowed books file not found! Shutting down." << endl;
      exit(1);
    }
    loadQueue(qIn, borrowedBooks);

    //Loading tree
    tIn.open("Library.txt"); //storage file for all books
    tIn.get(c); //detect eof in exisitng empty file
    if(!tIn)
    {
      cout << "Library file not found, or the file is empty! Shutting down." << endl;
      exit(1);
    }
    loadTree(tIn, bookCatalog);

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
        addBook();
        break;
    case 2:
        removeBook();
    case 3:
        updateBookInfo();
    case 4:
        viewAllLoans(borrowedBooks);
    case 5:
        addOrRemoveUser();
    case 6:
        logout(qIn,tIn, borrowedBooks, bookCatalog);
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        adminMenu(admin);
    }
}

void addBook() {
    // Implement add book functions
}

void removeBook() {
    // Implement remove book function
}

void updateBookInfo() {
    // Implement update book info function
}

void addOrRemoveUser() {
    // Implement add or remove user functions
}

