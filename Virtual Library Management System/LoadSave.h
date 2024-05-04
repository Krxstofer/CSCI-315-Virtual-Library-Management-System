#pragma once
#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H
#include <fstream>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "hash.h"

class LoadSave {
public:
    static void saveData(const HashTable& ht, const std::string& filename);
    static void loadData(HashTable& ht, const std::string& filename);
};



void loadQueue(ifstream& in, linkedQueueType<Book>& queue, bool display = true);
void saveQueue(ofstream& out, linkedQueueType<Book> queue, bool display = true); //no & means the actual parameter is
//passed since queue needs to be mostly deleted to be read

//tOut is global since the binary tree's inorderTraversal() with a function
//parameter only takes one parameter and tOut must be opened outside of
//saveTree since it is recurisive and thus called multiple times
extern ofstream tOut;

void loadTree(ifstream& in, bSearchTreeType<Book>& tree);
void saveTree(Book& x);
void printTree(Book& x);



#endif 