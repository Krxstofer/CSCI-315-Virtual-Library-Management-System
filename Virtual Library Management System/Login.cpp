#include <iostream>
#include "hash.h"

bool login(HashTable& ht, const std::string& username, const std::string& password) {
    std::string role = ht.login(username, password);  // Combined authentication and role retrieval
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

    login(ht, username, password);  // Performing login

    return 0;
}

