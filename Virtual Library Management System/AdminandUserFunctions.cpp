#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class User {
public:
    string username;
    string password;
    string role;

    User(string username, string password, string role)
        : username(username), password(password), role(role) {}

    virtual void displayMenu() = 0;
    virtual ~User() {}
    // Getters
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getRole() const { return role; }

    // Setters
    void setUsername(const string& newUsername) { username = newUsername; }
    void setPassword(const string& newPassword) { password = newPassword; }
    void setRole(const string& newRole) { role = newRole; }
};

class StandardUser : public User {
public:
    StandardUser(string username, string password)
        : User(username, password, "user") {}

    void displayMenu() override {
        cout << "Welcome " << username << ", you're logged in as a standard user.\n";
        cout << "1. Search for Books\n";
        cout << "2. Borrow a Book\n";
        cout << "3. Return a Book\n";
        cout << "4. View Borrowed Books\n";
        cout << "5. Update Profile\n";
        cout << "6. Logout\n";
    }
};

class Admin : public User {
public:
    Admin(string username, string password)
        : User(username, password, "admin") {}

    void displayMenu() override {
        cout << "Admin Dashboard\n---------------\n";
        cout << "1. Add a Book\n";
        cout << "2. Remove a Book\n";
        cout << "3. Update Book Information\n";
        cout << "4. View All Loans\n";
        cout << "5. Add/Remove User (Admins)\n";
        cout << "6. Logout\n";
    }
};

/*
int main() {
    // Example of using these classes:
    StandardUser user1("john_doe", "12345");
    Admin admin1("admin_user", "adminpass");

    // Demonstration of setters and getters
    cout << "Initial Username: " << user1.getUsername() << endl;
    user1.setUsername("jane_doe");
    cout << "New Username: " << user1.getUsername() << endl;

    user1.displayMenu();
    admin1.displayMenu();

    return 0;
}
*/
