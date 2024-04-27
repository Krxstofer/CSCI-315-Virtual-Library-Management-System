//Name: Group 2
//Date: 05/04/2024

//AdminFun.cpp: implementation file for Admin functions
#include <iostream>
#include <string>
#include "Book.h"
#include "AdminFun.h"
#include "linkedQueue.h"

using namespace std;

//PLACE the implementation for your admin function here

void viewAllLoans(linkedQueueType<Book>& queue)
{
    //printing a queue requires deleting a queue, so a temporary queue is used.
    linkedQueueType<Book> tempQueue = queue;
    Book tempBook;

    cout << "Here are all the books currently loaned out: " << endl;
    while(!tempQueue.isEmptyQueue())
    {
	tempBook = tempQueue.front();
        cout << tempBook;
        cout << "Borrowed by: " << tempBook.getBorrower() << endl << endl;
    	tempQueue.deleteQueue();
    }
    //If no user has borrowed any books, no books would be printed.
}
