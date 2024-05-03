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
#include "nullBuffer.h"

using namespace std;

//PLACE the implementation for your admin function here

// Implement add book functions
Book* addBook(bSearchTreeType<Book>& tree, istream& inStream, bool print)
{
    NullBuffer nullBuffer;
    ostream nullStream(&nullBuffer);
    ostream& outStream = print ? cout : nullStream;

    string title, fn, ln, pub, ID;
    int copyR = 0;
    if (cin.rdbuf()->in_avail() > 0) cin.ignore(100, '\n');
    outStream << endl << "Please fill out the following information for the new book:" << endl;

    outStream << "Book's title: ";
    getline(inStream, title);
    outStream << endl;

    outStream << "Author's first name: ";
    getline(inStream, fn);
    outStream << endl;

    outStream << "Author's last name: ";
    getline(inStream, ln);
    outStream << endl;

    outStream << "Copyright year:  ";
    inStream >> copyR;
    outStream << endl;

    if (inStream.rdbuf()->in_avail() > 0) inStream.ignore(100, '\n');
    outStream << "Publisher: ";
    getline(inStream, pub);
    outStream << endl;

    outStream << "ID: ";
    getline(inStream, ID);
    outStream << endl;

    Book Added(title, fn, ln, copyR, pub, ID, false, "N/A");
    tree.insert(Added);
    outStream << title << " has been added to the library:" << endl;
    outStream << "--------------------------------" << endl;
    outStream << Added;
    outStream << "--------------------------------" << endl;
    return tree.search(Added);
}

// Implement remove book function
bool removeBook(bSearchTreeType<Book>& tree, linkedQueueType<Book>& queue, istream& inStream, bool print)
{
    NullBuffer nullBuffer;
    ostream nullStream(&nullBuffer);
    ostream& outStream = print ? cout : nullStream;

    string title = "";
    Book searchTemp;
    char choice;

    if (cin.rdbuf()->in_avail() > 0) cin.ignore(100, '\n');
    outStream << endl << "What book would you like to remove?" << endl;
    getline(inStream, title);
    outStream << endl;
    searchTemp.setTitle(title);

    if (tree.search(searchTemp) != nullptr)
    {
        searchTemp = *tree.search(searchTemp);
        if (!searchTemp.getBorrowed())
        {
            outStream << "Book found:" << endl;
            outStream << "--------------------------------" << endl;
            outStream << searchTemp;
            outStream << "--------------------------------" << endl;
            outStream << "Are you sure you would like to remove this book from the library? This can not be undone. (Enter 'y' to accept)" << endl;
            inStream >> choice;
            choice = tolower(choice);
            switch (choice)
            {
            case 'y':
                tree.deleteNode(searchTemp);
                outStream << title << " has been removed." << endl;
                return true;
            default:
                outStream << "Removal canceled." << endl;
                return false;
            }
        }
        else
        {
            if (*tree.search(searchTemp) == queue.front())
            {
                outStream << "Book found:" << endl;
                outStream << "--------------------------------" << endl;
                outStream << searchTemp;
                outStream << "--------------------------------" << endl;
                outStream << "Warning: This book is borrowed and at the front of the return queue." << endl;
                outStream << "Are you sure you would like to remove this book from the library? This can not be undone. (Enter 'y' to accept)" << endl;
                inStream >> choice;
                choice = tolower(choice);
                switch (choice)
                {
                case 'y':
                    tree.deleteNode(searchTemp);
                    outStream << title << " has been removed." << endl;
                    return true;
                default:
                    outStream << "Removal canceled." << endl;
                    return false;
                }
            }
            else
            {
                outStream << title << "is borrowed, and not avalible for return. Removal canceled." << endl;
            }
        }
    }
    else
    {
        outStream << title << " Could not be found in the libary." << endl << endl;
        return false;
    }
    outStream << endl;
    return false;
}

// Implement update book info function
void updateBookInfo(bSearchTreeType<Book>& tree, istream& inStream, bool print)
{
    NullBuffer nullBuffer;
    ostream nullStream(&nullBuffer);
    ostream& outStream = print ? cout : nullStream;

    string search = "";
    Book searchTemp;
    int choice = 0;
    string title, fn, ln, pub, ID;
    int copyR;

    if (cin.rdbuf()->in_avail() > 0) cin.ignore(100, '\n');
    outStream << endl << "What book would you like to edit? ";
    getline(inStream, search);
    outStream << endl;
    searchTemp.setTitle(search);

    if (tree.search(searchTemp) != nullptr)
    {
        choice = 0;
        searchTemp = *tree.search(searchTemp);
        outStream << "Book found:" << endl;
        outStream << "--------------------------------" << endl;
        outStream << searchTemp;
        outStream << "--------------------------------" << endl;
        while (choice != 6)
        {
            outStream << "What information would you like to edit?" << endl;
            outStream << "1. Title" << endl;
            outStream << "2. Author" << endl;
            outStream << "3. Copyright" << endl;
            outStream << "4. Publisher" << endl;
            outStream << "5. ID" << endl;
            outStream << "6. Exit" << endl;
            inStream >> choice;
            switch (choice)
            {
            case 1:
            {
                if (cin.rdbuf()->in_avail() > 0) cin.ignore(100, '\n');
                outStream << "Enter new title: ";
                getline(inStream, title);
                outStream << endl;
                tree.search(searchTemp)->setTitle(title);
                outStream << "Title changed." << endl;
                break;
            }
            case 2:
            {
                if (cin.rdbuf()->in_avail() > 0) cin.ignore(100, '\n');
                outStream << "Enter new author's first name: ";
                getline(inStream, fn);
                outStream << endl;

                if (cin.rdbuf()->in_avail() > 0) cin.ignore(100, '\n');
                outStream << "Enter new author's last name: ";
                getline(inStream, ln);
                outStream << endl;

                tree.search(searchTemp)->setFirstName(fn);
                tree.search(searchTemp)->setLastName(ln);
                outStream << "Author changed." << endl << endl;
                break;
            }
            case 3:
            {
                outStream << "Enter new copyright year:  ";
                inStream >> copyR;
                outStream << endl;
                tree.search(searchTemp)->setCopyright(copyR);
                outStream << "Copyright changed." << endl << endl;
                break;
            }
            case 4:
            {
                if (cin.rdbuf()->in_avail() > 0) cin.ignore(100, '\n');
                outStream << "Enter new publisher: ";
                getline(inStream, pub);
                outStream << endl;
                tree.search(searchTemp)->setPublisher(pub);
                outStream << "Publisher changed." << endl << endl;
                break;
            }
            case 5:
            {
                outStream << "Enter new ID: ";
                inStream >> ID;
                outStream << endl;
                tree.search(searchTemp)->setId(ID);
                outStream << "ID changed." << endl << endl;
                break;
            }
            case 6:
            {
                outStream << "New book information:" << endl;
                outStream << "--------------------------------" << endl;
                outStream << *tree.search(searchTemp);
                outStream << "--------------------------------" << endl;
                return;
            }
            default:
            {
                outStream << "Your choice must be from 1 and 6." << endl;
            }
            }
        }
    }
    else
    {
        outStream << search << " Could not be found in the libary." << endl << endl;
    }
    outStream << endl;
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
