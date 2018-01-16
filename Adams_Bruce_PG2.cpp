/****************************************************
Authors: Bruce Adams

Program Description: The user is asked to enter a positive
number 2 or greater (N), and that number is then used to create a
2D vector of N x N. The program will then fill the specified
vector array with unique numbers that are randomly generated.
The program then prints to console the vector, the sum of each
row, the sum of each column and the sum of the two diagonals.
It then informs the user if it is a perfect matrix or not.
*****************************************************/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

// Define class for 2D Vector
class v2DMatrix
{
private:
    int rows, cols;
    int num = 0, rowSum = 0, colSum = 0, totalSum = 0;
    int const MAX_RAND = 149;
    bool perfectRow = false;
    bool perfectCol = false;
    bool perfectDiagLeft = false;
    bool perfectDiagRight = false;
    int perfectNum = 0;
    vector< vector< int > > vec;
    vector< int > row;

public:
    v2DMatrix(int rows,int cols);
    void setRows(int row);
    void setCols(int col);
    int getRows();
    int getCols();
    int repeatCheck(int num);
    int diagLeftCheck(int row, int col);
    int diagRightCheck(int row, int col);
    void printv2DMatrix();
};

// Constructor for 2D Vector Function
v2DMatrix::v2DMatrix(int rows,int cols)
{
    // Set randomizer based on time
    srand(time(NULL));

    // Create 2D vector
    // Looping through outer vector
    for(int i = 0; i< rows; i++)
    {
        //Looping through inner vector
        for(int j = 0; j < cols; j++)
        {
            int randNum = rand() % MAX_RAND +1;
            row.push_back(repeatCheck(randNum));
        }
            vec.push_back(row);
            row.clear();
    }

    // Set the rows and columns
    setRows(rows);
    setCols(cols);

    // Print the 2D vector matrix
    printv2DMatrix();

    // Loop to Determine total sum of all numbers in matrix
    for(int i = 0; i<rows ; i++)
    {
         for(int j = 0; j<cols ; j++)
        {
            totalSum += vec.at(i).at(j);
        }
    }
    // Display to console what the perfect number is
    perfectNum = totalSum / 3;
    cout <<"The perfect number is : "<< perfectNum <<endl<<endl;

    // Loop to Determine total sum of each row in matrix
    for(int i = 0; i<rows ; i++)
    {
         for(int j = 0; j<cols ; j++)
        {
            rowSum += vec.at(i).at(j);
        }
        cout <<"Sum of numbers in Row\t"<<" # "<<i+1<<"\t=\t"<< rowSum <<endl;
        if (rowSum == perfectNum)
            perfectRow = true;
        else
            perfectRow = false;

        rowSum = 0;
    }
    // Buffer line
    cout <<endl;
    //Determine total sum of each column in matrix
    for(int j = 0; j<cols ; j++)
    {
         for(int i = 0; i<rows ; i++)
        {
            colSum += vec.at(i).at(j);
        }
        cout <<"Sum of numbers in Col\t"<<" # "<<j+1<<"\t=\t"<< colSum <<endl;
        if (colSum == perfectNum)
            perfectCol = true;
        else
            perfectCol = false;

        colSum = 0;
    }
    // Buffer line to console
    cout <<endl;

    // Determine total sum of left diagonal in matrix
    diagLeftCheck(rows, cols);

    // Determine total sum of right diagonal in matrix
    diagRightCheck(rows, cols);

    // Buffer lines to console
    cout <<endl<<endl;

    //Check if 2D Matrix is a perfect matrix
    if ((perfectRow) && (perfectCol) && (perfectDiagLeft) && (perfectDiagRight))
    {
        cout <<"The above 2D Matrix is a PERFECT MATRIX!\n\n";
    }
    else
    {
        cout <<"The above 2D Matrix is NOT a perfect matrix\n\n";
    }
}

// This function will set the Rows
void v2DMatrix::setRows(int row)
{
    rows = row;
}

// This function will set the Columns
void v2DMatrix::setCols(int col)
{
    cols = col;
}

// This function will get the Rows
int v2DMatrix::getRows()
{
    return rows;
}

// This function will get the Columns
int v2DMatrix::getCols()
{
    return cols;
}

// This function checks for repeating numbers in
// the 2D Vector matrix
int v2DMatrix::repeatCheck(int num)
{

    // Outer loop for vector rows
    for ( int i = 0; i < vec.size(); i++ )
    {
        // Inner loop for vector columns
        for ( int j = 0; j < vec.size(); j++ )
        {
            // While Loop continues until unused number
            // is randomly created, then that number is
            // returned to calling function
            while ( vec.at(i).at(j) == num )
            {
                // Create variable for random number
                num = rand() % MAX_RAND +1;
            }
        }
    }
    return num;
}

