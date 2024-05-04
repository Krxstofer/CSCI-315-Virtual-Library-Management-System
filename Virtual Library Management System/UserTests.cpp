//Name: Garrett Comstock, Andrew Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//UserTests.cpp: file for testing functions from the user menu

#include <iostream>
#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "LoadSave.h"
#include "UserFun.h"
#include <gtest/gtest.h>

#include <stdexcept>  // Include for std::runtime_error

using namespace std;

TEST(LibraryTest, searchBook) //Test for searchBook function
{
    bSearchTreeType<Book> bookTree;
    Book b1("Today", "Jane", "Doe", 1780, "Miller and Sons", "1-566-46465-5", false);
    Book b2;
    Book b3("Idea Today", "John", "Doe", 2020, "Jefferson's Best", "DOJ", false);
    bookTree.insert(b1);
    bookTree.insert(b2);
    bookTree.insert(b3);

    istringstream real("Idea Today");
    istringstream fake("Idea Tomorrow");

    EXPECT_TRUE(searchBook(bookTree, real, false));
    EXPECT_FALSE(searchBook(bookTree, fake, false));
}

TEST(LibraryTest, borrowBook) //Test for borrowBook function
{
    User me("This_Guy", "Password123", "user");
    string real = "Idea Today";
    linkedQueueType<Book> borrowedBooks;
    bSearchTreeType<Book> bookTree;
    Book b1("Today", "Jane", "Doe", 1780, "Miller and Sons", "1-566-46465-5", false);
    Book b2("Idea Today", "John", "Doe", 2020, "Jefferson's Best", "DOJ", false);
    bookTree.insert(b1);
    bookTree.insert(b2);

    istringstream borrow("Idea Today");
    istringstream notARealBook("Idea Tomorrow");


    EXPECT_TRUE(borrowBook(bookTree, borrowedBooks, me, borrow, false));        //Borrows book
    EXPECT_EQ(me.getUsername(), borrowedBooks.front().getBorrower());           //Tells us if the new book is actully borrowed with correct info
    EXPECT_FALSE(borrowBook(bookTree, borrowedBooks, me, borrow, false));       //Tries to borrow the same book again
    EXPECT_FALSE(borrowBook(bookTree, borrowedBooks, me, notARealBook, false)); //Tries to borrow a book that isn't in the library
}

TEST(LibraryTest, returnBook) //Test for returnBook function
{
    User me("This_Guy", "Password123", "user");
    User you("That_Guy", "Password789", "user");
    linkedQueueType<Book> borrowedBooks;
    bSearchTreeType<Book> bookTree;
    Book b1("Today", "Jane", "Doe", 1780, "Miller and Sons", "1-566-46465-5", false);
    Book b2("Idea Today", "John", "Doe", 2020, "Jefferson's Best", "DOJ", false);
    bookTree.insert(b1);
    bookTree.insert(b2);
    istringstream borrow1("Idea Today");
    EXPECT_TRUE(borrowBook(bookTree, borrowedBooks, me, borrow1, false));  //Setting Borrower of b1
    istringstream borrow2("Today");
    EXPECT_TRUE(borrowBook(bookTree, borrowedBooks, you, borrow2, false)); //Setting Borrower of b2

    EXPECT_TRUE(returnBook(bookTree, borrowedBooks, me, false));   //Correct user returning book b1
    EXPECT_FALSE(returnBook(bookTree, borrowedBooks, me, false));  //Wrong user trying to return book b2
    EXPECT_TRUE(returnBook(bookTree, borrowedBooks, you, false));  //Correct user returning book b2
    EXPECT_FALSE(returnBook(bookTree, borrowedBooks, you, false)); //User returning book when there are no more books in the queue
}

TEST(LibraryTest, updateProfile)
{
    HashTable hash;
    User myUser("Ph1n3as", "S3cr3t", "User");

    istringstream testUsername("1\nW1nn1f3r\n");
    istringstream testPassword("2\nM3@oo6\nM3@oo6\n");
    istringstream testCancel("3\n");

    //Checking data before updating
    EXPECT_EQ("Ph1n3as", myUser.getUsername());
    EXPECT_EQ("S3cr3t", myUser.getPassword());

    updateProfile(hash, myUser, testUsername, false);

    //Checking data after updating username
    EXPECT_EQ("W1nn1f3r", myUser.getUsername());
    EXPECT_EQ("S3cr3t", myUser.getPassword());

    updateProfile(hash, myUser, testPassword, false);

    //Checking data after updating password
    EXPECT_EQ("W1nn1f3r", myUser.getUsername());
    EXPECT_EQ("M3@oo6", myUser.getPassword());

    updateProfile(hash, myUser, testCancel, false);

    //Checking data after cancling
    EXPECT_EQ("W1nn1f3r", myUser.getUsername());
    EXPECT_EQ("M3@oo6", myUser.getPassword());
}
