#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;
public:
    User(const std::string& uname, const std::string& pwd);
    std::string getUsername() const;
    std::string getPassword() const;
};

#endif 
