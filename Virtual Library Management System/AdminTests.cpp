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
#include <gtest/gtest.h>

//#include <stdexcept>  // Include for std::runtime_error
//#include <cstdlib>    // Include for exit()

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
