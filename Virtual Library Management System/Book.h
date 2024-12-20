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
  //Borrowed by: borrower

  friend ifstream& operator>>(ifstream& fcin, Book& entry);
  //inputs book info which was in the form output by the overloaded file output
  //operator from a file specified by the ifstream parameter
  //uses setTitle, setCopyright, returnBook, and setBorrower
  //to ensure values are reasonable and set the title to the proper format
  //Postcondition: the information has been loaded into the proper
  //member variables, title has been reformated and copyright has been set
  //to 0 if neccessary. If the status was "Available" borrowed was set
  //to false and borrower to "N/A" (discarding any other value for borrower 
  //if there was one. If the status was "Checked out" borrowed
  //was set to true and borrower was set to the value of borrower from the file.
  //If the status was neither of these then an error message is printed out
  //and neither borrowed nor borrower is not set. 

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
  //Does not output borrower for information security
  //if nessecary borrower can be ouput in a function by using getBorrower()

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
  string getBorrower() const; //borrower is "N/A" if not borrowed
  //functions to return the values of private member variables
  //Postcondition: the value of the appropriate member variable has been returned

  void returnBook();
  //function to return a book
  //Postcondition: borrowed is set to false and borrower to "N/A"
  //Note: book must be removed from the queue separately

  //setters
  void setTitle(string bookName);
  void setFirstName(string first);
  void setLastName(string last);
  void setCopyright(int cDate);
  void setPublisher(string publish);
  void setId(string idCode);
  void setBorrower(string username); //also sets borrowed to true
  //functions to set the values of private memebr variables
  //Postcondition: the value of the appropriate member variable has been altered
  //setTitle moves any initial "A", "An", "The" to the end of the title preceded by a comma
  //e.g. A Parade becomes Parade, A (useful for sorting)
  //if cDate is a negative number copyright will be set to its default value (0) instead.
  //borrowed has no direct setter becuase it can be set to true by setBorrower
  //(if there is a borrower then the book is currently borrowed) or set to false by
  //calling the returnBook function

  //overload relational operators
  bool operator==(const Book& other) const;
  //function to overload the == operator needed by the binary search tree.
  //Books are compared by title
  //Postcondition: if other title is the same as this title it will return true
  //otherwise it will return false
  bool operator>(const Book& other) const;
  //function to overload the>  operator needed by the binary search tree
  //books are compared (and thus sorted) by title
  //Postcondition: if the value of this title
  //is greater than the value of other title
  //then it will return true otherwise it will return false

  //constructor with default parameters
  Book(string bookName = "", string first = "", string last = "",
       int cDate = 0, string publish = "", string idCode = "000-0-000-00000-0",
       bool borrow = false, string username = "");
  //sets memeber variables to the values of the parameters. If values are not specified, default values
  //are used. Ensures username is only given a value other than "N/A" if borrow == true
  //Postcondition: id = idCode title = bookName however if bookname's first word was "A" "An" or "The"
  //this has been moved to the end of title and preceded by a comma
  //firstName = first lastName = last
  //copyright = cDate publisher = publish borrowed = borrow borrower = username

private:

  string title;
  string firstName; //author firstname
  string lastName; //author lastname
  int copyright;
  string publisher;
  string id; //e.g. ISBN or first three letters of lastname
  bool borrowed;
  string borrower; //username of the borrower. could make it a user object, but the
                   //password member is not needed here
};

#endif
