/****************************************************
Name: Bruce Adams
Date: October 21, 2016
CS 2308-005
Homework 6, Problem 10
*****************************************************/
#ifndef HEADING_H
#define HEADING_H
#include <iostream>
#include <string>
using namespace std;

//Create class Heading
class Heading
{
    //Declare variables for report and company names
    private:
        string reportName;
        string companyName;

    public:
        //Default Constructor
        Heading();
        // Constructor with 2 parameters
        Heading(string, string);

        //Mutators
        void displayOneLine();
        void displayBoxed();

        //Accessors
        string getCompName()
        { return companyName; }
        string getReportName()
        { return reportName; }

}; //end of Class Heading
#endif
