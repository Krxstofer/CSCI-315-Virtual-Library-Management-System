#include <iostream>
#include "hash.h"
#include "user.h"

// Function to handle user login
User* login(HashTable& table, const std::string& username, const std::string& password) {
    std::string storedPassword = table.searchTable(username);
    if (!storedPassword.empty() && storedPassword == password) {
        int hashValue = table.hashFunction(username);
        auto& users = table.getUsersTable()[hashValue];
        for (auto& user : users) {
            if (user.getUsername() == username) return new User(user);  // Assuming copy constructor exists
        }
        auto& admins = table.getAdminsTable()[hashValue];
        for (auto& admin : admins) {
            if (admin.getUsername() == username) return new Admin(admin);  // Assuming copy constructor exists
        }
    }
    return nullptr;
}

int main() {
    HashTable table;
    // Presumably, users and admins would be inserted into the table earlier in the program

    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    User* user = login(table, username, password);
    if (user) {
        user->displayMenu();
        delete user;  // Clean up the created user object
    } else {
        std::cout << "Invalid username or password!" << std::endl;
    }

    return 0;
}
