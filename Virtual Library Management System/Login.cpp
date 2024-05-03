#include "Login.h"

// Implementation of the login function
bool login(HashTable& ht, const std::string& username, const std::string& password) {
    // Assuming HashTable has a method called authenticate that checks if the username and password are correct
    // and returns the user's role if successful, or an empty string if the login fails.
    std::string role = ht.authenticate(username, password);

    if (!role.empty()) {
        std::cout << "Login successful! Welcome, " << username << ". You are logged in as a(n) " << role << "." << std::endl;
        return true;
    } else {
        std::cout << "Login failed: Invalid username or password." << std::endl;
        return false;
    }
}
