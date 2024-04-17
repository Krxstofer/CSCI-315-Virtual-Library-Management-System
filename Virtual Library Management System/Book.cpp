//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//book.cpp: implementation file for the book object

#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"

using namespace std;

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
