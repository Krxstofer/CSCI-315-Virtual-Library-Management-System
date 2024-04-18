#include "Book.h"

//Function to search books from the library.txt file and print thier informaiton
void searchBook(string title)
{
	string line;

	ifstream inFile;
	inFile.open("Library.txt");

	if (!inFile)
	{
		cout << "File failed to open." << endl << endl;
		return;
	}
	while (getline(inFile, line))
	{
		size_t lineNum = line.find(title);
		if (lineNum != string::npos)
		{
			cout << "Book has been found: " << endl;
			cout << line << endl;
			for (int i = 0; i <= 5; i++)
			{
				getline(inFile, line);
				cout << line << endl;
			}
			cout << endl;
			return;
		}
	}
	cout << title << " could not be found." << endl << endl;
	inFile.close();
}


//Function to check if a book is part of the library.txt file
bool checkBook(string title)
{
	string line;

	ifstream inFile;
	inFile.open("Library.txt");

	if (!inFile)
	{
		cerr << "File failed to open." << endl << endl;
		return false;
	}

	while (getline(inFile, line))
	{
		size_t lineNum = line.find(title);
		if (lineNum != string::npos)
		{
			return true;
		}
	}
	return false;
	inFile.close();
}