// This function will find all elements in the left
// Diagonal of the 2D Vector matrix and add them up
int v2DMatrix::diagLeftCheck(int row, int col)
{
    // Initialize variables
    int i, j, sum = 0;
    // Loop to determine sum of left diagonal
    for ( i = 0; i < row; i++ ) {
      for ( j = 0; j < col; j++ ) {
         if ( i == j ) {
            sum += vec[i][j];
         }
      }
    }
    // Output to console what sum is
    cout <<"Sum of numbers in 1st diagonal\t=\t"<<sum;
    cout<<endl;
    // Check for perfect number sequence
    if (sum == perfectNum)
        perfectDiagLeft = true;
    else
        perfectDiagLeft = false;

    return sum;
}

// This function will find all elements in the right
// Diagonal of the 2D Vector matrix and add them up
int v2DMatrix::diagRightCheck(int row, int col)
{
    // Initialize variables
    int i, j, sum = 0;
    // Loop to determine sum of right diagonal
    for ( i = 0; i < rows; i++ ) {
      for ( j = 0; j < cols; j++ ) {
         if ( (i + j) == (rows - 1) ) {
            sum += vec[i][j];
         }
      }
    }
    // Output to console what sum is
    cout <<"Sum of numbers in 2nd diagonal\t=\t"<<sum;
    cout<<endl;
    // Check for perfect number sequence
    if (sum == perfectNum)
        perfectDiagRight = true;
    else
        perfectDiagRight = false;

   return sum;

}

// This function prints the N x N 2D Matrix to console
void v2DMatrix::printv2DMatrix()
{
    for(int i=0;i<rows;++i)
    {
        cout<<endl;
        for(int j=0;j<cols;++j)
        {
            cout<<vec[i][j]<<"\t";
        }
        //Add vertical buffer
        cout <<endl;
    }

    // Buffer line
    cout <<endl;
}

// Main function for control of program flow
int main()
{
    // Set randomizer based on time
    srand((unsigned)time(NULL));

    // Variable to store user input for Y/N control
    char userInput;

    // Variables to store user number input
    int inputNum;

    // Output to console the program instructions
    cout <<"Welcome to our perfect matrix program. The function of the program is"<<endl;
    cout <<"to: "<<endl<<endl;
    cout <<"\t1. Allow the user to enter the size of the perfect matrix, such as"<<endl;
    cout <<"\t   N. N>=2."<<endl;
    cout <<"\t2. Create a 2 D vector array of size N x N."<<endl;
    cout <<"\t3. Populate the 2 D vector array with distinct random numbers."<<endl;
    cout <<"\t4. Display the sum for each row, column, and diagonals then"<<endl;
    cout <<"\t   determine whether the numbers in N x N vector array are perfect"<<endl;
    cout <<"\t   matrix numbers."<<endl<<endl;

    // Main do-while loop for program
    do
    {
        // Ask user to enter number 2 or greater for matrix size
        cout <<"Enter the size of the matrix ---->   ";
        cin >> inputNum;

        // Error checking on number to make sure it is an integer
        // and not a character
        while (!cin || inputNum < 2)
        {
            cout <<endl;
            if (!cin) {
                cout <<"\n\nError *** Incorrect input - You entered a character\n\n";
                cout <<"Enter the size of the matrix ---->   ";
            }
            else if (inputNum < 2) {
                cout <<"\n\n\Error *** Number must be 2 or greater ---> ";
            }
            // Clear the buffer
            cin.clear();
            cin.ignore(256,'\n');
            cin >> inputNum;
        }

        // Buffer line
        cout << endl;
        cout <<"The perfect matrix that is created for size "<<inputNum<<" :"<<endl;

        // Call class function to create 2D vector matrix
        v2DMatrix vec(inputNum,inputNum);

        // Output to console for user to continue or not
        cout <<"\nWould you like to find another perfect matrix?\n";
        cout <<"Enter y or Y for yes or n or N for no --->  ";
        cin >> userInput;
        cout << endl;

        while (userInput != 'Y' && userInput != 'y' && userInput != 'N' && userInput != 'n') {
            cout <<"\n\nError *** Invalid choice - Must enter y|Y or n|N  --->";
            // Clear the input buffer
            cin.clear();
            cin.ignore(256,'\n');
            cin >> userInput;
            cout <<endl;
        }

    } while (userInput == 'Y' || userInput == 'y'); // While control loop end

    // Program terminated to output
    // Display to console the signature lines
    cout <<endl;
    cout <<"This perfect matrix algorithm was designed\n";
    cout <<"and implemented by Bruce Adams\n";
    cout <<"February 7th, 2017\n\n";

    return 0;
}
