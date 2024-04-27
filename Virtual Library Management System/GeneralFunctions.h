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
#include "hash.h"

using namespace std;

void logout(ifstream& qIn, ifstream& tIn, linkedQueueType<Book>& queue, bSearchTreeType<Book>& tree);
void registerUser(HashTable& hash);

#endif
