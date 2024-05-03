#include <iostream>
#include "Login.h"  // Includes login function declaration and implicitly includes hash.h

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
        // If login is successful, show user-specific features
        std::cout << "Access to user-specific features...\n";
    } else {
        // If login fails, deny access
        std::cout << "Access denied.\n";
    }

    return 0;
}
