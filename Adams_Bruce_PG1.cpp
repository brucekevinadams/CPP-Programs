/****************************************************
Authors: Bruce Adams
Date: February 13, 2017

Program Description: The user is asked to enter a positive
number from 1 to 199, and that number is then used in seven
different functions to perform different tasks. Tasks are
1) coin conversion, 2) age data, 3) print to console,
4) armstrong number, 5) factorial, 6) prime check, 7)hailstone
sequence detection.
*****************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void computeChange(int);
void computeAge(int);
void printDigits(int,int&,int&,int&);
void numToText(int);
void armstrongNumber(int,int,int,int);
void computeFactorial(int);
bool primeChecker(int);
void computePrimes(int);
void hailstoneSequence(int);

int main()
{
    // Variable to store user input for Y/N control
    char userInput;
    // Variables to store user number input
    int inputNumber, firstDigit,secondDigit, thirdDigit;

    // Output to console the program instructions
    cout <<"Welcome to our perfect matrix program. The function of the program is"<<endl;
    cout <<"to: "<<endl<<endl;
    cout <<"\t1. Allow the user to enter the size of the perfect matrix, such as\tN. <>2."<<endl;
    cout <<"\t2. Create a 2 D vector array of size N x N."<<endl;
    cout <<"\t3. Populate the 2 D vector array with distinct random numbers."<<endl;
    cout <<"\t4. Display the sum for each row, column, and diagonals then"<<endl;
    cout <<"\t   determine whether the numbers in N x N vector array are perfect"<<endl;
    cout <<"\t   matrix numbers."<<endl<<endl;



    // Main do-while loop for program
    do
    {
        // Ask user to enter number from 1 to 199
        cout <<"Enter a positive integer >0 and <200 ---->   ";
        cin >> inputNumber;

        // Error checking on number to make sure it is an integer
        // and not a character
        while (!cin || inputNumber <=0 || inputNumber >199)
        {
            cout <<endl;
            if (!cin) {
                cout <<"\n\nError *** Incorrect input - You entered a character\n";
                cout <<"Enter a Positive Integer\n";
            }
            else if (inputNumber <=0 || inputNumber >199) {
                cout <<"\n\n\Error *** Number must be > 0 and < 200 ---> ";
            }
            cin.clear();
            cin.ignore(256,'\n');
            cin >> inputNumber;
        }

        // Buffer line
        cout << endl;

        // Function Calls
        computeChange(inputNumber);
        computeAge(inputNumber);
        printDigits(inputNumber,firstDigit,secondDigit,thirdDigit);
        armstrongNumber(inputNumber,firstDigit,secondDigit,thirdDigit);
        computeFactorial(inputNumber);
        primeChecker(inputNumber);
        computePrimes(inputNumber);
        hailstoneSequence(inputNumber);

       // Buffer lines
        cout <<endl<<endl;

        // Output to console for user to continue or not
        cout <<"Would you like to try for another number?\n\n";
        cout <<"Enter y || Y for yes or n || N for no --->  ";

        cin >>userInput;

        while (userInput != 'Y' && userInput != 'y' && userInput != 'N' && userInput != 'n') {
            cout <<"\n\nError *** Invalid choice - Must be Y || y || N || n   --->";
            cin >> userInput;
        }

    } while (userInput == 'Y' || userInput == 'y');

    // Program terminated to output
    cout <<endl;
    cout <<"This APP was designed and implemented by\n";
    cout <<"Bruce Adams\n";
    cout <<"January 25 2017\n\n";

    return 0;
}

void computeChange(int inputNumber)
{
    cout<<"Currency calculation "<<endl<<endl;
    cout<<"$"<<inputNumber<<" is equivalent to:"<<endl<<endl<<endl;
    cout<<inputNumber*4<<" quarters"<<endl
        <<inputNumber*10<<" dimes"<<endl
        <<inputNumber*20<<" nickels"<<endl
        <<inputNumber*100<<" pennies"<<endl;
    cout <<endl;
}

void computeAge(int inputNumber)
{
    long long minAge, secAge;
    minAge = inputNumber;
    secAge = inputNumber;
    cout<<"Age calculation "<<endl<<endl;
    cout<<"Assuming that you are "<<inputNumber<<" years old, then"<<endl<<endl;
    cout<<"You are "<< inputNumber*12<<" months old"<<endl
        <<"You are "<< inputNumber * 365<< " Days old"<<endl
        <<"You are approximately " << inputNumber * 8760<< " hours old"<<endl
        <<"You are approximately "  << minAge *525600 << " minutes old"<<endl
        <<"You are approximately " << secAge * 31536000 << " seconds old"<<endl;
    cout <<endl<<endl;
}
void printDigits(int inputNumber, int &firstDigit, int &secondDigit, int &thirdDigit)
{

    //Determine the digits
    thirdDigit = inputNumber % 10;
        inputNumber/=10;
    secondDigit = inputNumber % 10;
        inputNumber/=10;
    firstDigit = inputNumber % 10;

    //Display the digits
    //100's place digit is 1st digit
    if(firstDigit!=0)
        cout<<firstDigit<<"\t";

    //10's place digit is 2nd digit
    if(firstDigit!=0)
     cout<<secondDigit<<"\t";
    else if(firstDigit==0 && secondDigit!=0)
        cout<<secondDigit<<"\t";

    //One's place digit is 3rd digit
    cout<<thirdDigit<<endl;

    //Convert the digits to text and display
    //the digits underneath each corresponding number
    if(firstDigit!=0)
        numToText(firstDigit);
    if(firstDigit!=0)
        numToText(secondDigit);
    else if(firstDigit==0 && secondDigit!=0)
        numToText(secondDigit);

    numToText(thirdDigit);

    cout<<endl;
}
void numToText(int changedNumber)
{
    switch(changedNumber)
    {
    case 1:
        cout<<"one \t";
        break;

    case 2:
        cout<<"two \t";
        break;
    case 3:
        cout<<"three \t";
        break;
    case 4:
        cout<<"four \t";
        break;
    case 5:
        cout<<"five \t";
        break;
    case 6:
        cout<<"six \t";
        break;
    case 7:
        cout<<"seven \t";
        break;
    case 8:
        cout<<"eight \t";
        break;
    case 9:
        cout<<"nine \t";
        break;
    case 0:
        cout<<"zero \t";
        break;
    }

}
void armstrongNumber(int inputNumber, int fD,int sD , int tD)
{
    //Buffer line
    cout <<endl<<endl;

    //Computer if input number is an armstrong number
    if(inputNumber==((fD*fD*fD)+(sD*sD*sD)+(tD*tD*tD)))
        cout<<inputNumber<<" is an armstrong number";
    else
        cout<<inputNumber<<" is NOT an armstrong number"<<endl;

    cout <<endl<<endl;
}
void computeFactorial(int inputNumber)
{
    long double outputNum;
    outputNum = inputNumber;
    cout<<"Factorial of "<<inputNumber<<" = ";

    for(int i= inputNumber-1; i>0; i--)
        outputNum*=i;
    cout<<fixed<<setprecision(0)<<outputNum<<endl;

    cout <<endl;
}
bool primeChecker(int inputNumber)
{
bool isPrime;

    for (int i = 2; i<=inputNumber; i++){
            isPrime = true;
        for(int j = 2;j <= inputNumber-1; j++){
            if(i%j==0){
                isPrime= false;
            }
        }
    }
return isPrime;
cout <<endl<<endl;
}

void computePrimes(int inputNumber)
{
    if(primeChecker(inputNumber))
        cout<<inputNumber<<" is prime"<<endl;
    else
        cout<<inputNumber<<" is not prime"<<endl<<endl;

    cout<<"The list of prime numbers between 1 and "<<inputNumber<<" are:\n";

    for(int i=0; i<= inputNumber; i++){
        if(primeChecker(i)){
            cout<<i<<" number is prime\n";
        }
    }
cout<<endl;
}

void hailstoneSequence(int inputNumber)
{
    cout<<"The sequence of hailstone starting at "<<inputNumber<<" is\n";

    cout <<inputNumber<<" ";

    while(inputNumber!=1)
    {
        if(inputNumber%2==0)
        {
            inputNumber = inputNumber/2;
            cout<<inputNumber<<" ";
        }
        else
        {
            inputNumber = inputNumber*3+1;
            cout<<inputNumber<<" ";
        }
    }
    cout <<endl<<endl;
}
