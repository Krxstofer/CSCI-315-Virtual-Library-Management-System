//Name: Jeffrey Zoebisch, Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//GeneralTests.cpp: file for testing the functions which are used in neither
//the user menu or the admin menu or are used in both

#include <iostream>
#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "LoadSave.h"
#include "GeneralFunctions.h"
#include "hash.h"
#include "user.h"
#include <gtest/gtest.h>

#include <stdexcept>  // Include for std::runtime_error
#include <cstdlib>    // Include for exit()

TEST(LibraryTest, Register)
{
  HashTable hash;
  User test("", "", "user");
  std::istringstream fake_input1("1\nTestUser1\nt1\nt1\n");
  std::istringstream fake_input2("2\nTestUser2\nt2\nt2\n");
  std::istringstream fake_input3("0\nt\n1\nTestUser3\nt3\nt3\n");
  std::istringstream fake_input4("1\nTestUser1\nTestUser4\nt4\nt4\n");
  std::istringstream fake_input5("1\nTestUser5\nt5\nt2\nt5\nt5\n");

  //1. Test that user is correctly added to the hash
  EXPECT_TRUE(registerUser(hash, test, fake_input1, false)); //returns true for a successful registration
  EXPECT_TRUE(hash.checkPassword("TestUser1", "t1")); //is user in the hash now?
  EXPECT_EQ("TestUser1", test.getUsername()); //is the proper username set and returned?
  EXPECT_EQ("t1", test.getPassword()); //is the proper password set and returned?

  //2. Test that 2 exits the menu without inputting a new user
  EXPECT_FALSE(registerUser(hash, test, fake_input2, false));
  EXPECT_FALSE(hash.checkPassword("TestUser2", "t2"));
  EXPECT_NE("TestUser2", test.getUsername());
  EXPECT_NE("t2", test.getPassword());

  //3. Test that registerUser can recover from bad input (0,t)
  EXPECT_TRUE(registerUser(hash, test, fake_input3, false));
  EXPECT_TRUE(hash.checkPassword("TestUser3", "t3"));
  EXPECT_EQ("TestUser3", test.getUsername());
  EXPECT_EQ("t3", test.getPassword());

  //4. Test that registerUser can handle when a username has already been taken
  EXPECT_TRUE(registerUser(hash, test, fake_input4, false));
  EXPECT_TRUE(hash.checkPassword("TestUser4", "t4"));
  EXPECT_EQ("TestUser4", test.getUsername());
  EXPECT_EQ("t4", test.getPassword());

  //5. Test that registerUser can handle a bad password confirmation and recover
  EXPECT_TRUE(registerUser(hash, test, fake_input5, false));
  EXPECT_TRUE(hash.checkPassword("TestUser5", "t5"));
  EXPECT_EQ("TestUser5", test.getUsername());
  EXPECT_EQ("t5", test.getPassword());

}


TEST(LibraryTest, Logout)
{
  ifstream qIn, tIn;
  ofstream qOut; //tOut is in LoadSave
  linkedQueueType<Book> queue;
  bSearchTreeType<Book> tree;
  Book temp, test1("Tada!", "Logout" "Test"), test2("The Last", "John", "Doe");
  int i = 0;
  char c;

  test1.setBorrower("Test");
  test2.setBorrower("Testing");

  //prime queue file
  qOut.open("qLog.txt");
  qOut << test1 << test2;
  //load queue
  qIn.open("qLog.txt");
  loadQueue(qIn, queue);
  qOut.close(); //qIn will be closed in logout
  ASSERT_FALSE(queue.isEmptyQueue());

  //prime tree file
  tOut.open("tLog.txt");
  tOut << test1 << test2;
  //load tree
  tIn.open("tLog.txt");
  loadTree(tIn, tree);
  tOut.close(); //tIn will be closed in logout
  ASSERT_FALSE(tree.isEmpty());

  //Test that logout saved the data correctly
  logout(qIn, "qLog.txt", tIn, "tLog.txt", queue, tree, false); //closes the ifstream variables

  qIn.open("qLog.txt");
  qIn.get(c); //check for eof
  ASSERT_FALSE(qIn.eof());
  ASSERT_FALSE(queue.isEmptyQueue());
  while(!queue.isEmptyQueue())
  {
    qIn >> temp;
    EXPECT_EQ(temp, queue.front());
    queue.deleteQueue();
    i++;
  }
  i = 0;
  qIn.get(c); //check for eof
  EXPECT_TRUE(qIn.eof());
  qIn.close();

  tIn.open("tLog.txt");
  tIn.get(c); //check for eof
  ASSERT_FALSE(tIn.eof());
  ASSERT_FALSE(tree.isEmpty());
  tIn >> temp;
  EXPECT_EQ(temp, *(tree.search(test2)) ); //books were written to file alphabetically
  tIn >> temp;
  EXPECT_EQ(temp, *(tree.search(test1)) );
  tIn.get(c); //check for eof
  EXPECT_TRUE(tIn.eof());

  tIn.close();
}


