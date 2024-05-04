#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "LoadSave.h"
#include "UserFun.h"
#include "AdminFun.h"
#include "GeneralFunctions.h"
#include "user.h"
#include "hash.h"
#include <gtest/gtest.h>

TEST(LibraryTest, IntegrationTest)
{
    HashTable userDatabase;
    linkedQueueType<Book> borrowedBooks;
    bSearchTreeType<Book> bookCatalog;
    //User testUser("Some_Guy", "BestPassword", "user");
    User user("", "", "user");
    User testAdmin("Some_Gal", "GreatPassword", "admin");

    istringstream reg("1\nTest_Username\nTest_Password\nTest_Password\n");
    EXPECT_TRUE(registerUser(userDatabase, user, reg, false)); //Register user test

    EXPECT_EQ("Test_Username", user.getUsername());
    EXPECT_EQ("Test_Password", user.getPassword());

    istringstream usernameUpdate("1\nTest_Username2\n");
    istringstream passwordUpdate("2\nTest_Password2\nTest_Password2\n");

    updateProfile(userDatabase, user, usernameUpdate, false);
    updateProfile(userDatabase, user, passwordUpdate, false);

    EXPECT_EQ("Test_Username2", user.getUsername());
    EXPECT_EQ("Test_Password2", user.getPassword());

    istringstream newBook("Test_Title\nJohn\nDoe\n2024\nPublisher co.\n123456789");
    Book compBook("Test_Title", "John", "Doe", 2024, "Publisher co.", "123456789");
    EXPECT_EQ(compBook, *addBook(bookCatalog, newBook, false)); //check's to varify that the addbook correctly creates a book

    istringstream real1("Test_Title");
    EXPECT_TRUE(searchBook(bookCatalog, real1, false)); //Varifies book in the the tree

    Book compBook2("Test_Title2", "Jane", "Moe", 2025, "Published co.", "987654321");
    istringstream update("Test_Title\n1\nTest_Title2\n2\nJane\nMoe\n3\n2025\n4\nPublished co.\n5\n987654321\n6");
    EXPECT_EQ(compBook2, *updateBookInfo(bookCatalog, update, false));

    istringstream real2("Test_Title2\n");
    EXPECT_TRUE(searchBook(bookCatalog, real2, false)); //Varifies book in the the tree with updated info

    istringstream bor("Test_Title2\n");
    EXPECT_TRUE(borrowBook(bookCatalog, borrowedBooks, user, bor, false));  //Checks if borrow was successful

    EXPECT_EQ("Test_Username2", bookCatalog.search(compBook2)->getBorrower()); //Varifies borrower is set to username
    EXPECT_FALSE(borrowedBooks.isEmptyQueue()); //test to verify that queue contains borrowed book

    EXPECT_TRUE(returnBook(bookCatalog, borrowedBooks, user, false)); //Checks if return is successful

    EXPECT_NE("Test_Username2", bookCatalog.search(compBook2)->getBorrower()); //Varifies borrower is no longer the user

    EXPECT_TRUE(borrowedBooks.isEmptyQueue()); //test to verify that queue contains no borrowed book

    istringstream rem("Test_Title2\ny\n");
    EXPECT_TRUE(removeBook(bookCatalog, borrowedBooks, rem, false));

}