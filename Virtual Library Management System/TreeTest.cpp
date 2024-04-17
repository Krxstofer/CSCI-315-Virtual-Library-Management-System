//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//TreeTest.cpp: file for testing the BinarySearchTree object
//and for implementing its data persistence functions (loadTree and saveTree)

#include <string>
#include <iostream>
#include "Book.h"
#include "binarySearchTree.h"

//out is global since inorder only takes one parameter
//and out must be opened outside of saveTree since it is called multiple times
ofstream out;

using namespace std;

void loadTree(ifstream& in, bSearchTreeType<Book>& tree);
void saveTree(Book& x);
void printTree(Book& x);

int main()
{
/*temporary testing*/
ifstream in;
char c;

bSearchTreeType<Book> library;
Book b1("A Tale of Two Cities", "Charles", "Dickens", 1990, "Wordsworth", "DIC", false, "N/A");
Book b2("A Christmas Carol", "Charles", "Dickens", 1992, "Wordsworth", "DIC", true, "You");
Book dummy;

in.open("Library.txt");

in.get(c); //detect eof in exisitng empty file
if(!in)
{
  cout << "File was not found, or the file is empty! Shutting down." << endl;
  exit(1);
}
cout << "The tree should be empty:";
library.inorderTraversal(printTree);
cout << "Empty Tree" << endl << endl;

//Testing loadTree
loadTree(in, library);
cout << "Tree after loading:" << endl;
library.inorderTraversal(printTree); //function as a parameter for proper output
				     //(uses spaces between books instead of newlines otherwise)
in.close();

//Testing insert
cout << "Testing the duplicate excluder" << endl;
library.insert(b1);//testing the duplicate excluder
cout << endl;

cout << "The tree now:" << endl;
library.inorderTraversal(printTree);
cout << "the tree" << endl << endl;


//Test search
//(search now returns a pointer to the element or nullptr if not found not a boolean)
dummy.setTitle("A Tale of Two Cities");

cout << "Searching:" << endl;
if(library.search(dummy) != nullptr)
{
 cout << dummy.getTitle() << " found here: " << library.search(dummy) << endl;
 cout << "Contents of the returned pointer: " << endl
      << *(library.search(dummy)) << "end contents" << endl;
}
else
{
  cout << dummy.getTitle() << " not found." << endl;
  //nullptr cannot be printed out
}
cout << endl;

dummy.setTitle("A Tree");

if(library.search(dummy) != nullptr)
{
 cout << dummy.getTitle() << " found here: " << library.search(dummy) << endl;
 cout << "Contents of the returned pointer: " << endl
      << *(library.search(dummy)) << "end contents" << endl;
}
else
{
  cout << dummy.getTitle() << " not found." << endl;
}
cout << endl;

//Testing saveTree
out.open("Library.txt"); //storage file for books
cout << "Saving:" << endl;
library.inorderTraversal(saveTree);//the function saveTree is a parameter
in.open("Library.txt");

//reopen Library.txt to see how it has been changed
in.get(c);
if(!in)
{
  cout << "File was not found, or the file is empty! Shutting down." << endl;
  exit(1);
}

cout << "Library.txt after saving: " << endl;
in.get(c);
while(in) //checks
{
  in >> b1;
  cout << b1 << endl;
  in.get(c);
}

cout << "The tree after saving:" << endl;
library.inorderTraversal(printTree);

in.close();
out.close();

cout << "end" << endl;
/*test*/

  return 0;
}//end of main

void loadTree(ifstream& in, bSearchTreeType<Book>& tree) //needs to be run once
							   //before save writes to the Library file
{

  Book temp;
  char c;
  in.get(c); //check for eof
  while(in)
  {
    in >> temp;
    tree.insert(temp);
    in.get(c); //check for another entry (takes a char off a label (harmeless)) otherwise
               //indicates eof to the while
  }

}

void saveTree(Book& x)//must run before program end. Will overwrite Library.txt
{
  out << x;
}

void printTree(Book& x)
{
  cout << x << endl;
}

