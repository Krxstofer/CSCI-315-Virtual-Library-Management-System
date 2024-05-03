#include <iostream>
#include "Login.h"
#include "hash.h"
#include "user.h"

// Assuming "Login.h" declares the login function and includes "hash.h" and "user.h"
// Login function now returns the role of the user or an empty string if login fails
std::string login(HashTable& ht, const std::string& username, const std::string& password) {
    if (ht.checkPassword(username, password)) {
        std::string role = ht.getUserRole(username);
        if (!role.empty()) {
            std::cout << "Login successful! Welcome, " << username << ". You are logged in as a(n) " << role << "." << std::endl;
        } else {
            std::cout << "User role not found." << std::endl;
        }
        return role;
    } else {
        std::cout << "Login failed: Invalid username or password." << std::endl;
        return "";  // Return an empty string if authentication fails
    }
}

int main() {
    HashTable ht;

    // Example users inserted into the hash table
    ht.insertUser(User("Alice", "alice123", "admin"));
    ht.insertUser(User("Bob", "bob456", "standard"));

    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::string role = login(ht, username, password);
    if (!role.empty()) {
        if (role == "admin") {
            std::cout << "Admin menu goes here.\n";
        } else if (role == "standard") {
            std::cout << "Standard user menu goes here.\n";
        } else {
            std::cout << "Special role menu goes here.\n";
        }
    } else {
        std::cout << "Access denied.\n";
    }

    return 0;
}
