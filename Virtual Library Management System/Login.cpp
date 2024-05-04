#include <iostream>
#include "hash.h"  // Includes the HashTable class definition
#include "user.h"  // Includes the User class definition
#include "Login.h" // Includes the Login class header

// Declare the login function
std::string login(HashTable& ht, const std::string& username, const std::string& password, bool verbose);

int main() {
    HashTable ht;
    ht.insertUser(User("Alice", "alice123", "admin"));
    ht.insertUser(User("Bob", "bob456", "standard"));

    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Pass the verbose parameter according to the desired output behavior
    std::string role = login(ht, username, password, true);
    if (!role.empty()) {
        if (role == "admin") {
            adminMenu(qIn, borrowedBooks, tIn, bookCatalog, admin, userDatabase);
        } if else (role == "user") {
            userMenu(qIn, borrowedBooks, tIn, bookCatalog, user, userDatabase);
        }
    } else {
        std::cout << "Access denied.\n";
    }

    return 0;
}

// Adjust the login function to include the verbose parameter to control output
std::string login(HashTable& ht, const std::string& username, const std::string& password, bool verbose) {
    if (ht.checkPassword(username, password)) {
        std::string role = ht.getUserRole(username);
        if (!role.empty()) {
            if (verbose) {
                std::cout << "Login successful! Welcome, " << username << ". You are logged in as a(n) " << role << "." << std::endl;
            }
        } else {
            if (verbose) {
                std::cout << "User role not found." << std::endl;
            }
        }
        return role;
    } else {
        if (verbose) {
            std::cout << "Login failed: Invalid username or password." << std::endl;
        }
        return "";  // Return an empty string if authentication fails
    }
}
