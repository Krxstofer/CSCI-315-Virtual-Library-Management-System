//Name: Garrett Comstock, Andrew Palermo, Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//AdminTests.cpp: file for testing the admin menu functions

#include <iostream>
#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "hash.h"
#include "user.h"
#include "nullBuffer.h"
#include "AdminFun.h"
#include "UserFun.h"
#include <gtest/gtest.h>
//#include "gtest/gtest.h" //depending on how you get you google test libraries, "" are sometimes used.

//#include <stdexcept>  // Include for std::runtime_error
//#include <cstdlib>    // Include for exit()

TEST(LibraryTest, addBook) //Test for addBook function
{
    bSearchTreeType<Book> bookTree;
    Book b2("Idea Today", "John", "Doe", 2020, "Jefferson's Best", "DOJ", false);
    istringstream newBook("Idea Today\nJohn\nDoe\n2020\nJefferson's Best\nDOJ");
    Book temp = *addBook(bookTree, newBook, false);
    EXPECT_EQ("Idea Today", temp.getTitle());
    EXPECT_EQ("John", temp.getFirstName());
    EXPECT_EQ("Doe", temp.getLastName());
    EXPECT_EQ(2020, temp.getCopyright());
    EXPECT_EQ("Jefferson's Best", temp.getPublisher());
    EXPECT_EQ("DOJ", temp.getId());
    EXPECT_EQ(false, temp.getBorrowed());
    EXPECT_EQ("N/A", temp.getBorrower());

    istringstream real("Idea Today");
    EXPECT_TRUE(searchBook(bookTree, real, false));
}

TEST(LibraryTest, removeBook) //Test for removeBook function
{
    linkedQueueType<Book> borrowedBooks;
    bSearchTreeType<Book> bookTree;
    Book b1("Today", "Jane", "Doe", 1780, "Miller and Sons", "1-566-46465-5", false);
    Book b2("Idea Today", "John", "Doe", 2020, "Jefferson's Best", "DOJ", false);
    Book b3("A Test of Test", "Phil", "Doe", 2024, "Plublish co.", "DOP", false);
    bookTree.insert(b1);
    bookTree.insert(b2);
    bookTree.insert(b3);
    User me("This_Guy", "Password123", "user");
    istringstream borrow1("Idea Today");
    istringstream borrow2("Today");
    EXPECT_TRUE(borrowBook(bookTree, borrowedBooks, me, borrow1, false));
    EXPECT_TRUE(borrowBook(bookTree, borrowedBooks, me, borrow2, false));

    istringstream remove1("Today");
    istringstream remove2("Idea Today\nn");
    istringstream remove3("Idea Today\ny");
    istringstream remove33("Idea Today");
    istringstream remove4("Today\ny");
    istringstream remove44("Today");
    istringstream remove5("Not A Real Title");


    // True = removed, False = Not removed
    EXPECT_FALSE(removeBook(bookTree, borrowedBooks, remove1, false)); //Test to see how it treats the removal of a borrowed book, that is NOT in the front of the queue.
    EXPECT_FALSE(removeBook(bookTree, borrowedBooks, remove2, false)); //Test to see how it treats the removal of a borrowed book, that is in the front of the queue. Says No
    EXPECT_TRUE(searchBook(bookTree, remove33, false));
    EXPECT_TRUE(removeBook(bookTree, borrowedBooks, remove3, false));  //Test to see how it treats the removal of a borrowed book, that is in the front of the queue. Says Yes
    EXPECT_FALSE(searchBook(bookTree, remove33, false));
    EXPECT_TRUE(removeBook(bookTree, borrowedBooks, remove4, false));  //Test to see how it treats the removal of a borrowed book, that is NOT in the front of the queue.
    EXPECT_FALSE(searchBook(bookTree, remove44, false));
    EXPECT_FALSE(removeBook(bookTree, borrowedBooks, remove5, false)); //Test to see how it treats the attempt removal of a book that is not in the tree
}

TEST(LibraryTest, updateBookInfo) //Test for updateBookInfo function
{
    bSearchTreeType<Book> bookTree;
    Book b("Idea Today", "John", "Doe", 2020, "Jefferson's Best", "DOJ", false);
    bookTree.insert(b);

    //Varifies that the book set as expected:
    EXPECT_EQ("Idea Today", bookTree.search(b)->getTitle());
    EXPECT_EQ("John", bookTree.search(b)->getFirstName());
    EXPECT_EQ("Doe", bookTree.search(b)->getLastName());
    EXPECT_EQ(2020, bookTree.search(b)->getCopyright());
    EXPECT_EQ("Jefferson's Best", bookTree.search(b)->getPublisher());
    EXPECT_EQ("DOJ", bookTree.search(b)->getId());

    istringstream update("Idea Today\n1\nIdea Yesterday\n2\nJane\nMoe\n3\n1950\n4\nPublishing co.\n5\nMOJ\n6"); //Sets input for update
    b = *updateBookInfo(bookTree, update, false);         //Updates the title, author's first and last name, copyright year, 

    EXPECT_EQ("Idea Yesterday", b.getTitle());            //Varifies that the book title is "Idea Yesterday"
    EXPECT_EQ("Jane", b.getFirstName());                  //Varifies that the author's first name is "Jane"
    EXPECT_EQ("Moe", b.getLastName());                    //Varifies that the author's last name is "Moe"
    EXPECT_EQ(1950, b.getCopyright());                    //Varifies that the copyright year is "1950"
    EXPECT_EQ("Publishing co.", b.getPublisher());        //Varifies that the publisher is "Publishing co."
    EXPECT_EQ("MOJ", b.getId());                          //Varifies that the ID is "MOJ"

    istringstream badTitle("Not A Book In The Tree");
    EXPECT_EQ(NULL, updateBookInfo(bookTree, badTitle, false)); //Checks what happens if the book they want to edit does not exist
}

