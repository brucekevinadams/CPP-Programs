#include <iostream>
using namespace std;

int main()
{
	string name;
	
	int funny = 7, serious = 15;
	funny = serious % 2;
	if (funny !=1)
	{
		funny = 0;
		serious =0;
	}
	else if (funny == 2)
	{
		funny = 10;
		serious = 10;
	}
	else 
	{
		funny = 1;
		serious = 1;
	}
	
	cout << funny << serious << endl;
	
	cout << 15 % 1 <<endl;
	
	cout << "The works of Wolfgang\ninclude the following";
cout << "\nThe Turkish March" << endl;
cout << "and Symphony No. 40 ";
cout << "in G minor." << endl;

cout << "What is your name? ";
cin  >> name ;
cout << "\nYour name is " << name;

return 0;
}
