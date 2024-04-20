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

//tOut is global since the binary tree's inorderTraversal() with a function
//parameter only takes one parameter and out must be opened outside of 
//saveTree (where it is used) since it is called multiple times
ofstream tOut;

using namespace std;

// Book class is now in Book.h and Book.cpp

// Define Admin class
class Admin {
public:
    string username;
    string password;
    // Add more attributes as needed
};

// Define User class
class User {
public:
    string username;
    string password;
    // Add more attributes as needed
};


// Define global variables 
//unordered_map<int, Book> bookCatalog; //bookCatalog is now a binary Search Tree

unordered_map<string, User> userDatabase;
//vector<string> borrowedBooks; //borrowedBooks is now a queue
// Add more as needed

// Function prototypes
void preLoginMenu();

//User functions
void userMenu(const User& user);
void searchBook();
void borrowBook();
void returnBook();

void viewBorrowedBooks(linkedQueueType<Book>&, string username);
//function for users; it displays all books borrowed by that user
//the final version will have a user object as a paremeter
//Postcondition: None

void updateProfile();
//function for users; it allows users limited control to update their profile settings
//final version will have a user object as a parameter
//Postcondition: if the correct input is provided, it changes the username or password
//      based on the user's choice. If the input is incorrect, postcondition is none.

//Admin functions
void adminMenu();
void addBook();
void removeBook();
void updateBookInfo();

void viewAllLoans(linkedQueueType<Book>& );
//function for admin; it displays all books currently borrowed by users
//Postcondition: none

void addOrRemoveUser();
// Add more function prototypes for other functionalities

//Queue data persistence functions
void loadQueue(ifstream& in, linkedQueueType<Book>& queue);
void saveQueue(ofstream& out, linkedQueueType<Book> queue); //no & means the actual parameter is not
                                                            //emptied when the formal parmaeter is read
							    //(reading uses deleteQueue to progress)
//binary search tree data persistence functions
void loadTree(ifstream& in, bSearchTreeType<Book>& tree);
void saveTree(Book& x);

void printTree(Book& x);

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

    viewBorrowedBooks(borrowedQueue, "Me"); //new function that displays books borrowed by user
    viewAllLoans(borrowedQueue); //Andrew - new function that dispalys all borrowed books

    return 0;
}

void preLoginMenu() {
//User me; //for testing
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
	//adminMenu(); //for testing
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

void userMenu(const User& user) {
    ifstream qIn, tIn;
    ofstream qOut; //tOut is global
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
      cout << "File was not found, or the file is empty! Shutting down." << endl;
      exit(1);
    }
    loadTree(tIn, bookCatalog);

    cout << "Welcome " << user.username << " Thanks for using our Virtual Library!" << endl;
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
        void searchBook();
        break;
    case 2:
        void borrowBook();
        break;
    case 3:
        void returnBook();
        break;
    case 4:
        void viewBorrowedBooks();
        break;
    case 5:
        void addOrRemoveUser();
        break;
    case 6:
        cout << "Logging out..." << endl;

	//Saving out queue
	qOut.open("Borrowed.txt"); //storage file for borrowed books
        saveQueue(qOut, borrowedBooks);
        qIn.close();
        qOut.close();

	//Saving out binary search tree
	tOut.open("Library.txt"); //storage file for all books
	bookCatalog.inorderTraversal(saveTree);
	tIn.close();
        tOut.close();

        preLoginMenu();
    default:
        cout << "Invalid choice. Please try again." << endl;
        userMenu(user);
    }
}

void searchBook() {
    // Implement search book functions
}

void borrowBook() {
    // Implement borrow book functions
}

void returnBook() {
    // Implement return book functions
}

