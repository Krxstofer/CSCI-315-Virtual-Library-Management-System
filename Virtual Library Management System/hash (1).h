#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <list>
#include "user.h"
#include "admin.h"

class HashTable {
private:
    static const int hashGroups = 20;
    std::list<User> usersTable[hashGroups];
    std::list<Admin> adminsTable[hashGroups];

    int hashFunction(const std::string& key);

public:
    HashTable();
    bool isEmpty() const;
    void insertUser(const User& user);
    void insertAdmin(const Admin& admin);
    void removeUser(const std::string& username);
    std::string searchTable(const std::string& username);
    void printTable();
};

#endif // HASH_TABLE_H
