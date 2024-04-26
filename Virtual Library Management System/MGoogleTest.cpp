//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//MGoogleTest.cpp: file for testing the Book object, linked queue, binary search tree,
//registerUser(), addRemoveUser(), and logout()

#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "LoadSave.h"
#include <gtest/gtest.h>

TEST(LibraryTest, Book)
{
  Book b1("Today","John", "Doe", 1780, "Miller and Sons", "1-566-46465-5", false);
  Book b2("An Idea Today","Sam", "Smith", 1890, "Ideaonics", "1-741-09565-4", true);
  Book temp;
  string firstName, lastName, title, publisher, id, borrower;
  int copyright;

  //test constructor's setting of borrower member variables
  EXPECT_EQ("N/A", b1.getBorrower());
  EXPECT_EQ("", b2.getBorrower());

  //test file writing and reading
  ifstream in;
  ofstream out;

  out.open("BookTest.txt"); //create/overwrite file
  out << b1;
  out << b2;

  in.open("BookTest.txt");
  in >> temp;
  EXPECT_EQ(temp, b1);
  in >> temp;
  EXPECT_EQ(temp, b2);

  in.close();
  out.close();
  //test getters and setters
  firstName = "Frances";

  lastName = "Hodgson Burnett";
  title = "The Secret Garden";
  copyright = -32;
  publisher = "Penguin";
  id = "HOD";
  borrower = "Me";

  temp.setFirstName(firstName);
  temp.setLastName(lastName);
  temp.setTitle(title);
  temp.setCopyright(copyright);//out of bounds should come through as 0
  temp.setPublisher(publisher);
  temp.setId(id);
  temp.setBorrower(borrower); //sets borrowed and borrower

  EXPECT_EQ(firstName, temp.getFirstName());
  EXPECT_EQ(lastName, temp.getLastName());
  EXPECT_NE(title, temp.getTitle()); //Title is processed
  EXPECT_EQ("Secret Garden, The", temp.getTitle()); //Title is processed
  EXPECT_EQ(0, temp.getCopyright()); //copyright should have been reset
  copyright = 1880; //set copyright to reasonable date
  temp.setCopyright(copyright);
  EXPECT_EQ(copyright, temp.getCopyright());//should match now
  EXPECT_EQ(publisher, temp.getPublisher());
  EXPECT_EQ(id, temp.getId());
  EXPECT_TRUE(temp.getBorrowed());
  EXPECT_EQ(borrower, temp.getBorrower());

  //test return book
  b1.returnBook();
  b2.returnBook();

  EXPECT_FALSE(b1.getBorrowed());
  EXPECT_FALSE(b2.getBorrowed());

  EXPECT_EQ("N/A", b1.getBorrower());
  EXPECT_EQ("N/A", b2.getBorrower());

}

