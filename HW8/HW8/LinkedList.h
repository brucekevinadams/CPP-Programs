/****************************************************
Name: Bruce Adams
Date: November 18, 2016
Homework 8
*****************************************************/

#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

//Create Class for ListNode
class ListNode
{
    private:
    double value;                       //Create double to store value
    ListNode *next;                     //Create pointer for next
    friend class LinkedList;            //Create friend class LinkedList

    public:
    ListNode(double x, ListNode *ptr)     //Create ListNode
    {
        value = x; next = ptr;
    }

};

//Create Class for simple linked list
class LinkedList
{
    private:
        ListNode *head;                 //Create head pointer

    public:
        LinkedList( ) { head = NULL;}   //Default Constructor
        ~LinkedList();                  //Destructor
        void add(double x);             //Method to add number to list
        bool isMember(double x);        //Method for finding number
};
#endif
