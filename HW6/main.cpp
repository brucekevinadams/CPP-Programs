/****************************************************
Name: Bruce Adams
Date: October 21, 2016
CS 2308-005
Homework 6, Problem 10
*****************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Heading.h"
using namespace std;

int main()
{

    string companyName;   // To hold the company name
    string reportName;    // To hold the report name
    int input;
    bool flag = true;

    // Get the name of the company
    cout << "What is your company's name? ";
    getline(cin, companyName);

    // Get the name of the report
    cout << "What is the name of the report? ";
    getline(cin, reportName);
    cout <<endl;

    // Create a Heading object.
    Heading display(companyName, reportName);

    cout <<"Do you want one line format (press 1) or boxed format (press 2)?"<<endl;
    cin >> input;

    //This loop checks for input from the user. If user does not enter
    //a 1 or a 2, it will repeat until a 1 or a 2 is entered.
    while (flag == true)
    {
        //User wants a single line output
        if (input == 1)
        {
            //Call class object display, method displayOneLine()
            display.displayOneLine();
            flag = false;
        }
        //User wants a boxed output
        else if (input == 2)
        {
            //Call class object display, method displayBoxed()
            display.displayBoxed();
            flag = false;
        }
        else //Error correction: user must enter 1 or 2
        {
            cout <<"Please enter a 1 or a 2! : "<<endl;
            cin >> input;
            flag = true;
        }
    }

    return 0;
}
