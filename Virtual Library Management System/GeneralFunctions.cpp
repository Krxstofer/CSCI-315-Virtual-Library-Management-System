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
#include "user.h"
#include "LoadSave.h"
#include "GeneralFunctions.h"
//#include "Login.h"
using namespace std;
#include <cstdlib>  // For std::exit()

void logout(ifstream& qIn, string qBook, ifstream& tIn, string tBook, linkedQueueType<Book>& queue, bSearchTreeType<Book>& tree, bool display)
{
  ofstream qOut; //tOut is global

  //Saving out queue
  qOut.open(qBook); //storage file for borrowed books
  saveQueue(qOut, queue, display);
  qIn.close();
  qOut.close();

  //Saving out binary search tree
  tOut.open(tBook); //storage file for all books
  tree.inorderTraversal(saveTree);
  tIn.close();
  tOut.close();

  //no need to reset the user's credentials to blank because preLoginMenu
  //is called after logout and usr is not passed in to it
  //so user's login info for that session is gone (good for security) 
}

bool registerUser(HashTable& hash, User& user, istream& in_stream, bool display)
{
    int choice;
    string username = "", pass = "", passcheck = "";
    User temp(username, pass, "user");//initialize User temp

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
      in_stream >> username;

      while("" != hash.getUserRole(username))//if user already exists
      {
	if(display)
        {
          cout << "Sorry, that username has already been taken." << endl
	       << "Please enter a different username: ";
        }
        in_stream >> username;
      }

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
      temp.setUsername(username);
      temp.setPassword(pass);
      //role is already set in the constructor

      hash.insertUser(temp);

      user.setUsername(username);
      user.setPassword(pass);

      if(display)
      {
        cout << "Thank you for joining the Virtual Library!" << endl << endl;
      }
      return true; //registration successful

   }
   //if choice is 2 control will simply return
   return false; //did not register

}//end of registerUser

//Login Function
// Adjust the login function to include the verbose parameter to control output
std::string login(HashTable& ht, const std::string& username, const std::string& password, bool verbose) {
    if (ht.checkPassword(username, password)) {
        std::string role = ht.getUserRole(username);
        if (!role.empty()) {
            if (verbose) {
                std::cout << "Login successful! Welcome, " << username << ". You are logged in as a(n) " << role << "." << std::endl;
            }
        } else {
            if (verbose) {
                std::cout << "User role not found." << std::endl;
            }
        }
        return role;
    } else {
        if (verbose) {
            std::cout << "Login failed: Invalid username or password." << std::endl;
        }
        return "";  // Return an empty string if authentication fails
    }
}

void exitApplication(bool testMode, bool verbose = false) {
    if (verbose) {
        std::cout << "Exiting the application. Goodbye!\n";
    }
    
    if (!testMode) {
        std::exit(0);  // Exit the program normally
    } else {
        // If in test mode, throw an exception to simulate the exit without actually exiting
        throw std::runtime_error("Exit called during test mode");
    }
}
