#include <iostream>
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "Book.h"
#include <fstream>
#include <sstream>
#include "LoadSave.h"
#include "user.h"
#include "hash.h"

using namespace std;

ofstream tOut; //global file pointer for saveTree()



/*void LoadSave::saveData(const HashTable& ht, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing." << std::endl;
        return;
    }

    // Access to hashGroups and usersTable is modified to use accessor functions instead of direct access due to privacy
        for (int i = 0; i < HashTable::hashGroups; ++i) {
        for (const auto& user : ht.usersTable[i]) {
            file << user.getUsername() << "," << user.getPassword() << "," << user.getRole() << std::endl;
        }
    }

    file.close();
}

void LoadSave::loadData(HashTable& ht, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for reading." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, password, role;

        std::getline(iss, username, ',');
        std::getline(iss, password, ',');
        std::getline(iss, role);

        ht.insertUser(User(username, password, role));
    }

    file.close();
}
*/
void loadQueue(ifstream& in, linkedQueueType<Book>& queue, bool display) //needs to be run once
//before new borrows are added
{

    Book temp;
    char c;

    in.get(c);
    while (in)
    {

        in >> temp;
        if (temp.getBorrowed() == true) //make sure this book should be in the queue (it is borrowed)
        {
            queue.addQueue(temp);
        }
        else //otherwise temp is not added to the queue
        {
            if (display)
            {
                cout << "Error! " << temp.getTitle() << " should not be in the borrowed queue" << endl
                    << "because it is not checked out. It will not be loaded from the file." << endl << endl;
            }
        }
        in.get(c); //check for another entry (takes a char off a label (harmeless)) otherwise
        //indicates eof to the while
    }
    //when save is run it will overwrite any erroneous entries left in the file

}

void saveQueue(ofstream& out, linkedQueueType<Book> queue, bool display)//must run before program ends
//will overwrite Borrowed.txt
{
    //forcing a load here could append older borrowed books to the end of the user's working queue
    //so the programmer must be resposible for calling an initial load before any
    //calls to addQueue or saveQueue

    while (!queue.isEmptyQueue())
    {
        if (queue.front().getBorrowed() == true) //make sure this book should be in the queue (it is borrowed)
        {
            out << queue.front(); //if it is borrowed write it out
        }
        else
        {
            if (display)
            {
                cout << "Error! " << queue.front().getTitle() << " should not be in the borrowed queue" << endl
                    << "because it is not checked out. It will not be written to the file." << endl << endl;
            }
        }

        queue.deleteQueue(); //either way, remove front item from the queue
    }


}

void loadTree(ifstream& in, bSearchTreeType<Book>& tree) //needs to be run once
//before save writes to the Library file
{

    Book temp;
    char c;
    in.get(c); //check for eof
    while (in)
    {
        in >> temp;
        tree.insert(temp);
        in.get(c); //check for another entry (takes a char off a label (harmeless)) otherwise
        //indicates eof to the while
    }

}

void saveTree(Book& x)//must run before program end. Will overwrite Library.txt
{
    tOut << x;
}

void printTree(Book& x)
{
    cout << x << endl;
}
