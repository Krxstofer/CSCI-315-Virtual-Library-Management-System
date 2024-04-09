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
        << "Status: " << (entry.borrowed ? "Checked Out" : "Available") << endl << endl;
  return fcout;

}
ifstream& operator>>(ifstream& fcin, Book& entry)
{
  string label, str; //takes in unwanted labels
  char c; //gets the final newline

  fcin >> label;  //Title
  getline(fcin, str); //processes title even if it has spaces
  entry.title = str.substr(1); //Remove the space after ':'

  fcin >> label; //Author
  getline(fcin, str); //same for author
  entry.lastName = str.substr(1, (str.find(",") -1)); //last name is before the ,
  entry.firstName = str.substr(str.find(",") + 2); //firstname is after latname,' '

  fcin >> label >> entry.copyright; //Copyright
 
  fcin >> label; //Publisher
  getline(fcin, str); //processes publisher even if it has spaces
  entry.publisher = str.substr(1); //Remove the space after ':'

  fcin >> label >> entry.id; //ISBN

  fcin >> label; //Status
  getline(fcin, str);
  str = str.substr(1); //Remove the space after ':'
  if(str == "Available")
  {
    entry.borrowed =  false;
  }
  else if(str == "Checked Out")
  {
    entry.borrowed =  true;
  }
  else
  {
    cout << "Borrowed Value Error!" << endl; //maybe change to a throw later
  }

  fcin.get(c); //final newline
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
        << "Status: " << (entry.borrowed ?  "Checked Out" : "Available") << endl << endl;
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

//setters
void Book :: setTitle(string bookName)
{
  title = bookName;
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
void Book :: setBorrowed(bool borrow)
{
  borrowed = borrow;
}

//overload relational operators?

//constructor
Book :: Book(string bookName, string first, string last, int cDate, string publish,
	string idCode, bool borrow)
{
  title = bookName;
  firstName = first;
  lastName = last;
  setCopyright(cDate); //includes check for negative dates
  publisher = publish;
  id = idCode;
  borrowed = borrow;
}
