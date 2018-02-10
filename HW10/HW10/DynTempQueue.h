/****************************************************
Name: Bruce Adams
Date: December 5, 2016
CS 2308-005
Homework 10
*****************************************************/

#ifndef DYNTEMPQUEUE_H
#define DYNTEMPTQUEUE_H
#include <iostream>

using namespace std;

/*****************************************************
Class template for DynTempQueue, which can take      *
any type of item, such as an int, double, or float   *
This template creates different types of queues      *
depending on what is implemented in the main file    *
*****************************************************/
template <class T>
class DynTempQueue
{
private:
   // Structure for the queue nodes
   struct TempQueueNode
   {
      T value;         // T Value in a node
      TempQueueNode *next; // Pointer to the next node
   };

   TempQueueNode *front;  // The front of the queue
   TempQueueNode *rear;   // The rear of the queue
   int numItems;      // Number of items in the queue
public:
   // Constructor
   DynTempQueue();

   // Destructor
   ~DynTempQueue();

   // Queue operations
   void enqueue(T);
   void dequeue(T &);
   bool isEmpty() const;
   bool isFull() const;
   void clear();
};

// Constructor for Template function DynTempQueue
template <class T>
DynTempQueue<T>::DynTempQueue()
{
   front = NULL;
   rear = NULL;
   numItems = 0;
}

// Destructor for Template function DynTempQueue
template <class T>
DynTempQueue<T>::~DynTempQueue()
{
   clear();
}

//**********************************************
// Template function enqueue inserts the value *
// in num at the rear of the queue.            *
//**********************************************
template <class T>
void DynTempQueue<T>::enqueue(T num)
{
   TempQueueNode *newNode;

   // Create a new node and store num
   newNode = new TempQueueNode;
   newNode->value = num;
   newNode->next = NULL;

   // Adjust as needed
   if (isEmpty())
   {
      front = newNode;
      rear = newNode;
   }
   else
   {
      rear->next = newNode;
      rear = newNode;
   }

   // Update numItems.
   numItems++;
}

//*****************************************************
// Template function dequeue removes the value        *
// at the front of the queue, and copies it into num. *
//*****************************************************
template <class T>
void DynTempQueue<T>::dequeue(T &num)
{
   TempQueueNode *temp;

   if (isEmpty())
   {
      cout << "The queue is empty.\n";
      //return 1;
   }
    else
    {
       // Save the front node value in num.
       num = front->value;

       // Remove the front node and delete it.
       temp = front;
       front = front->next;
       delete temp;

       // Update numItems.
       numItems--;
    }
}

//******************************************************
// Template function isEmpty returns true if the queue *
// is empty, and false otherwise.                      *
//******************************************************
template <class T>
bool DynTempQueue<T>::isEmpty() const
{
    bool status;

    if (numItems > 0)
       status = false;
    else
       status = true;
    return status;
}

//*****************************************************
// Template function clear dequeues all the elements  *
// in the queue.                                      *
//*****************************************************
template <class T>
void DynTempQueue<T>::clear()
{
    T value;   // Dummy variable for dequeue

    while(!isEmpty())
       dequeue(value);
}
#endif
