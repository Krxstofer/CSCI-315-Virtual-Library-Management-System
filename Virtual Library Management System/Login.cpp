#include "Login.h"
#include "hash.h" // Ensures HashTable and User are defined here

// Implementation of the login function with revised authentication logic
bool login(HashTable& ht, const std::string& username, const std::string& password) {
    // First, check if the username and password are correct
    if (ht.checkPassword(username, password)) {
        // If credentials are valid, get the user's role
        std::string role = ht.getUserRole(username);
        if (!role.empty()) {
            std::cout << "Login successful! Welcome, " << username << ". You are logged in as a(n) " << role << "." << std::endl;
            return true;
        } else {
            std::cout << "Login failed: User role could not be determined." << std::endl;
            return false;
        }
    } else {
        std::cout << "Login failed: Invalid username or password." << std::endl;
        return false;
    }
}
