//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//BookTest.cpp: file for testing the Book object

#include <string>
#include <iostream>
#include "Book.h"

using namespace std;
int main()
{

/*temporary testing*/
Book b1("Today","John", "Doe", 1780, "Miller and Sons", "1-566-46465-5", false), b2;
//using a default variable for b1's borrower
ifstream i;
ofstream o;

o.open("Library.txt"); //storage file for books
i.open("Library.txt");

//setters
b2.setFirstName("Frances");
b2.setLastName("Hodgson Burnett");
b2.setTitle("The Secret Garden");
b2.setCopyright(-32);//out of bounds should come through as 0
b2.setPublisher("Penguin");
b2.setId("HOD");
b2.setBorrower("Me"); //sets borrowed and borrower

o <<  b1; //print to file

o << b2; //two books in file

i >> b2;//same book as b1 should come through

i >> b1; //testing double input

//getters
cout << "First Name:" << b2.getFirstName() << "."<< endl; //checking for white space in the variables
cout << "Last Name:" << b2.getLastName() << "."<< endl;
cout << "Title:" << b2.getTitle() << "."<< endl;
cout << "Copyright:" << b2.getCopyright() << "."<< endl;
cout << "Publisher:" << b2.getPublisher() << "."<< endl;
cout << "Id:" << b2.getId() << "."<< endl;
cout << "Borrowed Bool:" << b2.getBorrowed() << "."<< endl; //prints as an int
cout << "Borrower:" << b2.getBorrower() << "."<< endl << endl;

cout << b2 << endl << b1 << endl;

cout << "Return b2 and b1:" << endl;
b2.returnBook();
b1.returnBook();
cout << b2 << endl << b1 << endl;



/*test*/

  return 0;
}
