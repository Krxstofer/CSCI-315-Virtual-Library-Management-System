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
#include "LoadSave.h"
#include "GeneralFunctions.h"

using namespace std;

void logout(ifstream& qIn, ifstream& tIn, linkedQueueType<Book>& queue, bSearchTreeType<Book>& tree, bool display)
{
  ofstream qOut; //tOut is global

  if(display)
  {
    cout << "Logging out..." << endl; //Kristofer
  }

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
    //StandardUser temp(user, pass);//initialize User temp'

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
      //temp.setUsername(user);
      //temp.setPassword(pass);
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
