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
//#include "hash.h" needs fixed

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

    cout << "Author's first and last name: ";
    cin >> fn >> ln;
    cout << endl;

    cout << "Copyright year:  ";
    cin >> copyR;
    cout << endl;

    cin.ignore();
    cout << "Publisher: ";
    getline(cin, pub);
    cout << endl;

    ID = ln.substr(0, 2) + fn[0];
    ID[0] = toupper(ID[0]);
    ID[1] = toupper(ID[1]);
    ID[2] = toupper(ID[2]);

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
        defult:
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
                searchTemp.setTitle(title);
                cout << "Title changed." << endl;
                break;
            }
            case 2:
            {
                cout << "Enter new author's first and last name: ";
                cin >> fn >> ln;
                cout << endl;
                searchTemp.setFirstName(fn);
                searchTemp.setLastName(ln);
                cout << "Author changed." << endl << endl;
                break;
            }
            case 3:
            {
                cout << "Enter new copyright year:  ";
                cin >> copyR;
                cout << endl;
                searchTemp.setCopyright(copyR);
                cout << "Copyright changed." << endl << endl;
                break;
            }
            case 4:
            {
                cin.ignore();
                cout << "Enter new publisher: ";
                getline(cin, pub);
                cout << endl;
                searchTemp.setPublisher(pub);
                cout << "Publisher changed." << endl << endl;
                break;
            }
            case 5:
            {
                cout << "Enter new ID: ";
                cin >> ID;
                cout << endl;
                searchTemp.setId(ID);
                cout << "ID changed." << endl << endl;
                break;
            }
            case 6:
            {
                cout << "New book information:" << endl;
                cout << "--------------------------------" << endl;
                cout << searchTemp;
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
