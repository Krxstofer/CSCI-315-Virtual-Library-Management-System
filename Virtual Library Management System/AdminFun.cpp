//Name: Group 2
//Date: 05/04/2024

//AdminFun.cpp: implementation file for Admin functions
#include <iostream>
#include <string>
#include "Book.h"
#include "AdminFun.h"
#include "linkedQueue.h"
#include "user.h"
#include <cctype>
#include "hash.h"

using namespace std;

//PLACE the implementation for your admin function here

// Implement add book functions
void addBook(bSearchTreeType<Book>& tree)
{
    string title, fn, ln, pub, ID;
    int copyR = 0;
    cin.ignore();
    cout << endl << "Please fill out the following information for the new book:" << endl;

    cout << "Book's title: ";
    getline(cin, title);
    cout << endl;

    cout << "Author's first name: ";
    getline(cin, fn);
    cout << endl;

    cout << "Author's last name: ";
    getline(cin, ln);
    cout << endl;

    cout << "Copyright year:  ";
    cin >> copyR;
    cout << endl;

    cin.ignore();
    cout << "Publisher: ";
    getline(cin, pub);
    cout << endl;

    cout << "ID: ";
    getline(cin, ID);
    cout << endl;

    Book Added(title, fn, ln, copyR, pub, ID, false, "N/A");
    tree.insert(Added);
    cout << title << " has been added to the library:" << endl;
    cout << "--------------------------------" << endl;
    cout << Added;
    cout << "--------------------------------" << endl;
}

// Implement remove book function
void removeBook(bSearchTreeType<Book>& tree)
{
    string title = "";
    Book searchTemp;
    char choice;

    cin.ignore();
    cout << endl << "What book would you like to remove?" << endl;
    getline(cin, title);
    cout << endl;
    searchTemp.setTitle(title);

    if (tree.search(searchTemp) != nullptr)
    {
        searchTemp = *tree.search(searchTemp);
        cout << "Book found:" << endl;
        cout << "--------------------------------" << endl;
        cout << searchTemp;
        cout << "--------------------------------" << endl;
        cout << "Are you sure you would like to remove this book from the library? This can not be undone. (Enter 'y' to accept)" << endl;
        cin >> choice;
        choice = tolower(choice);
        switch (choice)
        {
        case 'y':
            tree.deleteNode(searchTemp);
            cout << title << " has been removed." << endl;
            break;
        default:
            cout << "Removal canceled." << endl;
            return;
        }
    }
    else
    {
        cout << title << " Could not be found in the libary." << endl << endl;
    }
    cout << endl;
    return;
}

// Implement update book info function
void updateBookInfo(bSearchTreeType<Book>& tree)
{
    string search = "";
    Book searchTemp;
    int choice = 0;
    string title, fn, ln, pub, ID;
    int copyR;

    cin.ignore();
    cout << endl << "What book would you like to edit? ";
    getline(cin, search);
    cout << endl;
    searchTemp.setTitle(search);

    if (tree.search(searchTemp) != nullptr)
    {
        choice = 0;
        searchTemp = *tree.search(searchTemp);
        cout << "Book found:" << endl;
        cout << "--------------------------------" << endl;
        cout << searchTemp;
        cout << "--------------------------------" << endl;
        while (choice != 6)
        {
            cout << "What information would you like to edit?" << endl;
            cout << "1. Title" << endl;
            cout << "2. Author" << endl;
            cout << "3. Copyright" << endl;
            cout << "4. Publisher" << endl;
            cout << "5. ID" << endl;
            cout << "6. Exit" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                cin.ignore();
                cout << "Enter new title: ";
                getline(cin, title);
                cout << endl;
                tree.search(searchTemp)->setTitle(title);
                cout << "Title changed." << endl;
                break;
            }
            case 2:
            {
                cin.ignore();
                cout << "Enter new author's first name: ";
                getline(cin, fn);
                cout << endl;

                cout << "Enter new author's last name: ";
                getline(cin, ln);
                cout << endl;

                tree.search(searchTemp)->setFirstName(fn);
                tree.search(searchTemp)->setLastName(ln);
                cout << "Author changed." << endl << endl;
                break;
            }
            case 3:
            {
                cout << "Enter new copyright year:  ";
                cin >> copyR;
                cout << endl;
                tree.search(searchTemp)->setCopyright(copyR);
                cout << "Copyright changed." << endl << endl;
                break;
            }
            case 4:
            {
                cin.ignore();
                cout << "Enter new publisher: ";
                getline(cin, pub);
                cout << endl;
                tree.search(searchTemp)->setPublisher(pub);
                cout << "Publisher changed." << endl << endl;
                break;
            }
            case 5:
            {
                cout << "Enter new ID: ";
                cin >> ID;
                cout << endl;
                tree.search(searchTemp)->setId(ID);
                cout << "ID changed." << endl << endl;
                break;
            }
            case 6:
            {
                cout << "New book information:" << endl;
                cout << "--------------------------------" << endl;
                cout << *tree.search(searchTemp);
                cout << "--------------------------------" << endl;
                return;
            }
            default:
            {
                cout << "Your choice must be from 1 and 6." << endl;
            }
            }
        }
    }
    else
    {
        cout << search << " Could not be found in the libary." << endl << endl;
    }
    cout << endl;
    return;
}


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

