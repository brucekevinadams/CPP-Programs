/*************************************************************
Author: Bruce Adams

Program Description: The program accepts array size from console
at least 4 or larger. Program fills array with random numbers
from 25 to 500. The program uses recursion to output various
displays including a table of squares, power of function,
sumOfSquares, minMax Numbers, Bubble sort, isMember, notMember and
isItPrime functions.
**************************************************************/

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void generateArray(int[],int);
void tableOfSquares(int);
void powerFunction(int);
int sumOfSquares(int);
void bubbleSort(int[], int);
int power(int,int);
bool isMember(int[],int, int);
int minMax(int[], int, int, int, int);
bool binaryNotMember(int[], int, int);
bool isPrime(int, int);
void printArray(int[], int);


//**************************************************
// Main function                                   *
// This function drives the program.               *
//**************************************************
int main()
{
    // Declare variables
    char choice;
    int arraySize;
    int hi;
    int lo;
    bool notMember;
    bool prime;

	cout <<"Thinking Recursively\n\n";
	cout <<"The purpose of this program is to\n";
	cout <<"use recursion to :-\n\n";
	cout <<"1.\tDisplay squares of integers in ascending\n";
	cout <<"\torder from 1 to the last element in the array\n";
	cout <<"2.\tRaise the first number to a power of 2\n";
	cout <<"3.\tReturn the sums of squares of the numbers\n";
	cout <<"\tfrom 0 to the fifth element in the array\n";
	cout <<"4.\tSearch the array for the array's min and max values\n";
	cout <<"5.\tSort the array in descending order\n";
	cout <<"6.\tSearch the array for the first value in the array\n";
	cout <<"7.\tSearch the array for the number 600\n";
	cout <<"8.\tDetermine if a number is prime (process all array values)\n\n";


    // Main do while loop
    do {
            try
            {

                cout <<"Select from the following menu\n";
                cout <<"A.  Enter array size that is > 4.\n";
                cout <<"X.  Terminate the program.          ";
                cin >> choice;

                // Error checking for input validation
                if (!(cin) || (choice != 'A') && (choice != 'a'))
                throw choice;

                // Start of switch-case
                switch (choice) {

                    case 'a':
                    case 'A':
                        {
                        try{
                        cout<<"\nEnter array size: ";
                        cin>>arraySize;
                        cout<<endl;

                        //error checking for array size validation
                        if(!(cin)|| arraySize<4)
                            throw arraySize;

                        // Initialize array of numbers
                        int randArray[arraySize];

                        // Generate array
                        generateArray(randArray,arraySize);

                        // Call recursive function to create table of squares
                        tableOfSquares(randArray[arraySize-1]);

                        // Call recursive function to raise element zero to power of two
                        powerFunction(randArray[0]);

                        cout<<endl;
                        cout<<"Sum of squares between 0 and "<<randArray[arraySize-2]<<" is: "<<sumOfSquares(randArray[arraySize-2])<<endl<<endl;

                        // Reset hi and lo numbers when function is called again inside loop
                        hi = -999, lo = 999;
                        // Call Recursive minMax function
                        minMax(randArray, arraySize, arraySize, hi, lo);
                        cout <<endl<<endl;
                        cout <<"Sorted Array"<<endl;
                        // Call recursive bubbleSort function
                        bubbleSort(randArray,arraySize);
                        printArray(randArray, arraySize);

                        // Functions for detecting numbers
                        cout <<"Member Functions:"<<endl;
                        cout <<"Does the array: ";
                        for(int i =0;i<arraySize; i++)
                                cout<<randArray[i]<<" ";
                        cout <<"have the number "<<randArray[3]<<"? ";

                        // Call recursive linear search function
                        isMember(randArray, arraySize, randArray[3]);
                        cout <<"Does the array: ";
                        for(int i =0;i<arraySize; i++)
                                cout<<randArray[i]<<" ";
                        cout <<"have the number 600?";

                        // Call recursive binary search function, search for number 600
                        notMember = binaryNotMember(randArray, arraySize, 600);
                        if (!notMember)
                            cout <<" NO"<<endl<<endl;
                        else
                            cout <<" YES"<<endl<<endl;

                        // Call recursive function to check if prime or not
                        cout <<"Is it prime:\n";
                        for (int i=0; i<arraySize; i++)
                        {
                            prime = isPrime(randArray[i], arraySize);
                            if (prime)
                                cout <<"The number "<<randArray[i]<<" is Prime"<<endl;
                            else
                                cout <<"The number "<<randArray[i]<<" is Not Prime"<<endl;
                        }
                        cout <<endl<<endl;
                         // Break out of case 1
                        break;
                        }
                           catch(int arraySize){
                            cout<<endl<<endl;
                            cout<<"***Invalid Array Size Value***"<<endl;
                            if(arraySize<=4)
                                cout<<"Enter array size that is >4"<<endl<<endl;
                            else
                                cout<<"Enter an integer, not a char"<<endl;
                            cin.clear();
                            cin.ignore();
                        }
                }
                    default:
                        break;
                } // End of switch-case
            } // Validation catch for improper input on try
            catch (char choice) {
                cout << endl << endl;
                if (choice !='X' && choice != 'x')
                cout <<"***  Invalid Option  ***"<<endl<<endl<<endl;
                cin.clear();    // Clear the buffer
                cin.ignore(256,'\n');
            }

    } while (choice != 'X' && (choice != 'x'));  // End of main do-whi

    cout<<"Bruce Adams\n";
    cout <<"April 2017\n";
	return 0;
}

