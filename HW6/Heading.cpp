/****************************************************
Name: Bruce Adams
Date: October 21, 2016
CS 2308-005
Homework 6, Problem 10
*****************************************************/
#include "Heading.h"   // Needed for the Heading class
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//2 parameter default constructor
Heading::Heading(string c, string r)
{
    if (c.empty())
        companyName = "ABC Industries";
    else
        companyName = c;
    if (r.empty())
        reportName = "Report";
    else
        reportName = r;
}

//Method definition for displaying 1 line
void Heading::displayOneLine()
{
    cout << companyName << " " << reportName <<endl;
}

//Method definition for displaying a boxed console output
void Heading::displayBoxed()
{
    //Declare length variables for names
    int len;
    int cLen = companyName.length();
    int rLen = reportName.length();

    //Make the *'s big enough
    if (cLen > rLen)
        len = cLen*2;
    else
        len = rLen*2;

    //Declare variables to find indent buffers
    int cFormat = (len/2) - (cLen/2);
    int rFormat = (len/2) - (rLen/2);

    //For loop to output stars top line
    for (int i=0; i<len; i++)
    {
        cout<<"*";
    }
    cout <<endl;

    //Indent the correct spaces to center the
    //Company name in the middle of the stars
    for (int i=0;i<cFormat-1; i++)
        cout <<" ";

        cout << companyName << endl;

    //Indent the correct spaces to center the
    //Report name in the middle of the stars
    for (int i=0;i<rFormat-1; i++)
        cout <<" ";
        cout << reportName << endl;

    //For loop to output stars bottom line
    for (int i=0; i<len; i++)
    {
        cout<<"*";
    }
    cout <<endl;
}




