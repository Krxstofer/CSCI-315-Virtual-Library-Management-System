// User.cpp
#include "user.h"

// Constructor
User::User(const std::string& username, const std::string& password, const std::string& role)
    : username(username), password(password), role(role) {}

// Display different menus based on the role
void User::displayMenu() {
    if (role == "admin") {
        std::cout << "Admin Dashboard\n---------------\n";
        std::cout << "1. Add a Book\n";
        std::cout << "2. Remove a Book\n";
        std::cout << "3. Update Book Information\n";
        std::cout << "4. View All Loans\n";
        std::cout << "5. Add/Remove User (Admins)\n";
        std::cout << "6. Logout\n";
    } else {
        std::cout << "Welcome " << username << ", you're logged in as a standard user.\n";
        std::cout << "1. Search for Books\n";
        std::cout << "2. Borrow a Book\n";
        std::cout << "3. Return a Book\n";
        std::cout << "4. View Borrowed Books\n";
        std::cout << "5. Update Profile\n";
        std::cout << "6. Logout\n";
    }
}

// Getters
std::string User::getUsername() const { return username; }
std::string User::getPassword() const { return password; }
std::string User::getRole() const { return role; }

// Setters
void User::setUsername(const std::string& newUsername) { username = newUsername; }
void User::setPassword(const std::string& newPassword) { password = newPassword; }
void User::setRole(const std::string& newRole) { role = newRole; }
