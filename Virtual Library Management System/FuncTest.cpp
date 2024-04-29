//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//FuncTest.cpp: file for testing the my functions

#include <string>
#include <iostream>
#include "Book.h"
//#include "hash.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "LoadSave.h"
#include "GeneralFunctions.h"
#include "AdminFun.h"

/*User Objects*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*prelogin*/
void preLoginMenu() {

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

int main()
{

/*temporary testing*/
//HashTable hash; broken
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
/*addOrRemoveUser(hash); //add
registerUser(hash);
addOrRemoveUser(hash); //remove*/
logout(qIn, tIn, queue, tree); 

/*test*/

  return 0;
}