void addOrRemoveUser(HashTable& hash, istream& in_stream, bool display)
{
    int choice;
    string user = "", pass = "", passcheck = "";
    User temp(user, pass, "admin"); //initialize Admin temp

    if(display)
    {
      cout << "Add an Admin or Remove an Admin or User" << endl; //modified admin menu
      cout << "------------------------------" << endl;
      cout << "1. Add an Admin" << endl;
      cout << "2. Remove an Admin or User" << endl;
      cout << "3. Leave this Menu" << endl;
      cout << "Please select an option: ";
    }
    in_stream >> choice;

    while(!in_stream || choice > 3 || choice < 1) //validate input
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
        cout << "1. Add an Admin" << endl;
        cout << "2. Remove an Admin or User" << endl;
        cout << "3. Leave this Menu" << endl;
        cout << "Please select an option: ";
      }

      in_stream >> choice;

    }

    if(display)
    {
      cout << endl << endl;
    }

    //Add admin
    if(choice == 1)
    {
      if(display)
      {
        cout << "Please enter the new Admin's username: ";
      }

      in_stream >> user;
      while("" != hash.getUserRole(user))//if user already exists
      {
        if(display)
        {
          cout << "Sorry, that username has already been taken." << endl
               << "Please enter a different username: ";
        }
        in_stream >> user;
      }

      if(display)
      {
        cout << endl << endl;
        cout << "Please enter the new Admin's password: ";
      }
      in_stream >> pass;

      if(display)
      {
        cout << "Confirm the new Admin's password: ";
      }
      in_stream >> passcheck;

      while(pass != passcheck) //password confirmation
      {
        if(display)
        {
          cout << endl;
          cout << "The passwords do not match! Note: passwords are case-sensitive." << endl;
          cout << "Please re-enter the new Admin's password: ";
        }
        in_stream >> pass;

        if(display)
        {
          cout << "Re-confirm the new Admin's password: ";
        }
        in_stream >> passcheck;

      }

      //Add the information to temp
      temp.setUsername(user);
      temp.setPassword(pass);
      //role is already set in the constructor

      hash.insertUser(temp);

      if(display)
      {
        cout << "The new Admin has been added to the system!" << endl << endl;
      }

    }
    else if (choice == 2) //remove
    {
      if(display)
      {
        cout << "1. Remove an Admin" << endl;
        cout << "2. Remove a User" << endl;
        cout << "3. Leave this Menu" << endl;
        cout << "Please select an option: ";
      }
      in_stream >> choice;

      while(!in_stream || choice > 3 || choice < 1) //validate input
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
          cout << "1. Remove an Admin" << endl;
          cout << "2. Remove a User" << endl;
          cout << "3. Leave this Menu" << endl;
          cout << "Please select an option: ";
        }

        in_stream >> choice;

      }

      if(display)
      {
        cout << endl << endl;
      }

      if(choice == 1)//remove admin
      {
        if(display)
        {
          cout << "Please enter the username and password of the Admin to be removed: ";
        }
        in_stream >> user >> pass;

        if("admin" == hash.getUserRole(user)) //before removing ensure this is an admin's account
        {
	  if(hash.checkPassword(user, pass) == true)//password check before removing for security
	  {
	    hash.removeUser(user);
	    if(display)
            {
              cout << "The admin " << user << " has been removed." << endl;
	    }
	  }
	  else //password check failed
	  {
	    if(display)
            {
              cout << pass << " is not " << user << "'s password."<< endl
		   << "Removal failed." << endl
		   << "Now leaving the Add or Remove Menu." << endl << endl;
	    }
	  }
        }//end of check if admin
        else //not an admin account or account doesn't exist
        {
  	  if(display)
          {
	    cout << "There is no Admin with that username." << endl
	         << "Now leaving the Add or Remove Menu." << endl << endl;
	  }
        }
      }//end remove admin
      if(choice == 2)//remove user
      {
        if(display)
        {
          cout << "Please enter the username and password of the User to be removed: ";
        }
        in_stream >> user >> pass;

        if("user" == hash.getUserRole(user)) //before removing ensure this is an user's account
        {
	  if(hash.checkPassword(user, pass) == true)//password check before removing for security
	  {
	    hash.removeUser(user);
	    if(display)
            {
              cout << "The user " << user << " has been removed." << endl;
	    }
	  }
	  else //password check failed
	  {
	    if(display)
            {
              cout << pass << " is not " << user << "'s password."<< endl
		   << "Removal failed." << endl
		   << "Now leaving the Add or Remove Menu." << endl << endl;
	    }
	  }
        }//end of check if user
        else //not a user account or account doesn't exist
        {
  	  if(display)
          {
	    cout << "There is no normal user with that username." << endl
	         << "Now leaving the Add or Remove an Menu." << endl << endl;
	  }
        }
      }//end remove user

    }//end choice 2

    //if choice is neither 1 or 2 (it is 3) the function simply returns

}
