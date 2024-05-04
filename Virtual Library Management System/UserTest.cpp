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
