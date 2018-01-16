/*************************************************************
Authors: Bruce Adams

Program Description: The user is asked to enter either a 1,
2, 3, 4, 5, 6, 7 or 9. Each number corresponds to a function
that will either get or show quizzes, programs or test grades.
The program uses 1D Vectors to store and access the data
**************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "mygrades.h"

using namespace std;

// Main function for control of program flow
int main()
{
    // Variables to store user number input
    int choice;

    // Variables to store scores
    double quizScore, progScore, testScore = 0;
    // Variables to store averages
    double quizAvg, progAvg, testAvg, totalAvg = 0;
    // Variables to hold the out of score
    int outOfScore = 0;
    int testNum = 0;


    // Create objects of class MyGrades
    MyGrades quizVec;
    MyGrades progVec;
    MyGrades testVec;
    MyGrades totalVec;

    // Output to console the program instructions
    cout <<"Welcome to My Grades APP."<<endl<<endl;

    // Main do while loop
    do {
        try {
            cout <<endl;
            cout <<"1. Set A quiz Grade\n";
            cout <<"2. Set A Programming Assignment Grade\n";
            cout <<"3. Set A Test Grade\n";
            cout <<"4. Show All quiz Grades\n";
            cout <<"5. Show All Programming Assignment Grades\n";
            cout <<"6. Show All Test Grades\n";
            cout <<"7. Show Overall Grades\n";
            cout <<"9. Exit The Program\n\n";

            // Ask user to enter their choice
            cout <<"Enter your choice ---->   ";
            cin >> choice;
            cout <<endl;

            // Error checking for input validation
            if (!(cin) || (choice < 1 || choice > 9 || choice == 8))
               throw choice;

            // Main switch loop for program
            switch (choice) {

                case 1:
                    cout <<"Please enter a quiz score (0 to 10) : ";
                    cin >> quizScore;
                    cout <<endl;
                    // Call setQuizGrades method to input quiz
                    // grades into the quizVec vector
                    quizVec.setQuizGrades(quizScore);
                    break;

                case 2:
                    cout <<"Please enter a programming assignment score (0 to 10) : ";
                    cin >> progScore;

                    // Call setProgGrades method to input programming
                    // assignment grades into the progVec vector
                    progVec.setProgGrades(progScore);
                    break;

                case 3:
                    cout <<"Please enter a Midterm Test score (0 to 20): ";
                    cin >> testScore;
                    cout <<endl;

                    // Call setTestGrades method to input Midterm
                    // test grades into the testVec vector
                    testVec.setTestGrades(testScore);
                    break;

                case 4:
                    quizAvg = quizVec.getQuizzes();
                    break;

                case 5:
                    progAvg = progVec.getProgs();
                    break;

                case 6:
                    testAvg = testVec.getTests();
                    break;

                case 7:
                    cout <<endl;
                    cout <<"Show Overall All Grades."<<endl<<endl;
                    cout <<"My Overall Grades so far are as follows: "<<endl<<endl;

                    quizAvg = quizVec.getQuizzes();
                    if (quizAvg)
                        outOfScore += 10;

                    progAvg = progVec.getProgs();
                    if (progAvg)
                        outOfScore += 20;

                    testAvg = testVec.getTests();
                    testNum = testVec.getTestTotal();
                    outOfScore += testNum;

                    totalAvg = quizAvg + progAvg + testAvg;
                    totalVec.getOverall(totalAvg);
                    cout <<" out of "<<outOfScore<<endl<<endl;;
                    outOfScore = 0;

                    break;
                case 9:
                    // Exit program
                    break;

                default:
                    break;
            } // End of switch-case
        } // Validation for improper input on switch/case
            catch (int choice) {
            cout << endl << endl;
            cout <<"Invalid choice!"<<endl<<endl;
            cin.clear();    // Clear the buffer
            cin.ignore(256,'\n');
        }
    } while (choice != 9);  // End of main do-while loop


    // Program terminated to output
    // Display to console the signature lines
    cout <<endl;
    cout <<"This APP was designed and implemented \n";
    cout <<"by Bruce Adams\n";
    cout <<"February 16th, 2017\n\n";

    return 0;
}   // End of main driver
