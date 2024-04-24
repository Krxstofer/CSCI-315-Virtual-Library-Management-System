#ifndef HASH_H
#define HASH_H

#include <string>
#include <list>

class HashTable {
private:
    static const int hashGroups = 20;
    std::list<std::pair<int, std::string>> table[hashGroups];

    int hashFunction(const std::string& username);

public:
    void insertUser(const std::string& username);
    void removeUser(const std::string& username);
    void printTable();
};

#endif // HASH_H
