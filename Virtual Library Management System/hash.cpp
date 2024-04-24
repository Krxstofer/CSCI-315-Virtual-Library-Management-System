#include "hash.h"
#include <iostream>

int HashTable::hashFunction(const std::string& username) {
    int hash = 0;
    for (char ch : username) {
        hash += ch; // Sum of ASCII values of characters
    }
    return hash % hashGroups;
}

void HashTable::insertUser(const std::string& username) {
    int hashValue = hashFunction(username);
    table[hashValue].emplace_back(hashValue, username);
}

void HashTable::removeUser(const std::string& username) {
    int hashValue = hashFunction(username);
    auto& cell = table[hashValue];
    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->second == username) {
            cell.erase(it);
            std::cout << "User '" << username << "' removed." << std::endl;
            return;
        }
    }
    std::cout << "User '" << username << "' not found." << std::endl;
}

void HashTable::printTable() {
    for (int i = 0; i < hashGroups; ++i) {
        if (!table[i].empty()) {
            std::cout << "Index " << i << ": ";
            for (const auto& entry : table[i]) {
                std::cout << entry.second << " ";
            }
            std::cout << std::endl;
        }
    }
}
