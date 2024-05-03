//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//GeneralFunctions.h header file for the general functions
//(those which are not part of the either User or Admin menus or are in both (e.g. logout))

#ifndef General
#define General
#include <fstream>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "Login.h"
#include "ExitFunction.h"
#include "hash.h"
//Login.h here
#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>

// Declare the login function that returns a user's role as a string
std::string login(HashTable& ht, const std::string& username, const std::string& password, bool verbose = true);

#endif // LOGIN_H
using namespace std;

void logout(ifstream& qIn, string qBook, ifstream& tIn, string tBook, linkedQueueType<Book>& queue, bSearchTreeType<Book>& tree, bool display = true);
bool registerUser(HashTable& hash, User& user, istream& in_stream = cin, bool display = true);


#endif
