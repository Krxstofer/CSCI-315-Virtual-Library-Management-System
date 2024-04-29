#include "user.h"

User::User(const std::string& uname, const std::string& pwd) : username(uname), password(pwd) {}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}
