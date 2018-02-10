/****************************************************
Name: Bruce Adams
Date: December 5, 2016
CS 2308-005
Homework 10
*****************************************************
This program enqueue's numbers from a dynamic queue
template and sends output of those numbers to the
console for the user
*****************************************************/

#include <iostream>
#include "DynTempQueue.h"
using namespace std;

int main()
{

   // Create a DynTempQueue object from the Class DynTempQueue for int numbers
    DynTempQueue<int> templateQueue;

   // Create DynTempQueue object from the Class DynTempQueue for double numbers
    DynTempQueue<double> templateDblQueue;

   // Enqueue a series of integer numbers.
    cout << "Putting integer items in queue...\n";
    for (int x = 10; x < 15; x++)
        templateQueue.enqueue(x);

   // Enqueue a series of double numbers.
    cout << "Putting double items in queue...\n";
    for (double x = 1.50; x < 6; x++)
        templateDblQueue.enqueue(x);

   // Dequeue and retrieve all numbers in the queue
    cout << "The values in the integer queue were:\n";
    while (!templateQueue.isEmpty())
    {
        int value;
        templateQueue.dequeue(value);
        cout << value << endl;
    }

   // Dequeue and retrieve all numbers in the queue
    cout << "The values in the double queue were:\n";
    while (!templateDblQueue.isEmpty())
    {
        double value;
        templateDblQueue.dequeue(value);
        cout << value << endl;
    }
    return 0;
}
