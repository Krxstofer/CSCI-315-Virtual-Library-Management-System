
#include <iostream>
#include "hash.h"
#include "user.h"
#include "admin.h"

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
    int sum = 0;
    for (int i = 0; i < hashGroups; ++i) {
        sum += usersTable[i].size() + adminsTable[i].size();
    }
    return sum == 0;
}

void HashTable::insertUser(const User& user) {
    int hashValue = hashFunction(user.getUsername());
    usersTable[hashValue].push_back(user);
}

void HashTable::insertAdmin(const Admin& admin) {
    int hashValue = hashFunction(admin.getUsername());
    adminsTable[hashValue].push_back(admin);
}

void HashTable::removeUser(const std::string& username) {
    int hashValue = hashFunction(username);
    auto& userCell = usersTable[hashValue];
    auto& adminCell = adminsTable[hashValue];

    for (auto it = userCell.begin(); it != userCell.end(); ++it) {
        if (it->getUsername() == username) {
            userCell.erase(it);
            std::cout << "User '" << username << "' removed." << std::endl;
            return;
        }
    }

    for (auto it = adminCell.begin(); it != adminCell.end(); ++it) {
        if (it->getUsername() == username) {
            adminCell.erase(it);
            std::cout << "Admin '" << username << "' removed." << std::endl;
            return;
        }
    }

    std::cout << "User/Admin '" << username << "' not found." << std::endl;
}

std::string HashTable::searchTable(const std::string& username) {
    int hashValue = hashFunction(username);
    auto& userCell = usersTable[hashValue];
    auto& adminCell = adminsTable[hashValue];

    for (const auto& user : userCell) {
        if (user.getUsername() == username) {
            return user.getPassword();
        }
    }

    for (const auto& admin : adminCell) {
        if (admin.getUsername() == username) {
            return admin.getPassword();
        }
    }

    return ""; 
}

void HashTable::printTable() {
    for (int i = 0; i < hashGroups; ++i) {
        if (!usersTable[i].empty()) {
            std::cout << "Index " << i << " (Users): ";
            for (const auto& user : usersTable[i]) {
                std::cout << "Username: " << user.getUsername() << ", Password: " << user.getPassword() << "; ";
            }
            std::cout << std::endl;
        }

        if (!adminsTable[i].empty()) {
            std::cout << "Index " << i << " (Admins): ";
            for (const auto& admin : adminsTable[i]) {
                std::cout << "Username: " << admin.getUsername() << ", Password: " << admin.getPassword() << "; ";
            }
            std::cout << std::endl;
        }
    }
}