//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//MGoogleTest.cpp: file for testing the Book object, linked queue, binary search tree,
//registerUser(), addRemoveUser(), and logout()

#include <string>
#include "Book.h"
#include "linkedQueue.h"
#include "binarySearchTree.h"
#include "LoadSave.h"
#include "GeneralFunctions.h"
#include "AdminFun.h"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>  // Include for std::runtime_error
#include <cstdlib>    // Include for exit()
TEST(LibraryTest, Book)
{
  Book b1("Today","John", "Doe", 1780, "Miller and Sons", "1-566-46465-5", false);
  Book b2("An Idea Today","Sam", "Smith", 1890, "Ideaonics", "1-741-09565-4", true);
  Book temp;
  string firstName, lastName, title, publisher, id, borrower;
  int copyright;

  //test constructor's setting of borrower member variables
  EXPECT_EQ("N/A", b1.getBorrower());
  EXPECT_EQ("", b2.getBorrower());

  //test file writing and reading
  ifstream in;
  ofstream out;

  out.open("BookTest.txt"); //create/overwrite file
  out << b1;
  out << b2;

  in.open("BookTest.txt");
  in >> temp;
  EXPECT_EQ(temp, b1);
  in >> temp;
  EXPECT_EQ(temp, b2);

  in.close();
  out.close();
  //test getters and setters
  firstName = "Frances";

  lastName = "Hodgson Burnett";
  title = "The Secret Garden";
  copyright = -32;
  publisher = "Penguin";
  id = "HOD";
  borrower = "Me";

  temp.setFirstName(firstName);
  temp.setLastName(lastName);
  temp.setTitle(title);
  temp.setCopyright(copyright);//out of bounds should come through as 0
  temp.setPublisher(publisher);
  temp.setId(id);
  temp.setBorrower(borrower); //sets borrowed and borrower

  EXPECT_EQ(firstName, temp.getFirstName());
  EXPECT_EQ(lastName, temp.getLastName());
  EXPECT_NE(title, temp.getTitle()); //Title is processed
  EXPECT_EQ("Secret Garden, The", temp.getTitle()); //Title is processed
  EXPECT_EQ(0, temp.getCopyright()); //copyright should have been reset
  copyright = 1880; //set copyright to reasonable date
  temp.setCopyright(copyright);
  EXPECT_EQ(copyright, temp.getCopyright());//should match now
  EXPECT_EQ(publisher, temp.getPublisher());
  EXPECT_EQ(id, temp.getId());
  EXPECT_TRUE(temp.getBorrowed());
  EXPECT_EQ(borrower, temp.getBorrower());

  //test return book
  b1.returnBook();
  b2.returnBook();

  EXPECT_FALSE(b1.getBorrowed());
  EXPECT_FALSE(b2.getBorrowed());

  EXPECT_EQ("N/A", b1.getBorrower());
  EXPECT_EQ("N/A", b2.getBorrower());

}


