//hash.h

#pragma once
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <list>
#include "user.h"
#include "Login.h"
#include "ExitFunction.h"

class HashTable {
private:
    static const int hashGroups = 20;
    std::list<User> usersTable[hashGroups];

    int hashFunction(const std::string& key);

public:
    HashTable();
    bool isEmpty() const;
    void insertUser(const User& user);
    void removeUser(const std::string& username);
    bool checkPassword(const std::string& username, const std::string& password);
    std::string getUserRole(const std::string& username);
    void printTable();
};

#endif // HASH_TABLE_H
