#pragma once
#include <iostream>
#include <string>
#include "hash.h"  // Include the hash table that contains the user credentials and login method

bool login(HashTable& ht, const std::string& username, const std::string& password);