TEST(LibraryTest, QueueIO)
{
  ifstream in;
  ofstream out;
  int i = 0;
  char c;
  linkedQueueType<Book> borrowedBooks;
  Book b1("A Tale of Two Cities", "Charles", "Dickens", 1990, "Wordsworth", "DIC", true, "Me");
  Book b2("A Christmas Carol", "Charles", "Dickens", 1992, "Wordsworth", "DIC", true, "You");
  Book tempBook, books[2]; //for testing EXPECT_EQ in a while loop

  books[0] = b1;
  books[1] = b2;

  //Test loadQueue()
  out.open("QueueTest.txt");
  out << b1 << b2; //prime file
  out.close();

  in.open("QueueTest.txt");

  loadQueue(in, borrowedBooks);
  in.close();

  ASSERT_FALSE(borrowedBooks.isEmptyQueue());//do not traverse an empty queue
  while(!borrowedBooks.isEmptyQueue()) //check queue has the expected contents
  {
    EXPECT_EQ(books[i], borrowedBooks.front());
    borrowedBooks.deleteQueue(); //remove front item from the queue
    i++;
  }
  i = 0;

  //Test loadQueue's not borrowed excluder
  b1.returnBook();
  out.open("QueueTest.txt");
  out << b1 << b2; 

  in.open("QueueTest.txt");

  loadQueue(in, borrowedBooks, false);
  in.close();

  EXPECT_EQ(b2, borrowedBooks.front());
  borrowedBooks.deleteQueue(); //remove front item from the queue
  EXPECT_TRUE(borrowedBooks.isEmptyQueue());
  b1.setBorrower("Me"); //restore b1

  //Test saveQueue
  //checked that queue was empty before adding above
  borrowedBooks.addQueue(b1);
  borrowedBooks.addQueue(b2);

  //Check that the Queue is full before saving
  ASSERT_FALSE(borrowedBooks.isEmptyQueue());
  saveQueue(out, borrowedBooks);
  out.close();

  //Test that borrowedBooks is unchanged after saveQueue and
  //test that the text file now contains the queue
  in.open("QueueTest.txt"); //reset in to top of the file

  ASSERT_FALSE(borrowedBooks.isEmptyQueue());
  while(!borrowedBooks.isEmptyQueue())
  {
    in >> tempBook;
    EXPECT_EQ(tempBook, borrowedBooks.front());
    borrowedBooks.deleteQueue();
    i++;
  }
  in.close();
  i = 0;
  //check that queue is now empty
  ASSERT_TRUE(borrowedBooks.isEmptyQueue());

  //Test saveQueue's borrowed == false excluder
  b1.returnBook();
  borrowedBooks.addQueue(b1); 
  borrowedBooks.addQueue(b2);//testing addQueue where borrowed = true

  out.open("QueueTest.txt");//reset

  ASSERT_FALSE(borrowedBooks.isEmptyQueue());
  saveQueue(out, borrowedBooks, false); //false prevents saveQueue 
				//from sending an error message to cout

  in.open("QueueTest.txt");
  in >> tempBook; //check for b1 not being in file
  EXPECT_EQ(tempBook, b2); //first book input is b2

  in.get(c); //check for eof now
  EXPECT_TRUE(in.eof());

  in.close();
  out.close();
}//end of QueueIO

TEST(LibraryTest, QueueFuncs)
{
  int i = 0;
  linkedQueueType<Book> temp, copy, borrowedBooks;
  Book b1("A Tale of Two Cities", "Charles", "Dickens", 1990, "Wordsworth", "DIC", true, "Me");
  Book b2("A Christmas Carol", "Charles", "Dickens", 1992, "Wordsworth", "DIC", true, "You");
  Book books[2]; //for testing EXPECT_EQ in a while loop
  
  books[0] = b1;
  books[1] = b2;

  borrowedBooks.addQueue(b1);
  borrowedBooks.addQueue(b2);
  
  temp = copy = borrowedBooks; //save bB and check user-defined assignment operator

  //Test whether = emptied or changed borrowed books
  ASSERT_FALSE(borrowedBooks.isEmptyQueue()); //do not traverse an empty queue
  while(!borrowedBooks.isEmptyQueue()) //check queue
  {
    EXPECT_EQ(books[i], borrowedBooks.front());
    borrowedBooks.deleteQueue(); //remove front item from the queue
    i++;
  }
  i = 0;

  //Test operator=
  ASSERT_FALSE(temp.isEmptyQueue());
  while(!temp.isEmptyQueue()) //view queue
  {
    EXPECT_EQ(books[i], temp.front());
    temp.deleteQueue(); //remove front item from the queue
    i++;
  }
  i = 0;

  //Test new queue being copy-constructor-initialzed
  linkedQueueType<Book> temp2(copy);
  ASSERT_FALSE(temp2.isEmptyQueue());
  while(!temp2.isEmptyQueue())
  {
    EXPECT_EQ(books[i], temp2.front());
    temp2.deleteQueue();
    i++;
  }
  i = 0;

 //Test copy-constructor-initialzation with an empty queue
  ASSERT_TRUE(temp.isEmptyQueue());
  linkedQueueType<Book> temp3(temp);
  EXPECT_TRUE(temp3.isEmptyQueue());

  //Test overloaded assignment operator with an empty queue
  ASSERT_TRUE(temp.isEmptyQueue());
  temp2 = temp;
  EXPECT_TRUE(temp2.isEmptyQueue());

  //Overloaded assignment operator with two empty queues
  ASSERT_TRUE(temp.isEmptyQueue());
  temp3 = temp; //two empty queues
  EXPECT_TRUE(temp3.isEmptyQueue());

} //end of QueueFuncs

