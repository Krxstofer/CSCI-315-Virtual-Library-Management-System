//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//QueueTest.cpp: file for testing the queue object (linked list version)
//and for implementing its data persistence functions (loadQueue and saveQueue)

#ifndef LoadSave
#define LoadSave 
#include <fstream>
#include "Book.h"
#include "linkedQueue.h"

using namespace std;

void loadQueue(ifstream& in, linkedQueueType<Book>& queue);
void saveQueue(ofstream& out, linkedQueueType<Book> queue); //no & means the actual parameter is not
							    //passed since queue needs to be mostly
							    //deleted to be read

#endif
