/****************************************************
Name: Bruce Adams
Date: October 26, 2016
CS 2308-005
Homework 7
*****************************************************/
//Add include files
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <iostream>
#include <string>

using namespace std;

//Day of the year class declaration. This Class has
//two static const variables that are used as arrays
//to store the names of the months and the days in
//each month.

class DayOfYear
{
    //Define int day as private variable
    private:
        int day;

    public:
        // Constructor with int parameter
        DayOfYear(int);

        //Two static const variables, an int and string arrays
        static const int totalDaysInMonth[];
        static const string MonthName[];

        //The print method prototype
        void print();
};
#endif // DAYOFYEAR_H