void viewBorrowedBooks(linkedQueueType<Book>& queue, string username) //ready for commit; move to main
{
    //printing a queue requires deleting a queue, so a temporary queue is used.
    linkedQueueType<Book> tempQueue = queue;
    Book tempBook;
    string user = username; //this will be replaced with a call to myUser.getUsername()

    cout << "Here are all of the books you, " << user << ", have borrowed: " << endl;
    while(!tempQueue.isEmptyQueue())
    {
        tempBook = tempQueue.front();
        //every book in the queue is assumed to be borrowed,
        //    so book.borrowed() does not need to be checked.
        if(user == tempBook.getBorrower())
            cout << tempBook << endl;
        tempQueue.deleteQueue();
    }
    //If a user has not borrowed any books, no books would be printed.
}

void updateProfile() {
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
        //Set username
    }
    else if(choice == 2)
    {
        cout << "Please enter your new password: ";
        cin >> newName;
        //Set password
    }
    cout << "Exiting update profile" << endl;
}

void adminMenu() {
    ifstream qIn, tIn;
    ofstream qOut; //tOut is global
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
      cout << "File was not found, or the file is empty! Shutting down." << endl;
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
        cout << "Logging out..." << endl;
        
	//Saving out queue
	qOut.open("Borrowed.txt"); //storage file for borrowed books
        saveQueue(qOut, borrowedBooks);
        qIn.close();
        qOut.close();

	//Saving out binary search tree
	tOut.open("Library.txt"); //storage file for all books
	bookCatalog.inorderTraversal(saveTree);
	tIn.close();
        tOut.close();

        preLoginMenu();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        adminMenu();
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

void viewAllLoans(linkedQueueType<Book>& queue)
{
    //printing a queue requires deleting a queue, so a temporary queue is used.
    linkedQueueType<Book> temp = queue;

    cout << "Here are all the books currently loaned out: " << endl;
    while(!temp.isEmptyQueue())
    {
        cout << temp.front() << endl;
        temp.deleteQueue();
    }
    //If a user has not borrowed any books, no books would be printed.
}

void addOrRemoveUser() {
    // Implement add or remove user functions
}

//Queue functions
void loadQueue(ifstream& in, linkedQueueType<Book>& queue) //needs to be run once
							   //before new borrows are added
{

  Book temp;
  char c;

  in.get(c); //check for eof
  while(in)
  {

    in >> temp;
    if(temp.getBorrowed() == true) //make sure this book should be in the queue (it is borrowed)
    {
      queue.addQueue(temp);
    }
    else //temp is not added to the queue
    {
      cout << "Error! " << temp.getTitle() << " should not be in the borrowed queue" << endl
	   << "because it is not checked out. It will not be loaded from the file." << endl << endl;
    }
    in.get(c); //check for another entry (takes a char off a label (harmeless)) otherwise
               //indicates eof to the while
  }
  //when save is run it will overwrite any erroneous entries left in the file

}

void saveQueue(ofstream& out, linkedQueueType<Book> queue)//must run before program ends?
{
  //forcing a load here could append older borrowed books to the end of the user's working queue
  //so the programmer must be resposible for calling an initial load before any
  //calls to addQueue or saveQueue


  while(!queue.isEmptyQueue())
  {
    if(queue.front().getBorrowed() == true) //make sure this book should be in the queue (it is borrowed)
    {
      out << queue.front(); //if it is borrowed write it out
    }
    else
    {
      cout << "Error! " << queue.front().getTitle() << " should not be in the borrowed queue" << endl
	   << "because it is not checked out. It will not be written to the file." << endl << endl;
    }

    queue.deleteQueue(); //either way, remove front item from the queue
  }

}

//Tree functions
void loadTree(ifstream& in, bSearchTreeType<Book>& tree) //needs to be run once
							   //before save writes to the Library file
{

  Book temp;
  char c;
  in.get(c); //check for eof
  while(in)
  {
    in >> temp;
    tree.insert(temp);
    in.get(c); //check for another entry (takes a char off a label (harmeless)) otherwise
               //indicates eof to the while
  }

}

void saveTree(Book& x)//must run before program end. Will overwrite Library.txt
{
  tOut << x;
}

void printTree(Book& x)
{
  cout << x << endl;
}



