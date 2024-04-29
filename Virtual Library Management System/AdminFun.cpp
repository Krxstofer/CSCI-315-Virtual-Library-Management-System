//Name: Group 2
//Date: 05/04/2024

//AdminFun.cpp: implementation file for Admin functions
#include <iostream>
#include <string>
#include "Book.h"
#include "AdminFun.h"
#include "linkedQueue.h"
#include "user.h"
//#include "hash.h" needs fixed

using namespace std;

//PLACE the implementation for your admin function here

void viewAllLoans(linkedQueueType<Book>& queue)
{
    //printing a queue requires deleting a queue, so a temporary queue is used.
    linkedQueueType<Book> tempQueue = queue;
    Book tempBook;

    cout << "Here are all the books currently loaned out: " << endl;
    while(!tempQueue.isEmptyQueue())
    {
	tempBook = tempQueue.front();
        cout << tempBook;
        cout << "Borrowed by: " << tempBook.getBorrower() << endl << endl;
    	tempQueue.deleteQueue();
    }
    //If no user has borrowed any books, no books would be printed.
}

void addOrRemoveUser(/*HashTable& hash*/)
{
    int choice;
    string user = "", pass = "", passcheck = "";
    User temp(user, pass, "admin"); //initialize Admin temp

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
