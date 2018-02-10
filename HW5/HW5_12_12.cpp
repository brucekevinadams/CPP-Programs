/****************************************************
Name: Bruce Adams
Date: October 14, 2016
Homework 5 Problem 12.12
*****************************************************/

//This program will ask a user to input a password, then
//parse the string to check for length, at least one uppercase
//and lowercase letters and at least one digit.


#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    //Declare variables
    string strInput;
    int strUpper = 0, strLower = 0, strDigit = 0;
    bool progGood, strNum = false;

    cout << "Please enter a password (maximum  of 30 characters) : "<<endl;
    cout << "Password must have at least 6 characters, have 1 uppercase letter, "<<endl;
    cout << "have 1 lowercase letter, and at least 1 digit : "<<endl;
    cin >>strInput;

    //Error checking for length of string, exits if lower than 6 or
    //greater than 30 characters
    if (strInput.length() < 6)
    {
       cout <<"Password must have at least six characters!"<<endl;
       return 1;
    }
    else if (strInput.length() >30)
    {
       cout <<"Password must be shorter than 30 characters!"<<endl;
       return 1;
    }
    else strNum = true;

    //Loop to check each element of string to see if there is an
    //uppercase, a lowercase, and at least one digit.
    for (int i=0; i<strInput.length(); i++)
    {
        if (isupper(strInput[i]))
            strUpper++;
        else if (islower(strInput[i]))
            strLower++;
        else if (isdigit(strInput[i]))
            strDigit++;
    }

    //Output check to console if criteria is not met
    if (strUpper < 1)
        cout <<"Password must have at least one uppercase character!"<<endl;
    if (strLower < 1)
        cout <<"Password must have at least one lowercase character!"<<endl;
    if (strDigit < 1)
        cout <<"Password must have at least one digit!"<<endl;

    //Output check to console if all criteria is met
    if (strNum && strUpper >= 1 && strLower >=1 && strDigit >=1 )
        cout <<"Password is good and meets all stated criteria!"<<endl;

    return 0;
}



