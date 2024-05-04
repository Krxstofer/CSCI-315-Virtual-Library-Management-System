#pragma once
#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include "hash.h"

class LoadSave {
public:
    static void saveData(const HashTable& ht, const std::string& filename);
    static void loadData(HashTable& ht, const std::string& filename);
};

#endif 