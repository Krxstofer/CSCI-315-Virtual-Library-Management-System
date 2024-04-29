#ifndef ADMIN_H
#define ADMIN_H

#include "hashTableUser.h"

class Admin : public User {
public:
    Admin(const std::string& uname, const std::string& pwd);
};

#endif 
