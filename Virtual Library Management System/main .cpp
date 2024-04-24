//Name: Samuel Etzkorn  
//Description:  CSCI Group Project
//Date:  20APR24
//book.cpp: Hash Table

#include <iostream>
#include "hash.h"

int main() {
    HashTable ht;

    // Inserting users
    ht.insertUser("David");
    ht.insertUser("Lucas");
    ht.insertUser("Alex");
    ht.insertUser("Jackson");
    ht.insertUser("Emily");
    ht.insertUser("Emma");
    ht.insertUser("Riley");
    ht.insertUser("Sam");
    ht.insertUser("Sammy");
    ht.insertUser("Christine");
    ht.insertUser("Penelope");
    ht.insertUser("Julian");
    ht.insertUser("Oakley");
    ht.insertUser("JJ");
    ht.insertUser("Fredrick");
    ht.insertUser("Marcel");
    ht.insertUser("Nami");
    ht.insertUser("Jack");
    ht.insertUser("Jackie");
    ht.insertUser("Ryan");

    // Printing hash table
    ht.printTable();

    // Removing a user
    ht.removeUser("Lucas");

    // Printing hash table after removal
    ht.printTable();

    return 0;
}
