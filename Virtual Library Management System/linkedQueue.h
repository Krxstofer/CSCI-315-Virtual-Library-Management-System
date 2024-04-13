//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//linkedQueue.h: header file for the queue class (linked list version)

//D. S. Malik's linkedQueueType and nodeType from the provided CSCI315_data_files.zip
//https://regent.instructure.com/courses/14753/modules/items/959303
//Chapter 17/Ch17_linkedQueue/linkedQueue.h
//Destructor, copy constructor, and operator= implemented by Megan Palermo

//Header file linkedQueue.h
 
#ifndef H_linkedQueue
#define H_linkedQueue 
  
#include <iostream>
#include <cassert>
#include "queueADT.h"
 
using namespace std;

//Definition of the node
template <class Type>
struct nodeType 
{
    Type info;
    nodeType<Type> *link;
};


template <class Type>
class linkedQueueType: public queueADT<Type>
{
public:
    const linkedQueueType<Type>& operator=
                    (const linkedQueueType<Type>&); 
      //Overload the assignment operator.

    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty. 
      //Postcondition: Returns true if the queue is empty,
      //               otherwise returns false.
     
    bool isFullQueue() const;
      //Function to determine whether the queue is full. 
      //Postcondition: Returns true if the queue is full,
      //               otherwise returns false.

    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: queueFront = nullptr; queueRear = nullptr

    Type front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the first 
      //               element of the queue is returned. 

    Type back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the last 
      //               element of the queue is returned.

    void addQueue(const Type& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement
      //               is added to the queue.

    void deleteQueue();
      //Function  to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first 
      //               element is removed from the queue.

    linkedQueueType(); 
      //Default constructor

    linkedQueueType(const linkedQueueType<Type>& otherQueue); 
      //Copy constructor

    ~linkedQueueType(); 
      //Destructor

private:
    nodeType<Type> *queueFront; //pointer to the front of 
                                //the queue
    nodeType<Type> *queueRear;  //pointer to the rear of 
                                //the queue
};

    //Default constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType() 
{
    queueFront = nullptr; //set front to nullptr
    queueRear = nullptr;  //set rear to nullptr
} //end default constructor

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return (queueFront == nullptr);
} //end isEmptyQueue

template <class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    nodeType<Type> *temp;

    while (queueFront!= nullptr)  //while there are elements 
                                  //left in the queue
    {
        temp = queueFront;  //set temp to point to the 
                            //current node
        queueFront = queueFront->link;  //advance first to  
                                        //the next node
        delete temp;    //deallocate memory occupied by temp
    }

    queueRear = nullptr;  //set rear to nullptr
} //end initializeQueue


template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;   //create the node

    newNode->info = newElement; //store the info
    newNode->link = nullptr;    //initialize the link 
                                //field to nullptr

    if (queueFront == nullptr) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}//end addQueue

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != nullptr);
    return queueFront->info; 
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert(queueRear!= nullptr);
    return queueRear->info;
} //end back

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;
   
    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the 
                            //first node
        queueFront = queueFront->link; //advance queueFront 

        delete temp;    //delete the first node

        if (queueFront == nullptr) //if after deletion the 
                                   //queue is empty
            queueRear = nullptr;   //set queueRear to nullptr
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue


    //Destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType() 
{
  //new based on D.S. Malik's linkedStackType
  initializeQueue();
} //end destructor

template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
                    (const linkedQueueType<Type>& otherQueue)
{
/*new*/
  nodeType<Type> *newNode, *current, *temp;
  if(this != &otherQueue) //do not copy self
  {
    initializeQueue(); //wipe current queue so other replaces it
                       //instead of being appended to the end of *this
    if(!otherQueue.isEmptyQueue()) //if other is not empty fill the first element
			    //of this queue
    {
      current = otherQueue.queueFront; //current will traverse otherQueue
      newNode = new nodeType<Type>;
      newNode->info = current->info;
      newNode->link = 0;
      queueFront = newNode;
      current = current->link;
      while(current != 0) //then fill any other elements 0 == nullptr
      {
        temp = newNode;//save this position
        newNode = new nodeType<Type>;
        newNode->info = current->info;
        temp->link = newNode; //link the previous node to the new node
        newNode->link = 0; //as the last node newNode's link is 0
        current = current->link;

      }
      queueRear = newNode;
    }
    //else return empty queue
  }

  return *this; //return this either way
/*new*/

} //end assignment operator
//could use addQueue instead?
	//copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType
                 (const linkedQueueType<Type>& otherQueue) 
{
  /*new*/
  nodeType<Type> *newNode, *current, *temp;
  
    if(!otherQueue.isEmptyQueue()) //if other is not empty fill the first element
			    //of this queue
    {
      current = otherQueue.queueFront; //current will traverse otherQueue
      newNode = new nodeType<Type>;
      newNode->info = current->info;
      newNode->link = 0;
      queueFront = newNode;
      current = current->link;
      while(current != 0) //then fill any other elements 0 == nullptr
      {
        temp = newNode;//save this position
        newNode = new nodeType<Type>;
        newNode->info = current->info;
        temp->link = newNode; //link the previous node to the new node
        newNode->link = 0; //as the last node newNode's link is 0
        current = current->link;

      }
      queueRear = newNode;
    }
    else //else return empty queue
    {
      queueFront = queueRear = 0;
    }
    

  /*new*/
}//end copy constructor

#endif
