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
  //Borrowed by: borrower

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
       bool borrow = false, string username = "N/A");
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
  string id; //e.g. ISBN or first three letters of lastname? changed to string
  bool borrowed;
  string borrower; //username of the borrower. could make it a user object, but the
                   //password member is not needed here
  //int quantity; remove? might make borrowing harder to implement
    // Add more attributes as needed
};

//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//book.cpp: implementation file for the book object

//File I/O friend functions
ofstream& operator<<(ofstream& fcout, const Book& entry)
{
  fcout << "Title: " << entry.title << endl
	<< "Author: " << entry.lastName << ", " << entry.firstName << endl
	<< "Copyright: " << entry.copyright << endl
        << "Publisher: " << entry.publisher << endl
        << "ID: " << entry.id << endl
        << "Status: " << (entry.borrowed ? "Checked Out" : "Available") << endl
	<< "Borrowed by: " << entry.borrower << endl << endl;
  return fcout;

}
ifstream& operator>>(ifstream& fcin, Book& entry)
{
  string label, str; //takes in unwanted labels
  int copyright;
  char c; //gets the final newline

  fcin >> label;  //Title
  fcin.get(c); //Remove the space after ':'
  getline(fcin, str); //processes title even if it has spaces

  entry.setTitle(str); //moves initial "A" , "An" or "The" to the end of the title
		 //preceded by a ","

  fcin >> label; //Author
  getline(fcin, str); //same for author
  entry.lastName = str.substr(1, (str.find(",") -1)); //last name is before the ,
  entry.firstName = str.substr(str.find(",") + 2); //firstname is after latname,' '

  fcin >> label >> copyright; //Copyright
  entry.setCopyright(copyright); //ensures copyright is positive 
 
  fcin >> label; //Publisher
  getline(fcin, str); //processes publisher even if it has spaces
  entry.publisher = str.substr(1); //Remove the space after ':'

  fcin >> label >> entry.id; //ISBN

  fcin >> label; //Status
  getline(fcin, str);
  str = str.substr(1); //Remove the space after ':'
  if(str == "Available")
  {
    entry.returnBook(); //set borrowed to false and borrower to "N/A"
    //Read in borrower but ignore it
    //label is used twice because the label "Borrowed by:" is two strings
    fcin >> label >> label >> str; //Borrowed by:
  }
  else if(str == "Checked Out")
  {
    fcin >> label >> label >> str; //Borrowed by:
    entry.setBorrower(str); //sets borrowed to true and sets the borrower's name
  }
  else
  {
    cout << "Borrowed Value Error!" << endl; //maybe change to a throw later
    //Read in borrower but ignore it
    fcin >> label >> label >> str; //Borrowed by:
  }

  getline(fcin, str); //discard the two final newlines (they are not stored in str)
  getline(fcin, str); //getline is used instead of get() so that Windows' /n/r
		      //can be processed
  return fcin;
}

//overload output
ostream& operator<<(ostream& out, const Book& entry)
{
  out << "Title: " << entry.title << endl
	<< "Author: " << entry.lastName << ", " << entry.firstName << endl
	<< "Copyright: " << entry.copyright << endl
        << "Publisher: " << entry.publisher << endl
        << "ID: " << entry.id << endl
        << "Status: " << (entry.borrowed ?  "Checked Out" : "Available") << endl
	<< "Borrowed by: " << entry.borrower << endl;
  return out;
}

//getters
string Book :: getTitle() const
{
  return title;
}
string Book :: getFirstName() const
{
  return firstName;
}
string Book :: getLastName() const
{
  return lastName;
}
int Book :: getCopyright() const
{
  return copyright;
}
string Book :: getPublisher() const
{
  return publisher;
}
string Book :: getId() const
{
  return id;
}
bool Book :: getBorrowed() const
{
  return borrowed;
}
string Book :: getBorrower() const
{
  return borrower;
}

void Book :: returnBook()
{
  borrowed = false;
  borrower = "N/A";
}

//setters
void Book :: setTitle(string bookName)
{
  string temp;

  //move initial "A" "An" or "The" in this title to the end preceded
  //by a comma (useful for sorting)
  temp = bookName.substr(0, bookName.find(" "));

  if(temp == "A" || temp == "The" || temp == "An")
  {
    title = bookName.substr(bookName.find(" ") + 1) + ", " + temp;
  }
  else
  {
    title = bookName;
  }
}
void Book :: setFirstName(string first)
{
  firstName = first;
}
void Book :: setLastName(string last)
{
  lastName = last;
}
void Book :: setCopyright(int cDate)
{
  if(cDate < 0) //can change to historically accurate date?
  {
    copyright = 0;
  }
  else //should I check for future dates?
  {
    copyright = cDate;
  }
}
void Book :: setPublisher(string publish)
{
  publisher = publish;
}
void Book :: setId(string idCode)
{
  id = idCode;
}
void Book :: setBorrower(string username)
{
  borrowed = true;
  borrower = username;
}

//overload relational operators
//since these titles are in book objects they must have already ben processed
//by setTitle into the form tile, A/The/An if neccessary
bool Book :: operator==(const Book& other) const
{
  return(this->title == other.title);
}
bool Book :: operator>(const Book& other) const
{
  return(this->title > other.title);
}

//constructor
Book :: Book(string bookName, string first, string last, int cDate, string publish,
	string idCode, bool borrow, string username)
{
  setTitle(bookName);//move initial "A" "An" or "The" to the end of the title 
		     //preceded by a comma
  firstName = first;
  lastName = last;
  setCopyright(cDate); //includes check for negative dates
  publisher = publish;
  id = idCode;
  if(borrow == true) //set borrowed to true and set the borrower's name
  {
    setBorrower(username);
  }
  else //borrow is false, borrowed is set to false and borrower is set to "N/A"
  {
    returnBook();
  }
}

#endif
