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
