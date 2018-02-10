/****************************************************
Name: Bruce Adams
Date: October 14, 2016
CS 2308-005
Homework 5, Problem 7.33
*****************************************************/

#include <iostream>

using namespace std;

struct Rectangle
{
	int length;
	int width;
};

//Function prototype
void getLength (Rectangle &rect);

int main()
{
    Rectangle item;
	getLength(item);
	
	cout <<"The rectangle length is : " << item.length;
	return 0;
}

//*****************************************************************************
// Function getLength will receive a Rectangle structure passed to it
// by reference so that new values can be stored in the length field by a user
//*****************************************************************************
void getLength (Rectangle &rect)
{
	cout <<"Enter the rectangles length : ";
	cin >> rect.length;
}		



