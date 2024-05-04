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