//could maybe use fixture class for redundant data
TEST(LibraryTest, QueueIO)
{
  ifstream in;
  ofstream out;
  int i = 0;
  char c = 'M';
  linkedQueueType<Book> borrowedBooks;
  Book b1("A Tale of Two Cities", "Charles", "Dickens", 1990, "Wordsworth", "DIC", true, "Me");
  Book b2("A Christmas Carol", "Charles", "Dickens", 1992, "Wordsworth", "DIC", true, "You");
  Book tempBook, books[2]; //for testing EXPECT_EQ in a while loop

  books[0] = b1;
  books[1] = b2;

  //Test loadQueue()
  out.open("QueueTest.txt");
  out << b1 << b2; //prime file

  in.open("QueueTest.txt");

  loadQueue(in, borrowedBooks);
  in.close();

  ASSERT_FALSE(borrowedBooks.isEmptyQueue());//do not traverse an empty queue
  while(!borrowedBooks.isEmptyQueue()) //check queue has the expected contents
  {
    EXPECT_EQ(books[i], borrowedBooks.front());
    borrowedBooks.deleteQueue(); //remove front item from the queue
    i++;
  }
  i = 0;

  //Test saveQueue
  //check that queue is empty before adding
  EXPECT_TRUE(borrowedBooks.isEmptyQueue());
  borrowedBooks.addQueue(b1);
  borrowedBooks.addQueue(b2);

  //Check that the Queue is full before saving
  ASSERT_FALSE(borrowedBooks.isEmptyQueue());
  saveQueue(out, borrowedBooks);
  out.close();

  //Test that borrowedBooks is unchanged after saveQueue and
  //test that the text file now contains the queue
  in.open("QueueTest.txt"); //reset in to top of the file

  ASSERT_FALSE(borrowedBooks.isEmptyQueue());
  while(!borrowedBooks.isEmptyQueue())
  {
    in >> tempBook;
    EXPECT_EQ(tempBook, borrowedBooks.front());
    borrowedBooks.deleteQueue();
    i++;
  }
  in.close();
  i = 0;
  //check that queue is now empty
  ASSERT_TRUE(borrowedBooks.isEmptyQueue());

  //Test saveQueue's borrowed == false excluder
  b1.returnBook();
  borrowedBooks.addQueue(b1); 
  borrowedBooks.addQueue(b2);//testing addQueue where borrowed = true

  out.open("QueueTest.txt");//reset

  ASSERT_FALSE(borrowedBooks.isEmptyQueue());
  saveQueue(out, borrowedBooks);

  in.open("QueueTest.txt");
  in >> tempBook; //check for b1 not being in file
  EXPECT_EQ(tempBook, b2); //first book input is b2

  in.get(c); //check for eof now
  EXPECT_TRUE(in.eof());

  in.close();
  out.close();
}//end of QueueIO

TEST(LibraryTest, QueueFuncs)
{
  int i = 0;
  linkedQueueType<Book> temp, copy, borrowedBooks;
  Book b1("A Tale of Two Cities", "Charles", "Dickens", 1990, "Wordsworth", "DIC", true, "Me");
  Book b2("A Christmas Carol", "Charles", "Dickens", 1992, "Wordsworth", "DIC", true, "You");
  Book books[2]; //for testing EXPECT_EQ in a while loop
  
  books[0] = b1;
  books[1] = b2;

  borrowedBooks.addQueue(b1);
  borrowedBooks.addQueue(b2);
  
  temp = copy = borrowedBooks; //save bB and check user-defined assignment operator

  //Test whether = emptied or changed borrowed books
  ASSERT_FALSE(borrowedBooks.isEmptyQueue()); //do not traverse an empty queue
  while(!borrowedBooks.isEmptyQueue()) //check queue
  {
    EXPECT_EQ(books[i], borrowedBooks.front());
    borrowedBooks.deleteQueue(); //remove front item from the queue
    i++;
  }
  i = 0;

  //Test operator=
  ASSERT_FALSE(temp.isEmptyQueue());
  while(!temp.isEmptyQueue()) //view queue
  {
    EXPECT_EQ(books[i], temp.front());
    temp.deleteQueue(); //remove front item from the queue
    i++;
  }
  i = 0;

  //Test new queue being copy-constructor-initialzed
  linkedQueueType<Book> temp2(copy);
  ASSERT_FALSE(temp2.isEmptyQueue());
  while(!temp2.isEmptyQueue())
  {
    EXPECT_EQ(books[i], temp2.front());
    temp2.deleteQueue();
    i++;
  }
  i = 0;

 //Test copy-constructor-initialzation with an empty queue
  ASSERT_TRUE(temp.isEmptyQueue());
  linkedQueueType<Book> temp3(temp);
  EXPECT_TRUE(temp3.isEmptyQueue());

  //Test overloaded assignment operator with an empty queue
  ASSERT_TRUE(temp.isEmptyQueue());
  temp2 = temp;
  EXPECT_TRUE(temp2.isEmptyQueue());

  //Overloaded assignment operator with two empty queues
  ASSERT_TRUE(temp.isEmptyQueue());
  temp3 = temp; //two empty queues
  EXPECT_TRUE(temp3.isEmptyQueue());

} //end of QueueFuncs

TEST(LibraryTest, Tree)
{

}

/*

TEST(LibraryTest, Register)
{

}

TEST(LibraryTest, addRemoveUsers)
{

}

TEST(LibraryTest, Logout)
{

}
*/
