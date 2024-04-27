//Samuel C Etzkorn
//CSCI 315
// Group project
// Hash table Final Project

#include <iostream>
#include "user.h"
#include "admin.h"
#include "hash.h"

int main() {
    HashTable ht;

    // Inserting users
    ht.insertUser(User("David", "password1"));
    ht.insertUser(User("Lucas", "password2"));
    ht.insertUser(User("Alex", "password3"));
    ht.insertUser(User("Jackson", "password4"));
    ht.insertUser(User("Emily", "password5"));
    ht.insertUser(User("Emma", "password6"));
    ht.insertUser(User("Riley", "password7"));
    ht.insertUser(User("Sam", "password8"));
    ht.insertUser(User("Sammy", "password9"));
    ht.insertUser(User("Christine", "password10"));
    ht.insertUser(User("Penelope", "password11"));
    ht.insertUser(User("Julian", "password12"));
    ht.insertUser(User("Oakley", "password13"));
    ht.insertUser(User("JJ", "password14"));
    ht.insertUser(User("Fredrick", "password15"));
    ht.insertUser(User("Marcel", "password16"));
    ht.insertUser(User("Nami", "password17"));
    ht.insertUser(User("Jack", "password18"));

  // Printing hash table
      ht.printTable();

      // Removing a user
      ht.removeUser("Lucas");

      // Printing hash table after removal
      ht.printTable();

      // Searching for a user
      std::cout << "Password for Alex: " << ht.searchTable("Alex") << std::endl;
  
      return 0;
  }
