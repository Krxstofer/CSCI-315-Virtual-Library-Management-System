//hash.cpp

#include <iostream>
#include "hash.h"
#include "user.h"

// Define the constructor
HashTable::HashTable() {
    // Constructor body can remain empty if no initialization is needed
}

int HashTable::hashFunction(const std::string& key) {
    int hash = 0;
    for (char ch : key) {
        hash += static_cast<int>(ch);
    }
    return hash % hashGroups;
}

bool HashTable::isEmpty() const {
    for (int i = 0; i < hashGroups; ++i) {
        if (!usersTable[i].empty()) {
            return false;
        }
    }
    return true;
}

void HashTable::insertUser(const User& user) {
    int hashValue = hashFunction(user.getUsername());
    usersTable[hashValue].push_back(user);
}

void HashTable::removeUser(const std::string& username) {
    int hashValue = hashFunction(username);
    auto& cell = usersTable[hashValue];

    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->getUsername() == username) {
            cell.erase(it);
            std::cout << "User '" << username << "' removed." << std::endl;
            return;
        }
    }

    std::cout << "User '" << username << "' not found." << std::endl;
}

bool HashTable::checkPassword(const std::string& username, const std::string& password) {
    int hashValue = hashFunction(username);
    auto& cell = usersTable[hashValue];

    for (const auto& user : cell) {
        if (user.getUsername() == username && user.getPassword() == password) {
            return true; // Password matches
        }
    }

    return false; // User not found or password does not match
}

std::string HashTable::getUserRole(const std::string& username) {
    int hashValue = hashFunction(username);
    auto& cell = usersTable[hashValue];

    for (const auto& user : cell) {
        if (user.getUsername() == username) {
            return user.getRole();
        }
    }

    return ""; // User not found
}

void HashTable::printTable() {
    for (int i = 0; i < hashGroups; ++i) {
        if (!usersTable[i].empty()) {
            std::cout << "Index " << i << "(Users): ";
            for (const auto& user : usersTable[i]) {
                std::cout << "Username: " << user.getUsername() << "; ";
            }
            std::cout << std::endl;
        }
    }
}