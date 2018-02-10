/****************************************************
Name: Bruce Adams
Date: October 26, 2016
CS 2308-005
Homework 7
*****************************************************/
//Add include files
#include "DayOfYear.h"
#include<iostream>
#include<string>

/****************************************************
This program uses three total files: Homework7.cpp,
DayOfYear.cpp and DayOfYear.h to instantiate an object
of the Class DayOfYear. The program will ask the user
for a number, and then convert that number into the
correct Month and day of the year.
*****************************************************/

using namespace std;

int main()
{
	//Define integer day_num for the number entered
	//by the user.
	int day_num;

	//Ask for the total day number of the year
	cout << "Enter a number, and the program "<<endl;
	cout << "will convert the number into " <<endl;
	cout << "the correct month and day : ";

	//Input variable day number from user
	cin >> day_num;
	cout << endl;

	//Check to make sure the day entered is a valid day number
	//If number is not valid, program exits
	if(day_num <= 0 || day_num > 365)
	{
		cout << "You must enter a valid number! Please enter 1 to 365! " << endl;
		cout << "Program has terminated!" << endl;
		return 1;
	}

    //Create object objDayYear of Class DayOfYear with input variable day
	DayOfYear objDayYear(day_num);

	//Call the method print using the class object objDayYear
	//This will pass control to DayOfYear.cpp and then back
	//to Homework 7.cpp to display the correct number format
	objDayYear.print();

	//End main program
	return 0;
}