TEST(LibraryTest, addRemoveUsers)
{
  HashTable hash;
  User test1("NotAd", "not1", "user");
  User test2("TestUser1", "t1", "user");
  hash.insertUser(test1);
  hash.insertUser(test2);
  //input for add user
  std::istringstream fake_input1("1\nTestAdmin1\nt1\nt1\n");
  std::istringstream fake_input2("0\nt\n1\nTestAdmin2\nt2\nt2\n");
  std::istringstream fake_input3("1\nTestAdmin2\nTestAdmin1\nTestAdmin3\nt3\nt3\n");
  std::istringstream fake_input4("1\nTestAdmin4\nt4\nt2\nt4\nt4\n");
  
  //input for remove admin
  std::istringstream fake_input5("2\n0\nt\n1\nTestAdmin4\nt4\n");
  std::istringstream fake_input6("2\n1\nTestAdmin3\nt6\n");
  std::istringstream fake_input7("2\n1\nNotAd\nt7\n");

  //input to remove user
  std::istringstream fake_input8("2\n2\nTestUser1\nt1\n");
  std::istringstream fake_input9("2\n2\nNotAd\nt1\n");
  std::istringstream fake_input10("2\n2\nTestAdmin1\nt1\n");

  //input for exiting
  std::istringstream fake_input11("3\n1\nTestAdmin11\nt11\nt11\n");


  //Check the add functionality
  //1. Test that Admin is correctly added to the hash
  addOrRemoveUser(hash, fake_input1, false); //returns true for a successful registration
  EXPECT_TRUE(hash.checkPassword("TestAdmin1", "t1"));

  //2. Test that addRemoveUsers can recover from bad input (0,t)
  addOrRemoveUser(hash, fake_input2, false);
  EXPECT_TRUE(hash.checkPassword("TestAdmin2", "t2"));

  //3. Test that addRemoveUsers (add) can handle when a username has already been taken
  addOrRemoveUser(hash, fake_input3, false);
  ASSERT_TRUE(hash.checkPassword("TestAdmin3", "t3")); //needed for test 6

  //4. Test that registerUser (add) can handle a bad password confirmation and recover
  addOrRemoveUser(hash, fake_input4, false);
  ASSERT_TRUE(hash.checkPassword("TestAdmin4", "t4")); //needed for next test


  //Check the remove functionality for admin
  //5. Test that can recover from bad input (0,t) and that TestAdmin4 is correctly removed 
  //from the hash
  addOrRemoveUser(hash, fake_input5, false);
  EXPECT_FALSE(hash.checkPassword("TestAdmin4", "t4"));

  //6. Test that the admin is not removed if the password is wrong
  addOrRemoveUser(hash, fake_input6, false);
  EXPECT_TRUE(hash.checkPassword("TestAdmin3", "t3"));

  //7. Test that the username entered belongs to an Admin otherwise do not remove
  addOrRemoveUser(hash, fake_input7, false);
  ASSERT_TRUE(hash.checkPassword("NotAd", "not1")); //needed for test 9


  //Check the remove functionality for user
  //8. Test that user TestUser1 is correctly removed from the hash
  EXPECT_TRUE(hash.checkPassword("TestUser1", "t1"));
  addOrRemoveUser(hash, fake_input8, false);
  EXPECT_FALSE(hash.checkPassword("TestUser1", "t1"));

  //9. Test that the user is not removed if the password is wrong
  addOrRemoveUser(hash, fake_input9, false);
  EXPECT_TRUE(hash.checkPassword("NotAd", "not1"));

  //10. Test that the username entered belongs to a user otherwise do not remove
  addOrRemoveUser(hash, fake_input10, false);
  EXPECT_TRUE(hash.checkPassword("TestAdmin1", "t1"));


  //11. Test that 3 exits the menu without adding a user
  addOrRemoveUser(hash, fake_input11, false);
  EXPECT_FALSE(hash.checkPassword("TestAdmin11", "t11"));


}
