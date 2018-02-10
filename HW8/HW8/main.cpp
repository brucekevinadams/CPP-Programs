/****************************************************
Name: Bruce Adams
Date: November 18, 2016
CS 2308-005
Homework 8
*****************************************************/

#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

int main()
{
    // Give instructions to user on console
    cout << "This program creates a linked list of numbers and then\n";
    cout << "allows the user to check if various numbers are on the list.\n";

    // Create an empty list object
    LinkedList numList;

    // Get console input from user to add numbers to list
    cout << "\nEnter Five numbers: ";
    for (int i = 0; i < 5; i++)
    {
        //Variable to store a number
        double x;
        //Get input from user
        cin >> x;
        //Call Class object to add number x from user
        numList.add(x);
    }
    // Test if number is on linked list
    for (int i = 0; i < 5; i++)
    {
        //Variable to store a number
        double x;

        //Ask user to enter a number
        cout << "Enter a number to test membership for: ";
        //Get user input
        cin >> x;

        //Call boolean function isMember to check if the number
        //input by the user is on the list. If function returns a true
        //then the number is on the list, If false it is not on list.
        if (numList.isMember(x))
            cout << "\n" << x << " is on the linked list." << endl;
        else
            cout << "\n" << x << " is not on the linked list!" << endl;
    }
    return 0;
}
