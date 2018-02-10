/****************************************************
Name: Bruce Adams
Date: October 7, 2016
Homework 4
*****************************************************/
#include <iostream>
using namespace std;

//This program is used to gather statistical data about the number of movies
//that college students have seen in a month.

//Function prototypes
void getStudentNumber (int *);    //Prototype to input # of students
void selectionSort(int *, int *); //Prototype to sort array of movies
void CalcMedian(int *, int *);	  //Prototype function to find median
void CalcMode(int *, int *);	  //Prototype function to find mode

int main()
{
    int number;					  //Declare variable for SIZE of array
    int avg;                      //Declare avg variable for average
    int *movies;                  //Declare int pointer movies
    int total=0;				  //Declare variable for total # of movies

    //Call function to input # of students
    getStudentNumber(&number);

    //Dynamically allocate movies array
    movies = new int[number];

	//For loop to ask user how many movies each student has seen
	for (int index = 0; index < number; index++)
	{
		cout << "How many movies did student #" << (index+1) << " see? : ";
      	cin >> movies[index];

      	//Keep a running total of the movies that all the students have seen
      	total = total + movies[index];
   	}

	//Call function to Sort the array
	selectionSort(movies, &number);

	//Calculate average number of movies seen by all students
	avg = total / number;
	cout <<"The average number of movies that the " << number <<" students"
		 <<" saw was " << avg << " movies.\n";

	//Call function to find the median of the array
	CalcMedian(movies, &number);

	//Call function to find mode of the array
	CalcMode(movies, &number);

	//Deallocate the dynamic memory for movies array
	delete[] movies;

	return 0;
}

//Function to get number of students from user
//Input is a pointer to keep the same number
//for multiple functions that are called
void getStudentNumber(int *input)
{
	//Ask user how many students were surveyed
	cout <<"How many students were surveyed? ";
	//Input the # of students from the user
	cin >> *input;

}

//Function definition to sort the array of # of movies seen per student
//using a selection sort method
void selectionSort(int *arr, int *number)
{
	//Variables to hold start and minimum values in array
	int start, mIndex, mValue;

	//Outer For loop to sort the array
	for (start = 0; start < (*number-1); start++)
	{
		mIndex = start;
		mValue = arr[start];

		//Nested inner for loop to sort the array
		for(int index = start + 1; index < *number; index++)
		{
			if(arr[index] < mValue)
			{
				mValue = arr[index];
				mIndex = index;
			}
		}

	arr[mIndex] = arr[start];
	arr[start] = mValue;
	}
	cout <<endl;
}

//Function to find the median in the movies array
void CalcMedian(int *arr, int *number)
{
	//Assign variables to temp numbers from array
	int temp = ((*number+1)/2)-1;
	double temp2 = (arr[(*number/2)-1] + arr[*number/2]) / 2.0;

    //Calculate the middle number of the array
    if(*number % 2 != 0) //Number of elements is odd
		cout << "The median is " << arr[temp]<< endl;
    else  //Number of elements is even
    	cout << "The median is " << temp2 << endl;
}

//Function to calculate the Mode of the movies array
//If no mode is found, program will tell the user that
//Note that this function can only find one mode not
//multiple modes if there are more than one set
void CalcMode(int *array, int *size)
{
    //Declare variables
    int counter = 1;
    int max = 0;
    int mode = array[0];

    //For loop to determine if there are duplicate numbers in
    //the sorted array of numbers
    for (int elem = 0; elem < *size - 1; elem++)
    {
		//If statement checks if two numbers are equal
		//If they are, the counter is incremented
		if ( array[elem] == array[elem+1] )
       	{
        	counter++;
        	//If statement checks if counter is greater than
        	//the max number, if so, then the mode is array[elem]
        	if ( counter > max )
          	{
            	max = counter;
              	mode = array[elem];
          	}
       	}
	   	else
        	counter = 1; //Reset counter
    }

    //Print to console what mode is
    //If max is zero, there are no duplicate numbers
    if (max == 0)
    	cout <<"There is no mode!\n";
    else
		cout << "The mode is: " << mode << endl;
}

