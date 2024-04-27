//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//LoadSave.h header file for data persistence functions (and printTree)
//(contains global ofstream variable tOut for use in saveTree())

#ifndef LoadSave
#define LoadSave 
#include <fstream>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"

using namespace std;

void loadQueue(ifstream& in, linkedQueueType<Book>& queue);
void saveQueue(ofstream& out, linkedQueueType<Book> queue); //no & means the actual parameter is not
							    //passed since queue needs to be mostly
							    //deleted to be read

//tOut is global since the binary tree's inorderTraversal() with a function
//parameter only takes one parameter and tOut must be opened outside of
//saveTree since it is recurisive and thus called multiple times
extern ofstream tOut;
void loadTree(ifstream& in, bSearchTreeType<Book>& tree);
void saveTree(Book& x);
void printTree(Book& x);


#endif
