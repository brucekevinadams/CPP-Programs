// Bruce Adams
// CS 2308
// 10-2-2016

#include <iostream>
using namespace std;

int binarySearch(int array[], int numElems, int value)
{
 
	int first = 0,				//first array element
		last = numElems -1,		//last array element
		middle,					//middle point of search
		position = -1;			//position of search value
		
	bool found = false;			//flag
	
while (!found && first <= last)
{
	middle = (first+last)/2;	//calculate mid-point
 
	if (value == array[middle])
	{
		found = true;	
  		position =  middle;
    }
 	else if (array[middle]> value)  //If value is in lower half
	 {
	 	last = middle - 1;
	}
	else 
	{
  		first = middle + 1;			//If value is in upper half	
    }
}	
return position;
}

int main()
{
 int luckyNumber[] = {13579,26791,26792,33445,55555,62483,77777,79422,85647,93121};
 int userValue;
 cout << "Enter this weeks winning five-digit number ";
 cin >> userValue;

 int result = binarySearch(luckyNumber,10,userValue);
 if(result >= 0)
 	{
		cout << "You won! " << luckyNumber[result];
		cout <<endl;
	}	
else
	{
 		cout << "You lost again";
 		cout <<endl;
	}
}
