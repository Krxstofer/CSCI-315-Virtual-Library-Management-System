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
//#include "hash.h"
#include "user.h"
#include "LoadSave.h"
#include "GeneralFunctions.h"

using namespace std;

void logout(ifstream& qIn, string qBook, ifstream& tIn, string tBook, linkedQueueType<Book>& queue, bSearchTreeType<Book>& tree, bool display)
{
  ofstream qOut; //tOut is global

  if(display)
  {
    cout << "Logging out..." << endl; //Kristofer
  }

  //Saving out queue
  qOut.open(qBook); //storage file for borrowed books
  saveQueue(qOut, queue);
  qIn.close();
  qOut.close();

  //Saving out binary search tree
  tOut.open(tBook); //storage file for all books
  tree.inorderTraversal(saveTree);
  tIn.close();
  tOut.close();

  if(display)
  {
  //maybe wipe current user info here, see login()
  // need .h file preLoginMenu(); //Kristofer
  }
}

void registerUser(/*HashTable& hash,*/ istream& in_stream, bool display)
{
    int choice;
    string user = "", pass = "", passcheck = "";
    User temp(user, pass, "user");//initialize User temp'

    if(display)
    {
      cout << "Welcome to the User Registration Menu!" << endl; //modified admin menu
      cout << "-------------------------------------" << endl;
      cout << "1. Register for a Virtual Library Account" << endl;
      cout << "2. Leave this Menu" << endl;
      cout << "Please select an option: ";
    }
    in_stream >> choice;
    while(!in_stream || choice > 2 || choice < 1) //validate input
    {
      if(display)
      {
        cout << endl;
        cout << "Invalid option! Please enter the number corresponding" << endl
	     << "to your selection: " << endl;
      }
      in_stream.clear();
      in_stream.ignore(200, '\n');

      if(display)
      {
        cout << "1. Register for a Virtual Library Account" << endl;
        cout << "2. Leave this Menu" << endl;
        cout << "Please select an option: ";
      }

      in_stream >> choice;

    }
    if(display)
    {
      cout << endl << endl;
    }
    //Register
    if(choice == 1)
    {
      if(display)
      {
        cout << "Please enter a username: ";
      }
      in_stream >> user;
      //!!search hash!!
      /*while(user is found)
      {
        if(display)
        {
          cout << "Sorry, that username has already been taken." << endl
	       << "Please enter a different username: ";
        }
        in_stream >> user;
      }*/

      if(display)
      {
        cout << endl << endl;
        cout << "Please enter your password: ";
      }
      in_stream >> pass;

      if(display)
      {
        cout << "Confirm your password: ";
      }
      in_stream >> passcheck;

      while(pass != passcheck) //password confirmation
      {
        if(display)
        {
          cout << endl;
          cout << "The passwords do not match! Note: passwords are case-sensitive." << endl;
          cout << "Please re-enter your password: ";
        }
        in_stream >> pass;

        if(display)
        {
          cout << "Re-confirm your password: ";
        }
        in_stream >> passcheck;

      }

      //Add the information to temp
      temp.setUsername(user);
      temp.setPassword(pass);
      //role is already set in the constructor

      //add temp to the table Note!!(cannot do so until next version of hash)Note!!
      //hash.insertUser(temp);

      if(display)
      {
        cout << "Welcome to the Virtual Library!" << endl << endl;
      }
      //!!user will return to pre login menu to login or could call login here!!

   }
   //if choice is 2 control will simply return

}

//void userMenu() {
    //int choice = 0;
    //while (true) {
        //cout << "\nUser Menu\n";
        //cout << "1. View Profile\n";
        //cout << "2. Edit Profile\n";
        //cout << "3. Logout\n";
        //cout << "Choose an option or 3 to exit: ";
        //cin >> choice;

        //switch (choice) {
            //case 1:
                //cout << "Viewing profile...\n";
                //break;
            //case 2:
                //cout << "Editing profile...\n";
                //break;
            //case 3:
                //cout << "Logging out...\n";
                //return;  // Returns to the calling function, effectively exiting the menu
            //default:
                //cout << "Invalid option, try again.\n";
        //}
    //}
//}

void exitApplication() {
    cout << "Exiting application...\n";
    exit(0);  // Exits the program
}

// Function to handle user login
//User* login(HashTable& table, const std::string& username, const std::string& password) {
   //std::string storedPassword = table.searchTable(username);
    //if (!storedPassword.empty() && storedPassword == password) {
        //int hashValue = table.hashFunction(username);
        //auto& users = table.getUsersTable()[hashValue];
       // for (auto& user : users) {
           //if (user.getUsername() == username) return new User(user);  // Assuming copy constructor exists
       // }
       // auto& admins = table.getAdminsTable()[hashValue];
       // for (auto& admin : admins) {
         //   if (admin.getUsername() == username) return new Admin(admin);  // Assuming copy constructor exists
        //}
   // }
    //return nullptr;
//}

//int main() {
    //HashTable table;
    // Presumably, users and admins would be inserted into the table earlier in the program

    //std::string username, password;
    //std::cout << "Enter username: ";
    //std::cin >> username;
    //std::cout << "Enter password: ";
    //std::cin >> password;

    //User* user = login(table, username, password);
    //if (user) {
       // user->displayMenu();
       // delete user;  // Clean up the created user object
   // } else {
        //std::cout << "Invalid username or password!" << std::endl;
   // }

    //return 0;
//}
