//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//book.h: header file for the book object
#ifndef book
#define book

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Book {

public:

  //overload file I/O
  friend ofstream& operator<<(ofstream& fcout, const Book& entry);
  //outputs book info to a file specified by the ofstream parameter
  //Postcondition: The book's informatoin has been output in the form:
  //Title: title
  //Author: lastname, firstname
  //Copyright: copyright
  //Publisher: publisher
  //ID: id
  //Status: "Checked out" if borrowed = true, "Avaialble" if borrowed = false

  friend ifstream& operator>>(ifstream& fcin, Book& entry);
  //inputs book info which was in the form output by the overloaded file output 
  //operator from a file specified by the ifstream parameter
  //Postcondition: the information has been loaded into the proper
  //member variables if the status was "Available" brorrowed was set
  //to false. If the status was "Checked out" borrowed was set to true
  //if the status was neither of these then an error message is printed out 

  //overload output
  friend ostream& operator<<(ostream& out, const Book& entry);
  //outputs a book's information to the screen
  //Postcondition: The book's informatoin has been output in the form:
  //Title: title
  //Author: lastname, firstname
  //Copyright: copyright
  //Publisher: publisher
  //ID: id
  //Status: "Checked out" if borrowed = true, "Avaialble" if borrowed = false

  //input is not overloaded because using individual setters allows for more
  //flexibility

  //getters
  string getTitle() const;
  string getFirstName() const;
  string getLastName() const;
  int getCopyright() const;
  string getPublisher() const;
  string getId() const;
  bool getBorrowed() const;
  //functions to return the values of private memebr variables
  //Postcondition: the value of the appropriate memebr variable has been returned

  //setters
  void setTitle(string bookName);
  void setFirstName(string first);
  void setLastName(string last);
  void setCopyright(int cDate);
  void setPublisher(string publish);
  void setId(string idCode);
  void setBorrowed(bool borrow);
  //functions to set the values of private memebr variables
  //Postcondition: the value of the appropriate memebr variable has been altered
  //if cDate is a negative number copyright will be set to its deafult value (0) instead

  //overload relational operators?

  //constructor with default parameters
  Book(string bookName = "", string first = "", string last = "",
       int cDate = 0, string publish = "", string idCode = "000-0-000-00000-0", bool borrow = false);
  //sets memeber variables to the values of teh parameters. If values are not specified, default values
  //are used
  //Postcondition: id = idCode title = bookName firstName = first lastName = last
  //copyright = cDate publisher = publish borrowed = borrow

private:
  string title;
  string firstName; //author firstname
  string lastName; //author lastname
  int copyright;
  string publisher;
  string id; //e.g. ISBN or first three letters of lastname? changed to string
  bool borrowed;
  //int quantity; remove? might make borrowing harder to implement
    // Add more attributes as needed
};
#endif
