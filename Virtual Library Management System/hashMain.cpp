// hashMain.cpp

#include <iostream>
#include "user.h"
#include "hash.h"

int main() {
    HashTable ht;

    // Inserting users
    ht.insertUser(User("David", "password1", "standard"));
    ht.insertUser(User("Lucas", "password2", "standard"));
    ht.insertUser(User("Alex", "password3", "standard"));  
    ht.insertUser(User("Jackson", "password4", "standard"));
    ht.insertUser(User("Emily", "password5", "standard"));
    ht.insertUser(User("Emma", "password6", "standard"));
    ht.insertUser(User("Riley", "password7", "standard"));
    ht.insertUser(User("Sam", "password8", "standard"));
    ht.insertUser(User("Sammy", "password9", "standard"));
    ht.insertUser(User("Christine", "password10", "standard"));
    ht.insertUser(User("Penelope", "password11", "standard"));
    ht.insertUser(User("Julian", "password12", "standard"));
    ht.insertUser(User("Oakley", "password13", "standard"));
    ht.insertUser(User("JJ", "password14", "standard"));
    ht.insertUser(User("Fredrick", "password15", "standard"));
    ht.insertUser(User("Marcel", "password16", "standard"));
    ht.insertUser(User("Nami", "password17", "standard"));
    ht.insertUser(User("Jack", "password18", "standard"));

    // Printing hash table
    ht.printTable();

    // Removing a user
    ht.removeUser("Lucas");

    // Printing hash table after removal
    ht.printTable();

    // Checking password and getting role
    std::string username = "Alex";
    std::string password = "password3"; // Example password
    if(ht.checkPassword(username, password)) {
        std::cout << "Password for " << username << " is correct. Role: " << ht.getUserRole(username) << std::endl;
    } else {
        std::cout << "Password for " << username << " is incorrect or user does not exist." << std::endl;
    }

    return 0;
}
