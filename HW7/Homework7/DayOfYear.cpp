/****************************************************
Name: Bruce Adams
Date: October 26, 2016
CS 2308-005
Homework 7

This program has the definition of the Constructor as
well as the method print that was prototyped in DayOfYear.h
*****************************************************/

//Add include files
#include "DayOfYear.h"
#include<iostream>
#include<string>

//Reserve space and define months as the array totalDaysInMonth
const int DayOfYear::totalDaysInMonth[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

//Reserve space and define month names as an array
const string DayOfYear::MonthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//Define constructor with one int variable d
//Constructor sets private variable day to input d
DayOfYear::DayOfYear(int d)
{
    day = d;
}

//Define the method print here
void DayOfYear::print()
{
    //Set variable month to zero
	int month = 0;

    //Loop to determine which month the number falls into
    //Use modulus to figure this out.
	while (DayOfYear::totalDaysInMonth[month] < day)
		month = (month + 1) %12;

    //Print to console what the result is
    cout << "Day " << day << " would be ";
	//Display the correct month and day
	cout << DayOfYear::MonthName[month] << " " << day - DayOfYear::totalDaysInMonth[month-1];
	cout <<endl;
}
