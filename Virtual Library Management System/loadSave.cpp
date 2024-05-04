#include <fstream>
#include <sstream>
#include "loadSave.h"
#include "user.h"
#include "hash.h"

void LoadSave::saveData(const HashTable& ht, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing." << std::endl;
        return;
    }

    // Access to hashGroups and usersTable is modified to use accessor functions instead of direct access due to privacy
        for (int i = 0; i < HashTable::hashGroups; ++i) {
        for (const auto& user : ht.usersTable[i]) {
            file << user.getUsername() << "," << user.getPassword() << "," << user.getRole() << std::endl;
        }
    }

    file.close();
}

void LoadSave::loadData(HashTable& ht, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for reading." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, password, role;

        std::getline(iss, username, ',');
        std::getline(iss, password, ',');
        std::getline(iss, role);

        ht.insertUser(User(username, password, role));
    }

    file.close();
}