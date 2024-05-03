#pragma once
#include <iostream>
#include <string>
#include "hash.h"  // Includes the HashTable class definition

// Adjust the function to return a string (role)
std::string login(HashTable& ht, const std::string& username, const std::string& password);
