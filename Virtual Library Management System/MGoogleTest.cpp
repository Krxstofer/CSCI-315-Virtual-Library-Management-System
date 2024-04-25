//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//MGoogleTest.cpp: file for testing the Book object, linked queue, binary search tree,
//registerUser(), addRemoveUser(), and logout()

#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
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
  ifstream i;
  ofstream o;

  o.open("Library.txt"); //storage file for books
  o << b1;
  o << b2;

  i.open("Library.txt");
  i >> temp;
  EXPECT_EQ(temp, b1);
  i >> temp;
  EXPECT_EQ(temp, b2);

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

TEST(LibraryTest, Queue)
{

}

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
