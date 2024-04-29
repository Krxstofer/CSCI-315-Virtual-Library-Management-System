#include "User.h"
#include "UserFactory.h"
#include <unordered_map>

// Global variable for user storage
unordered_map<string, pair<string, string>> userDatabase = {
    {"john_doe", {"12345", "user"}},
    {"admin_user", {"adminpass", "admin"}}
};

// Function to handle user login
User* login(const string& username, const string& password) {
    auto it = userDatabase.find(username);
    if (it != userDatabase.end() && it->second.first == password) {
        return UserFactory::createUser(username, password, it->second.second);
    }
    return nullptr;
}

int main() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    User* user = login(username, password);
    if (user) {
        user->displayMenu();
        delete user;  // Clean up the created user object
    } else {
        cout << "Invalid username or password!" << endl;
    }

    return 0;
}
