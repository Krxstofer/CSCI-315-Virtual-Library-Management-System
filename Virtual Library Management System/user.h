// User.h
#pragma once
#include <iostream>
#include <string>

class User {
public:
    User(const std::string& username, const std::string& password, const std::string& role);
    virtual ~User() {}

    void displayMenu(); // Function to display the menu based on the user role

    // Getters
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getRole() const;

    // Setters
    void setUsername(const std::string& newUsername);
    void setPassword(const std::string& newPassword);
    void setRole(const std::string& newRole);

private:
    std::string username;
    std::string password;
    std::string role;
};
