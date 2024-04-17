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
unordered_map<int, Book> bookCatalog;
unordered_map<string, User> userDatabase;
//vector<string> borrowedBooks; //borrowedBooks is now a queue
// Add more as needed

// Function prototypes
void preLoginMenu();

void userMenu(const User& user); //user functions
void searchBook();
void borrowBook();
void returnBook();
void viewBorrowedBooks(); //Andrew - in progress
void updateProfile(); //Andrew - prototype ready (see below)

void adminMenu(); //admin functions
void addBook();
void removeBook();
void updateBookInfo();
void viewAllBooks(); //Andrew - in progress
void addOrRemoveUser();
// Add more function prototypes for other functionalities

void loadQueue(ifstream& in, linkedQueueType<Book>& queue);
void saveQueue(ofstream& out, linkedQueueType<Book> queue); //no & means the actual parameter is not
                                                            //emptied when the formal parmaeter is read
							    //(reading uses deleteQueue to progress)

int main() {
    // Populate book catalog and user database with sample data for testing
    // You can replace this with actual data loading from files or databases
    
    preLoginMenu();
    updateProfile(); //Andrew - this will execute so long as the user does not exist in preLoginMenu

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
    ifstream qIn;
    ofstream qOut;
    linkedQueueType<Book> borrowedBooks;
    char c;

    qIn.open("Borrowed.txt");
    qIn.get(c); //detect eof in existing, empty file
    if(!qIn)
    {
      cout << "Borrowed books file not found! Shutting down." << endl;
      exit(1);
    }
    loadQueue(qIn, borrowedBooks);

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
	qOut.open("Borrowed.txt"); //storage file for books
        saveQueue(qOut, borrowedBooks);
        qIn.close();
        qOut.close();
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

void viewBorrowedBooks() {
    // Implement view borrowed book functions
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
    ifstream qIn;
    ofstream qOut;
    linkedQueueType<Book> borrowedBooks;
    char c;

    qIn.open("Borrowed.txt");
    qIn.get(c); //detect eof in existing, empty file
    if(!qIn)
    {
      cout << "Borrowed books file not found! Shutting down." << endl;
      exit(1);
    }
    loadQueue(qIn, borrowedBooks);

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
        viewAllBooks();
    case 5:
        addOrRemoveUser();
    case 6:
        cout << "Logging out..." << endl;
        qOut.open("Borrowed.txt"); //storage file for books
	saveQueue(qOut, borrowedBooks);
        qIn.close();
        qOut.close();
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

void viewAllBooks() {
    // Implement view all books "loans" function
}

void addOrRemoveUser() {
    // Implement add or remove user functions
}

void loadQueue(ifstream& in, linkedQueueType<Book>& queue) //needs to be run once
							   //before new borrows are added
{

  Book temp;
  char c;

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

