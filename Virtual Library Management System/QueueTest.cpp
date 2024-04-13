//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//QueueTest.cpp: file for testing the queue object (linked list version)
//and for implementing its data persistence functions (loadQueue and saveQueue)

#include <string>
#include <iostream>
#include "Book.h"
#include "linkedQueue.h"

using namespace std;

void loadQueue(ifstream& in, linkedQueueType<Book>& queue);
void saveQueue(ofstream& out, linkedQueueType<Book> queue); //no & means the actual parameter is not
                                                            //emptied when the formal parmaeter is read
							    //(reading uses deleteQueue to progress)
int main()
{
/*temporary testing*/
ifstream in;
ofstream out;
char c;
linkedQueueType<Book> temp, copy, borrowedBooks;
Book b1("A Tale of Two Cities", "Charles", "Dickens", 1990, "Wordsworth", "DIC", false, "N/A");
Book b2("A Christmas Carol", "Charles", "Dickens", 1992, "Wordsworth", "DIC", true, "You");

in.open("Borrowed.txt");

in.get(c); //detect eof in exisitng empty file
if(!in)
{
  cout << "File was not found, or the file is empty! Shutting down." << endl;
  exit(1);
}

loadQueue(in, borrowedBooks);
temp = copy = borrowedBooks; //assignment test
cout << "Books in Borrowed.txt: " << endl;
while(!borrowedBooks.isEmptyQueue()) //view queue
{
  cout << borrowedBooks.front() << endl; //print front item
  borrowedBooks.deleteQueue(); //remove front item from the queue
}
cout <<"---------------------" << endl;

//---------------------------------------------//
//Tests for copy constructor and operator=

cout << "A copy of borrowedBooks with the = :" << endl;

while(!temp.isEmptyQueue()) //view queue
{
  cout << temp.front() << endl; //print front item
  temp.deleteQueue(); //remove front item from the queue
}

cout << "New queue copy-constructor-initialzed with copy" << endl;
linkedQueueType<Book> temp2(copy); //test copy constructor
while(!temp2.isEmptyQueue())
{
  cout << temp2.front() << endl;
  temp2.deleteQueue();
}

cout << "Copy-constructor-initialzed with an empty queue" << endl;
linkedQueueType<Book> temp3(temp); //test copy constructor with an empty queue
while(!temp3.isEmptyQueue())
{
  cout << temp3.front() << endl;
  temp3.deleteQueue();
}

cout << "Overloaded assignment operator with an empty queue" << endl;
temp2 = temp; //test overloaded assignment with an empty queue
while(!temp2.isEmptyQueue())
{
  cout << temp2.front() << endl;
  temp2.deleteQueue();
}

cout << "Overloaded assignment operator with two empty queues" << endl;
temp3 = temp; //two empty queues
while(!temp3.isEmptyQueue())
{
  cout << temp3.front() << endl;
  temp3.deleteQueue();
}
cout << "No crashes" << endl << endl;
//--------------------------------------//

borrowedBooks.addQueue(b1);//testing saveQueue borrowed = false excluder
borrowedBooks.addQueue(b2);//testing addQueue where borrowed = true
out.open("Borrowed.txt"); //storage file for books
saveQueue(out, borrowedBooks); //writes out only borrowed books, but does not remove erroneous
			       //entries from the queue itself the programmer should ensure
                               //that only borrowed books are used as parameters for addQueue()

cout << "borrowedBooks after saveQueue: " << endl;
while(!borrowedBooks.isEmptyQueue()) //checks if borrowedBooks was emptied by saveQueue
{
  cout << borrowedBooks.front() << endl;
  borrowedBooks.deleteQueue();
}

b1.setBorrower("Me");
borrowedBooks.addQueue(b1);
saveQueue(out, borrowedBooks); //restore Borrowed.txt to its original state

in.close();
out.close();
cout << "end" << endl;
/*test*/

  return 0;
}//end of main

void loadQueue(ifstream& in, linkedQueueType<Book>& queue) //needs to be run once
							   //before new borrows are added
{

  Book temp;
  char c;

  while(in)
  {

    in >> temp;
    if(temp.getBorrowed() == true) //make sure this book should be in the queue (it is borrowed)
    {
      queue.addQueue(temp);
    }
    else //otherwise temp is not added to the queue
    {
      cout << "Error! " << temp.getTitle() << " should not be in the borrowed queue" << endl
	   << "because it is not checked out. It will not be loaded from the file." << endl << endl;
    }
    in.get(c); //check for another entry (takes a char off a label (harmeless)) otherwise
               //indicates eof to the while
  }
  //when save is run it will overwrite any erroneous entries left in the file

}

void saveQueue(ofstream& out, linkedQueueType<Book> queue)//must run before program ends
							  //will overwrite Borrowed.txt
{
  //forcing a load here could append older borrowed books to the end of the user's working queue
  //so the programmer must be resposible for calling an initial load before any
  //calls to addQueue or saveQueue

  while(!queue.isEmptyQueue())
  {
    if(queue.front().getBorrowed() == true) //make sure this book should be in the queue (it is borrowed)
    {
      out << queue.front(); //if it is borrowed write it out
    }
    else
    {
      cout << "Error! " << queue.front().getTitle() << " should not be in the borrowed queue" << endl
	   << "because it is not checked out. It will not be written to the file." << endl << endl;
    }

    queue.deleteQueue(); //either way, remove front item from the queue
  }


}