// exit_function_test.cpp

// Test part
TEST(LibraryTest, ExitFunction) {
    try {
        exitApplication(true);  // Call with test mode true to throw exception instead of exiting
        FAIL() << "Expected std::runtime_error";
    } catch (std::runtime_error const & err) {
        EXPECT_EQ(err.what(), std::string("Exit called during test mode"));
    } catch (...) {
        FAIL() << "Caught unexpected exception type";
    }
}
//LoginTest.cpp
#include <gtest/gtest.h>
#include "GeneralFunctions.h"
#include "hash.h"
#include "user.h"

class LibraryTest : public ::testing::Test {
protected:
    HashTable ht;

    void SetUp() override {
        ht.insertUser(User("Alice", "alice123", "admin"));
        ht.insertUser(User("Bob", "bob456", "standard"));
    }

    void TearDown() override {
        // Optional: Clear the hash table if necessary
    }
};

TEST_F(LibraryTest, SuccessfulLoginAdmin) {
    std::string expected = "admin";
    std::string result = login(ht, "Alice", "alice123", false);
    ASSERT_EQ(expected, result);
}

TEST_F(LibraryTest, SuccessfulLoginStandard) {
    std::string expected = "standard";
    std::string result = login(ht, "Bob", "bob456", false);
    ASSERT_EQ(expected, result);
}

TEST_F(LibraryTest, FailedLoginIncorrectPassword) {
    std::string result = login(ht, "Alice", "wrongpassword", false);
    ASSERT_TRUE(result.empty());
}

TEST_F(LibraryTest, FailedLoginNonExistentUser) {
    std::string result = login(ht, "Charlie", "any123", false);
    ASSERT_TRUE(result.empty());
}

TEST_F(LibraryTest, VerboseOutputCheck) {
    testing::internal::CaptureStdout();
    login(ht, "Alice", "alice123", true);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
    ASSERT_NE(output.find("Login successful"), std::string::npos);
}
//UserTest.cpp
#include <gtest/gtest.h>
#include <sstream>
#include "user.h"

class LibraryTest : public ::testing::Test {
protected:
    User adminUser;
    User standardUser;

    LibraryTest() : adminUser("admin", "adminpass", "admin"), standardUser("user", "userpass", "standard") {}

    virtual void SetUp() {
        // This can be used if any setup before each test is needed
    }

    virtual void TearDown() {
        // This can be used if any cleanup after each test is needed
    }
};

TEST_F(LibraryTest, ConstructorTest) {
    User newUser("newuser", "newpass", "standard");
    ASSERT_EQ("newuser", newUser.getUsername());
    ASSERT_EQ("newpass", newUser.getPassword());
    ASSERT_EQ("standard", newUser.getRole());
}

TEST_F(LibraryTest, SettersAndGetters) {
    adminUser.setUsername("newadmin");
    adminUser.setPassword("newpass");

    ASSERT_EQ("newadmin", adminUser.getUsername());
    ASSERT_EQ("newpass", adminUser.getPassword());
}

TEST_F(LibraryTest, DisplayMenuOutput) {
    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    // Testing admin menu
    adminUser.displayMenu();
    std::string adminOutput = buffer.str();
    std::cout.rdbuf(oldCoutStreamBuf);  // Reset to standard output
    ASSERT_TRUE(adminOutput.find("Admin Dashboard") != std::string::npos);

    buffer.str(""); // Clear buffer
    buffer.clear();

    // Testing standard user menu
    std::cout.rdbuf(buffer.rdbuf()); // Redirect std::cout to buffer again
    standardUser.displayMenu();
    std::string userOutput = buffer.str();
    std::cout.rdbuf(oldCoutStreamBuf); // Reset to standard output
    ASSERT_TRUE(userOutput.find("Welcome user") != std::string::npos);
}
