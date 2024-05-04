//hash.h

#pragma once
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <list>
#include "user.h"


class HashTable {
public:
    static const int hashGroups = 20;
    std::list<User> usersTable[hashGroups];

    int hashFunction(const std::string& key);

public:
    HashTable();
    bool isEmpty() const;
    void insertUser(const User& user);
    void removeUser(const std::string& username, bool printMessage = true);
    bool checkPassword(const std::string& username, const std::string& password);
    std::string getUserRole(const std::string& username);
    void printTable();
    void saveData(const std::string& filename) const;
    void loadData(const std::string& filename);
};

#endif // HASH_TABLE_H
