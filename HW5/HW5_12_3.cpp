/****************************************************
Name: Bruce Adams
Date: October 14, 2016
CS 2308-005
Homework 5 Problem 12.3
*****************************************************/

//This program will ask a user to input a string then
//pass the string to a function as a C-string. The function
//will then parse the c-string to determine the number of
//words that was entered and display it on console

#include <iostream>
#include <cctype>
using namespace std;

//Function prototype for determining word count in a C-string
int wordCount(char *);

int main()
{
    //Declare strInput array to hold C-string input
    char strInput[121];

    cout << "Please enter a string (maximum  of 120 characters) : ";
    cin.getline(strInput,121);

    cout << "String  has " << wordCount(strInput) << " words"<< endl;

    return 0;
}

int wordCount(char * strInput)
{
    //Declare variables
    bool numSpaces = true;
    int numWords = 0;

    //While loop to parse C-string pointer array
    //Loop terminates when NULL character is encountered
    while (*strInput != NULL)
    {
        //Check for spaces or tabs, set numSpaces to true
        if (isspace(*strInput))
        {
         numSpaces = true;
        }
        //If there are spaces,
        else if (numSpaces)
        {
            //Check to see if the characters are letters
            //that make up words, and not numbers or
            //special characters
            if (isalpha(*strInput))
            {
                numWords++;
                numSpaces = false;
            }
        }
        //Increment the input so as to escape the while loop
        ++strInput;
    }

    //Return the number of words to the main program
    return numWords;
}