// Function to generate random array
void generateArray(int randArray[],int arraySize)
{
srand(time(NULL));
for(int i =0; i<arraySize;i++)
    randArray[i]=rand()%475+25;

cout<<"The generated array is:  ";

for(int i =0;i<arraySize;i++)
    cout<<randArray[i]<<" ";

cout<<endl<<endl;
}

// Function to recursively generate table of squares
void tableOfSquares(int tableSize)
{
    cout<<"Table of square values 1 - "<<tableSize<<endl<<endl;
    cout<<"N\t"<<"N squared"<<endl;
    for(int i=1; i<tableSize+1; i++)
    {
        cout<<i<<"\t"<<power(i,2)<<endl;

    }
    cout<<endl<<endl;
}

// Function calls recursive function to raise number to power of two
void powerFunction(int num)
{
    cout<<"Power function:"<<endl;
    cout<<num<<" raised to the 2nd power is "<<power(num,2)<<endl<<endl;
}

// Recursive function to return the sum of squares
int sumOfSquares(int num)
{
   if(num==0)
    return 1;
   else
    {
        return(sumOfSquares(num-1) + power((num),2));

    }
}

// Recursive function to return the 2nd power of element zero
int power(int x, int y)
{
    if(y==0)
        return 1;
    else if(y==1)
        return x;
    else
        return(x* power(x,y-1));
}

// Recursive function to display array as bubble sorted
void bubbleSort(int randArray[], int arraySize)
{
    if(arraySize==1)
        return;

    for(int i =0; i<arraySize-1; i++)
    {
        if(randArray[i]<randArray[i+1])
            swap(randArray[i],randArray[i+1]);

        bubbleSort(randArray,arraySize-1);
    }
}

// Recursive function to determine whether 4th value is a member of array
bool isMember(int randArray[], int arraySize, int value)
{
    if(value<0)
        return false;
    if(randArray[arraySize]==value)
    {
        cout<<"YES"<<endl;
        return true;
    }
    return isMember(randArray,arraySize-1,value);
}


// Function to recursively find the min and max values
int minMax(int randArray[], int tempSize, int arraySize, int hi, int lo)
{
    // Base case
    if(tempSize == 0)
    {
        cout <<"Min Number of ( ";
        for(int i =0;i<arraySize; i++)
        {
            if (i == arraySize-1)
                cout<<randArray[i];
            else
                cout<<randArray[i]<<" , ";
        }

        cout <<" ) "<<endl;
        cout<<"is : "<<lo<<endl;
        cout <<"Max Number of ( ";
        for(int i =0;i<arraySize; i++)
        {
            if (i == arraySize-1)
                cout<<randArray[i];
            else
                cout<<randArray[i]<<" , ";
        }
        cout <<" ) "<<endl;
        cout<<"is : "<<hi<<endl;

        return randArray[arraySize];
    }

    //Determine the hi and lo numbers
    if (randArray[tempSize-1] > hi)
      hi = randArray[tempSize-1];
    if (randArray[tempSize-1] < lo)
        lo = randArray[tempSize-1];

    //Recursive call
    minMax(randArray, tempSize-1, arraySize, hi, lo);
}

// Recursive boolean binary search function to determine whether a number is in an array
bool binaryNotMember(int randArray[], int arraySize, int item){

	int first = 0,
		last = arraySize - 1,
		mid;
	bool found = false;

	if (first <= last){ // Check to see it it needs to go any further.
		return false;
		mid = (first + last) / 2;

		if(randArray[mid] == item) // item found
			found = true;

		else if (randArray[mid] > item)
			return  binaryNotMember (randArray, mid -1, item) ; //checking array < mid
		else
			return binaryNotMember (randArray, mid + 1,item);   //checking array > mid
	}
}

// Recursive function to check if numbers are prime
bool isPrime(int n, int d)
{
    //Base case
    if(n<2)
        return 0;
    if(d == 1)
        return true;
    else
    {
        if(n % d == 0)
            return false;
        else
            // Recursive function
            return isPrime(n, d - 1);
    }
}

void printArray(int arr[], int n)
{
    // Call recursive bubble sort descending function
    bubbleSort(arr,n);
    // Print the sorted array
    for (int i=0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;
}
