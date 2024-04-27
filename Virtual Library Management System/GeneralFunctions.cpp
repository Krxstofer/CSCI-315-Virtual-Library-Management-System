//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//GeneralFunctions.cpp: contains the defintions of the general functions
//(those which are not part of the either User or Admin menus or are in both (e.g. logout))

#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "hash.h"
#include "LoadSave.h"
#include "GeneralFunctions.h"

using namespace std;

void logout(ifstream& qIn, ifstream& tIn, linkedQueueType<Book>& queue, bSearchTreeType<Book>& tree)
{
  ofstream qOut; //tOut is global

  cout << "Logging out..." << endl; //Kristofer

  //Saving out queue
  qOut.open("Borrowed.txt"); //storage file for borrowed books
  saveQueue(qOut, queue);
  qIn.close();
  qOut.close();

  //Saving out binary search tree
  tOut.open("Library.txt"); //storage file for all books
  tree.inorderTraversal(saveTree);
  tIn.close();
  tOut.close();

  //maybe wipe current user info here, see login()
  // need .h file preLoginMenu(); //Kristofer

}
//repalce with user.h when it is created
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
//replace with user.h when created

void registerUser(HashTable& hash)
{
    int choice;
    string user = "", pass = "", passcheck = "";
    StandardUser temp(user, pass);//initialize User temp'

    cout << "Welcome to the User Registration Menu!" << endl; //modified admin menu
    cout << "-------------------------------------" << endl;
    cout << "1. Register for a Virtual Library Account" << endl;
    cout << "2. Leave this Menu" << endl;
    cout << "Please select an option: ";

    cin >> choice;
    while(!cin || choice > 2 || choice < 1) //validate input
    {
      cout << endl;
      cout << "Invalid option! Please enter the number corresponding" << endl
	   << "to your selection: " << endl;
      cin.clear();
      cin.ignore(200, '\n');

      cout << "1. Register for a Virtual Library Account" << endl;
      cout << "2. Leave this Menu" << endl;
      cout << "Please select an option: ";

      cin >> choice;

    }
    cout << endl << endl;

    //Register
    if(choice == 1)
    {
      cout << "Please enter a username: ";
      cin >> user;
      //!!search hash!!
      /*while(user is found)
      {
        cout << "Sorry, that username has already been taken." << endl
	     << "Please enter a different username: ";
        cin >> user;
      }*/

      cout << endl << endl;
      cout << "Please enter your password: ";
      cin >> pass;

      cout << "Confirm your password: ";
      cin >> passcheck;

      while(pass != passcheck) //password confirmation
      {
        cout << endl;
        cout << "The passwords do not match! Note: passwords are case-sensitive." << endl;
        cout << "Please re-enter your password: ";
        cin >> pass;

        cout << "Re-confirm your password: ";
        cin >> passcheck;

      }

      //Add the information to temp
      temp.setUsername(user);
      temp.setPassword(pass);
      //role is already set in the constructor

      //add temp to the table Note!!(cannot do so until next version of hash)Note!!
      //hash.insertUser(temp);

      cout << "Welcome to the Virtual Library!" << endl << endl;
      //!!user will return to pre login menu to login or could call login here!!

   }
   //if choice is 2 control will simply return

}
