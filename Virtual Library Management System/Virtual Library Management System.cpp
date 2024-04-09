// Virtual Library Management System Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Book.h"

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
vector<string> borrowedBooks;
// Add more as needed

// Function prototypes
void preLoginMenu();

void userMenu(const User& user);
void searchBook();
void borrowBook();
void returnBook();
void viewBorrowedBooks();
void updateProfile();

void adminMenu();
void addBook();
void removeBook();
void updateBookInfo();
void viewAllBooks();
void addOrRemoveUser();
// Add more function prototypes for other functionalities

int main() {
    // Populate book catalog and user database with sample data for testing
    // You can replace this with actual data loading from files or databases

    preLoginMenu();

    return 0;
}

void preLoginMenu() {
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
    // Implement update profile book functions
}


void adminMenu() {
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
