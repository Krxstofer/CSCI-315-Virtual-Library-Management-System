#include <iostream>
#include "hash.h"   // Assuming hash.h has been included properly and configured
#include "user.h"   // Assuming this contains the User class definition

// Assuming HashTable has a method login that performs user authentication and returns the role or an empty string if failed
bool login(HashTable& ht, const std::string& username, const std::string& password) {
    std::string role = ht.login(username, password);  // Use the combined login method
    if (!role.empty()) {
        std::cout << "Login successful! Welcome, " << username << ". You are logged in as a(n) " << role << "." << std::endl;
        return true;
    } else {
        std::cout << "Login failed: Invalid username or password." << std::endl;
        return false;
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

    if (login(ht, username, password)) {
        // Additional logic for logged-in users
        std::cout << "Access to user-specific features...\n";
    } else {
        std::cout << "Access denied.\n";
    }

    return 0;
}
