//Name: Group 2
//Date: 05/04/2024

#ifndef H_UserFun
#define H_UserFun
//userFun.h: header file for user functions

#include <iostream>
#include <string>
#include "Book.h"
#include "linkedQueue.h"

using namespace std;

class User {
public:
    string username;
    string password;
    string role;

    User(string username, string password, string role)
        : username(username), password(password), role(role) {}

    virtual void displayMenu() = 0;
    virtual ~User() {}
    // Getters
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getRole() const { return role; }

    // Setters
    void setUsername(const string& newUsername) { username = newUsername; }
    void setPassword(const string& newPassword) { password = newPassword; }
    void setRole(const string& newRole) { role = newRole; }
};

class StandardUser : public User {
public:
    StandardUser(string username, string password)
        : User(username, password, "user") {}

    void displayMenu() override {
        cout << "Welcome " << username << ", you're logged in as a standard user.\n";
        cout << "1. Search for Books\n";
        cout << "2. Borrow a Book\n";
        cout << "3. Return a Book\n";
        cout << "4. View Borrowed Books\n";
        cout << "5. Update Profile\n";
        cout << "6. Logout\n";
    }
};

void viewBorrowedBooks(linkedQueueType<Book>&, string username);
//function for users; it displays all books borrowed by that user
//Postcondition: None

void updateProfile(StandardUser& );
//function for users; it allows users limited control to update their profile settings
//Postcondition: if the correct input is provided, it changes the username or password
//	based on the user's choice. If the input is incorrect, the postcondition is none.

//PLACE your user prototype(s) here.

#endif