TEST(LibraryTest, Tree)
{
  //tOut is a global in LoadSave
  ifstream in;
  char c;

  bSearchTreeType<Book> library;
  Book b1("A Tale of Two Cities", "Charles", "Dickens", 1990, "Wordsworth", "DIC", false, "N/A");
  Book b2("A Christmas Carol", "Charles", "Dickens", 1992, "Wordsworth", "DIC", true, "You");
  Book dummy;

  //Test loadTree()
  tOut.open("TreeTest.txt");
  tOut << b1 << b2; //prime file
  tOut.close();

  in.open("TreeTest.txt");

  ASSERT_TRUE(library.isEmpty());
  loadTree(in, library);
  in.close();

  EXPECT_FALSE(library.isEmpty());
  //search for a book with b1's title return a pointer to that book if found in the tree
  EXPECT_EQ(b1, *(library.search(b1)) ); //expect to find b1 in the tree now
  EXPECT_EQ(b2, *(library.search(b2)) ); //expect to find b2 in the tree now

  //Test the duplicate excluder
  dummy.setTitle("A Tale of Two Cities");
  library.insert(dummy, false); //dummy should not be inserted because its title matches b1
			 //insert sends an error message to cout
  library.deleteNode(b1);
  EXPECT_EQ(nullptr, library.search(dummy)); //dummy should not be in the tree

  library.insert(b1);//restore the tree 

  //Test search
  //(search now returns a pointer to the element or nullptr if not found instead of a boolean)
  EXPECT_EQ(b1, *(library.search(dummy)) );

  dummy.setTitle("A Tree");
  EXPECT_EQ(nullptr, library.search(dummy) );

  //Test saveTree
  tOut.open("TreeTest.txt");
  ASSERT_FALSE(library.isEmpty());
  library.inorderTraversal(saveTree);//the function saveTree is in LoadSave

  //check if books were copied to file
  in.open("TreeTest.txt");
  in.get(c); //check for eof
  EXPECT_FALSE(in.eof());

  ASSERT_FALSE(library.isEmpty());
  in >> dummy;
  EXPECT_EQ(dummy, *(library.search(b2)) ); //books were written to file alphabetically
  in >> dummy;
  EXPECT_EQ(dummy, *(library.search(b1)) );

  in.close();
  tOut.close();

}

