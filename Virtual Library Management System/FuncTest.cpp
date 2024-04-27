//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//FuncTest.cpp: file for testing the my functions

#include <string>
#include <iostream>
#include "Book.h"
#include "hash.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "LoadSave.h"
#include "GeneralFunctions.h"

/*User Objects*/
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

/*prelogin*/
void preLoginMenu() {
StandardUser me("", ""); //for testing
    int choice;
    cout << "Welcome to the Virtual Library Management System" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Please select an option: ";
    cin >> choice;

    switch (choice) {
    case 1:
        // Implemenet Login functionality
        //userMenu(me); //for testing
        //adminMenu(); //for testing
        break;
    case 2:
        // Implement registration functionality
        break;
    case 3:
        cout << "Exiting program..." << endl;
        exit(0);
    default:
        cout << "Invalid choice. Please try again." << endl;
        preLoginMenu();
    }
}

using namespace std;


void addOrRemoveUser(HashTable& hash);
//void registerUser(HashTable& hash);

int main()
{

/*temporary testing*/
HashTable hash;
ifstream qIn, tIn;
linkedQueueType<Book> queue;
bSearchTreeType<Book> tree;
Book test("Tada!", "FuncTest");
char c;

test.setBorrower("Test");

//loading queue
    qIn.open("Borrowed.txt"); //storage file for borrowed books
    qIn.get(c); //detect eof in existing, empty file
    if(!qIn)
    {
      cout << "Borrowed books file not found! Shutting down." << endl;
      exit(1);
    }
    loadQueue(qIn, queue);
queue.addQueue(test);
    //loading tree
    tIn.open("Library.txt"); //storage file for all books
    tIn.get(c); //detect eof in exisitng empty file
    if(!tIn)
    {
      cout << "File was not found, or the file is empty! Shutting down." << endl;
      exit(1);
    }
    loadTree(tIn, tree);
tree.insert(test);
addOrRemoveUser(hash); //add
registerUser(hash);
addOrRemoveUser(hash); //remove
logout(qIn, tIn, queue, tree); 

/*test*/

  return 0;
}
void addOrRemoveUser(HashTable& hash)
{
    int choice;
    string user = "", pass = "", passcheck = "";
    Admin temp(user, pass); //initialize Admin temp

    cout << "Add or Remove an Admin Account" << endl; //modified admin menu
    cout << "------------------------------" << endl;
    cout << "1. Add an Admin" << endl;
    cout << "2. Remove an Admin" << endl;
    cout << "3. Leave this Menu" << endl;
    cout << "Please select an option: ";

    cin >> choice;
    while(!cin || choice > 3 || choice < 1) //validate input
    {
      cout << endl;
      cout << "Invalid option! Please enter the number corresponding" << endl
	   << "to your selection: " << endl;
      cin.clear();
      cin.ignore(200, '\n');

      cout << "1. Add an Admin" << endl;
      cout << "2. Remove an Admin" << endl;
      cout << "3. Leave this Menu" << endl;
      cout << "Please select an option: ";

      cin >> choice;

    }
    cout << endl << endl;

    //Add admin
    if(choice == 1)
    {
      cout << "Please enter the new Admin's username: ";
      cin >> user;
       //!!search hash!!
      /*while(user is found)
      {
        cout << "Sorry, that username has already been taken." << endl
	     << "Please enter a different username: ";
        cin >> user;

      }*/

      cout << endl << endl;
      cout << "Please enter the new Admin's password: ";
      cin >> pass;

      cout << "Confirm the new Admin's password: ";
      cin >> passcheck;

      while(pass != passcheck) //password confirmation
      {
        cout << endl;
        cout << "The passwords do not match! Note: passwords are case-sensitive." << endl;
        cout << "Please re-enter the new Admin's password: ";
        cin >> pass;

        cout << "Re-confirm the new Admin's password: ";
        cin >> passcheck;

      }

      //Add the information to temp
      temp.setUsername(user);
      temp.setPassword(pass);
      //role is already set in the constructor

      //add temp to the table Note!!(cannot do so until next version of hash)Note!!
      //hash.insertUser(temp);

      cout << "The new Admin has been added to the system!" << endl << endl;

    }//remove Admin
    else if (choice == 2)
    {
      cout << "Please enter the username of the Admin to be removed: ";
      cin >> user;
      //need more hash table for this
      //search does this username exist and is it an admin's username?
      //get password confirmation before deletion? nah
      //if so 
      //hash.removeUser(user);
      //else print not an admin or not found as neccesary

    }

    //if choice is neither 1 or 2  (it is 3) the function simply returns

}
