/****************************************************
Name: Bruce Adams
Date: November 18, 2016
Homework 8
*****************************************************/

#include "LinkedList.h"
using namespace std;


// Method to add a number to a linked list
void LinkedList::add(double x)
{
    head = new ListNode(x, head);
}

// Method isMember checks if a number is a member
// of a linked list created by a user
bool LinkedList::isMember(double x)
{
    ListNode *ptr = head; // Use ptr to traverse list

    //Traverse the list until NULL (end of list)
    while (ptr != NULL)
    {
        //Test if the node value is equal to the
        //number that the user is looking for
        if (ptr->value == x)
            return true;            //If found, return true
        else
            ptr = ptr->next;        //If not found, keep looking
    }

    // Method traversed the entire list and did not find
    // matching number, so return a false
    return false;
}

// Create Destructor
LinkedList::~LinkedList()
{
    while (head != NULL)
    {
        ListNode * ptr = head;
        head = head->next;
        delete ptr;
    }
}