TEST(LibraryTest, Register)
{
  HashTable hash;
  User test("", "", "user");
  std::istringstream fake_input1("1\nTestUser1\nt1\nt1\n");
  std::istringstream fake_input2("2\nTestUser2\nt2\nt2\n");
  std::istringstream fake_input3("0\nt\n1\nTestUser3\nt3\nt3\n");
  std::istringstream fake_input4("1\nTestUser1\nTestUser4\nt4\nt4\n");
  std::istringstream fake_input5("1\nTestUser5\nt5\nt2\nt5\nt5\n");

  //1. Test that user is correctly added to the hash
  EXPECT_TRUE(registerUser(hash, test, fake_input1, false)); //returns true for a successful registration
  EXPECT_TRUE(hash.checkPassword("TestUser1", "t1")); //is user in the hash now?
  EXPECT_EQ("TestUser1", test.getUsername()); //is the proper username set and returned?
  EXPECT_EQ("t1", test.getPassword()); //is the proper password set and returned?

  //2. Test that 2 exits the menu without inputting a new user
  EXPECT_FALSE(registerUser(hash, test, fake_input2, false));
  EXPECT_FALSE(hash.checkPassword("TestUser2", "t2"));
  EXPECT_NE("TestUser2", test.getUsername());
  EXPECT_NE("t2", test.getPassword());

  //3. Test that registerUser can recover from bad input (0,t)
  EXPECT_TRUE(registerUser(hash, test, fake_input3, false));
  EXPECT_TRUE(hash.checkPassword("TestUser3", "t3"));
  EXPECT_EQ("TestUser3", test.getUsername());
  EXPECT_EQ("t3", test.getPassword());

  //4. Test that registerUser can handle when a username has already been taken
  EXPECT_TRUE(registerUser(hash, test, fake_input4, false));
  EXPECT_TRUE(hash.checkPassword("TestUser4", "t4"));
  EXPECT_EQ("TestUser4", test.getUsername());
  EXPECT_EQ("t4", test.getPassword());

  //5. Test that registerUser can handle a bad password confirmation and recover
  EXPECT_TRUE(registerUser(hash, test, fake_input5, false));
  EXPECT_TRUE(hash.checkPassword("TestUser5", "t5"));
  EXPECT_EQ("TestUser5", test.getUsername());
  EXPECT_EQ("t5", test.getPassword());

}


TEST(LibraryTest, addRemoveUsers)
{
  HashTable hash;
  User test1("NotAd", "not1", "user");
  User test2("TestUser1", "t1", "user");
  hash.insertUser(test1);
  hash.insertUser(test2);
  //input for add user
  std::istringstream fake_input1("1\nTestAdmin1\nt1\nt1\n");
  std::istringstream fake_input2("0\nt\n1\nTestAdmin2\nt2\nt2\n");
  std::istringstream fake_input3("1\nTestAdmin2\nTestAdmin1\nTestAdmin3\nt3\nt3\n");
  std::istringstream fake_input4("1\nTestAdmin4\nt4\nt2\nt4\nt4\n");
  
  //input for remove admin
  std::istringstream fake_input5("2\n0\nt\n1\nTestAdmin4\nt4\n");
  std::istringstream fake_input6("2\n1\nTestAdmin3\nt6\n");
  std::istringstream fake_input7("2\n1\nNotAd\nt7\n");

  //input to remove user
  std::istringstream fake_input8("2\n2\nTestUser1\nt1\n");
  std::istringstream fake_input9("2\n2\nNotAd\nt1\n");
  std::istringstream fake_input10("2\n2\nTestAdmin1\nt1\n");

  //input for exiting
  std::istringstream fake_input11("3\n1\nTestAdmin11\nt11\nt11\n");


  //Check the add functionality
  //1. Test that Admin is correctly added to the hash
  addOrRemoveUser(hash, fake_input1, false); //returns true for a successful registration
  EXPECT_TRUE(hash.checkPassword("TestAdmin1", "t1"));

  //2. Test that addRemoveUsers can recover from bad input (0,t)
  addOrRemoveUser(hash, fake_input2, false);
  EXPECT_TRUE(hash.checkPassword("TestAdmin2", "t2"));

  //3. Test that addRemoveUsers (add) can handle when a username has already been taken
  addOrRemoveUser(hash, fake_input3, false);
  ASSERT_TRUE(hash.checkPassword("TestAdmin3", "t3")); //needed for test 6

  //4. Test that registerUser (add) can handle a bad password confirmation and recover
  addOrRemoveUser(hash, fake_input4, false);
  ASSERT_TRUE(hash.checkPassword("TestAdmin4", "t4")); //needed for next test


  //Check the remove functionality for admin
  //5. Test that can recover from bad input (0,t) and that TestAdmin4 is correctly removed 
  //from the hash
  addOrRemoveUser(hash, fake_input5, false);
  EXPECT_FALSE(hash.checkPassword("TestAdmin4", "t4"));

  //6. Test that the admin is not removed if the password is wrong
  addOrRemoveUser(hash, fake_input6, false);
  EXPECT_TRUE(hash.checkPassword("TestAdmin3", "t3"));

  //7. Test that the username entered belongs to an Admin otherwise do not remove
  addOrRemoveUser(hash, fake_input7, false);
  ASSERT_TRUE(hash.checkPassword("NotAd", "not1")); //needed for test 9


  //Check the remove functionality for user
  //8. Test that user TestUser1 is correctly removed from the hash
  EXPECT_TRUE(hash.checkPassword("TestUser1", "t1"));
  addOrRemoveUser(hash, fake_input8, false);
  EXPECT_FALSE(hash.checkPassword("TestUser1", "t1"));

  //9. Test that the user is not removed if the password is wrong
  addOrRemoveUser(hash, fake_input9, false);
  EXPECT_TRUE(hash.checkPassword("NotAd", "not1"));

  //10. Test that the username entered belongs to a user otherwise do not remove
  addOrRemoveUser(hash, fake_input10, false);
  EXPECT_TRUE(hash.checkPassword("TestAdmin1", "t1"));


  //11. Test that 3 exits the menu without adding a user
  addOrRemoveUser(hash, fake_input11, false);
  EXPECT_FALSE(hash.checkPassword("TestAdmin11", "t11"));


}


