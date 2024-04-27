//Name: Group 2
//Date: 05/04/2024

#ifndef H_AdminFun
#define H_AdminFun

//adminFun.h: header file for admin functions
#include <iostream>
#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "UserFun.h"

using namespace std;

void viewAllLoans(linkedQueueType<Book>& );
//function for admin; it displays all books currently borrowed by users
//Postcondition: none

//PLACE your admin prototype(s) here

class Admin : public User {
public:
    Admin(string username, string password)
        : User(username, password, "admin") {}

    void displayMenu() override {
        cout << "Admin Dashboard\n---------------\n";
        cout << "1. Add a Book\n";
        cout << "2. Remove a Book\n";
        cout << "3. Update Book Information\n";
        cout << "4. View All Loans\n";
        cout << "5. Add/Remove User (Admins)\n";
        cout << "6. Logout\n";
    }
};
#endif
