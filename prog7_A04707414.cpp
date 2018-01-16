/****************************************************
Name: Bruce Adams

*****************************************************/

#include <cstdlib>
#include <stack>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

//Function to return counterpart of expression
char counterpart(char &ch)
{
    if(ch == ')')
        return '(';
    if(ch == ']')
        return '[';
    if(ch == '(')
        return ')';
    if(ch == '[')
        return ']';
}

//Function to check if expressions match
bool match(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

int main()
{
	//Initialize and create stack
	stack<char> Lstack;
	stack<char> Mstack;

	//Variable to hold line chars
    string line;

    //Ask user to enter file name
	cout << "Enter a text file name: ";

	//Get file name
    string fname;
    getline(cin, fname);

	//Open files
    ifstream fin(fname.c_str(), ios::in);
    ofstream fout("exp_output.dat", ios::out);

    //Check for successful opening of input file
    if(!fin)
    {
       cerr << "Error Opening File: " << fname << endl;
       cerr << "Make sure that the file exists!" << endl;
       exit(1);
    }

    //Check for successful opening of output file
    if(!fout)
    {
       cerr << "Error Opening output File exp_output.dat!" << endl;
       exit(1);
    }

    while( fin >> line)
    {
		//for loop to read each line from the input file
		for (int i =0; i<line.length(); i++)
		{
			//Check if character is open expression
			if (line[i] == '(' || line[i] == '[')
			{
				Lstack.push(line[i]);
			}
			//Check for closing expressions
			else if (line[i] == ')' || line[i] == ']')
			{
				//stack is empty or no match to character
				if (Lstack.empty() || !match(Lstack.top(), line[i]))
				{
					if (Mstack.empty())
						Lstack.push(line[i]);
					else
						Lstack.push(counterpart(line[i]));
				}
				//matching parentheses or brackets
				else if (counterpart(Lstack.top()) == line[i])
					Lstack.pop();
				else //mismatch of types of expressions
				{
					//Add ch to mismatch stack
					Mstack.push(counterpart(line[i]));
				}
			}
	  	}

		//write characters to output file
		int len = line.size();
		fout << line <<right<<setw(40-len);

	  	//Found more than six missing elements
	  	if (Lstack.size() > 6)
	  	{
	  		fout <<"      There are more than six elements missing";
	  		while (!Lstack.empty())
		  		Lstack.pop();
			while (!Mstack.empty())
				Mstack.pop();
		}
		//If stack is not empty, then find missing expressions
	  	else if (!Lstack.empty() || !Mstack.empty())
		{
			//Write to file
		  	fout <<setw(32-len)<< " === Missing ";
		  	while (!Mstack.empty())
		  	{
		  		fout << Mstack.top() << " ";
		  		Mstack.pop();
			}
		  	while (!Lstack.empty())
		  	{
				fout << counterpart(Lstack.top()) << " ";
				Lstack.pop();
		  	}
		}
		else
			fout << " === Valid expression";
		//Add line break to output file
		fout << endl;
	}

  	  //close files
	  fin.close();
	  fout.close();

      return 0;
}