TEST(LibraryTest, Logout)
{
  ifstream qIn, tIn;
  ofstream qOut; //tOut is in LoadSave
  linkedQueueType<Book> queue;
  bSearchTreeType<Book> tree;
  Book temp, test1("Tada!", "Logout" "Test"), test2("The Last", "John", "Doe");
  int i = 0;
  char c;

  test1.setBorrower("Test");
  test2.setBorrower("Testing");

  //prime queue file
  qOut.open("qLog.txt");
  qOut << test1 << test2;
  //load queue
  qIn.open("qLog.txt");
  loadQueue(qIn, queue);
  qOut.close(); //qIn will be closed in logout
  ASSERT_FALSE(queue.isEmptyQueue());

  //prime tree file
  tOut.open("tLog.txt");
  tOut << test1 << test2;
  //load tree
  tIn.open("tLog.txt");
  loadTree(tIn, tree);
  tOut.close(); //tIn will be closed in logout
  ASSERT_FALSE(tree.isEmpty());

  //Test that logout saved the data correctly
  logout(qIn, "qLog.txt", tIn, "tLog.txt", queue, tree, false); //closes the ifstream variables

  qIn.open("qLog.txt");
  qIn.get(c); //check for eof
  ASSERT_FALSE(qIn.eof());
  ASSERT_FALSE(queue.isEmptyQueue());
  while(!queue.isEmptyQueue())
  {
    qIn >> temp;
    EXPECT_EQ(temp, queue.front());
    queue.deleteQueue();
    i++;
  }
  i = 0;
  qIn.get(c); //check for eof
  EXPECT_TRUE(qIn.eof());
  qIn.close();

  tIn.open("tLog.txt");
  tIn.get(c); //check for eof
  ASSERT_FALSE(tIn.eof());
  ASSERT_FALSE(tree.isEmpty());
  tIn >> temp;
  EXPECT_EQ(temp, *(tree.search(test2)) ); //books were written to file alphabetically
  tIn >> temp;
  EXPECT_EQ(temp, *(tree.search(test1)) );
  tIn.get(c); //check for eof
  EXPECT_TRUE(tIn.eof());

  tIn.close();
}

// exit_function_test.cpp

// Test part
TEST(LibraryTest, ExitFunction) {
    try {
        exitApplication(true);  // Call with test mode true to throw exception instead of exiting
        FAIL() << "Expected std::runtime_error";
    } catch (std::runtime_error const & err) {
        EXPECT_EQ(err.what(), std::string("Exit called"));
    } catch (...) {
        FAIL() << "Caught unexpected exception type";
    }
}

// Main function to run the tests
//int main(int argc, char **argv) {
    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
}
