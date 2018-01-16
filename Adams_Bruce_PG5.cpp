/*************************************************************
Author: Bruce Adams

Program Description: The program displays a menu on the console
allowing the user to enter elements of a stack and queue. The
program then displays whether the stack and queue have the same
number of elements and have the same matching group of symbols
(, ), {, }, [, ], <, >. The program terminates when the user
enters a 9.
**************************************************************/

#include <iostream>
#include <stdexcept>

using namespace std;

//**************************************************
// Create a template for dynamic stack class
//**************************************************
template < class T >
class DynStack
{
private:

    T *dynStackArr;         // Pointer to dynamic array
    int top;                // Index to top of stack

public:

    DynStack();             // Default Constructor
    ~DynStack();            // Destructor
    void push( T );         // Add to stack
    void pop();             // Remove from stack
    bool isEmpty() const;   // Boolean check for empty
    int stackSize();        // Returns size of stack
    void makeEmpty();       // Empties the stack
    void display();         // Displays the stack
    T getTop();             // Returns top value
    T getPtr(int);          // Return array PTR value
};

//**************************************************
// Constructor                                     *
// This function creates the dynamic array         *
//**************************************************
template < class T >
DynStack<T>::DynStack()
{
    dynStackArr = new T;
    top = -1;
}

//**************************************************
// Destructor                                      *
// This function deletes the dynamic array         *
//**************************************************
template < class T >
DynStack<T>::~DynStack()
{
    delete [] dynStackArr;
}

//****************************************************
// Member function getTop returns the index of top   *
//****************************************************
template < class T >
T DynStack<T>::getTop()
{
    return dynStackArr[top];
}

//************************************************
// Function returns the value at index(val)      *
// from the Stack dynamic array dynStackArr      *
//************************************************
template < class T >
T DynStack<T>::getPtr(int val)
{
    return dynStackArr[val];
}


//************************************************
// Member function push adds the value (argument)*
// onto the stack.                               *
//************************************************
template < class T >
void DynStack<T>::push( T val )
{
    top++;
    dynStackArr[top] = val;
}

//****************************************************
// Member function pop removes the value at the top  *
//****************************************************
template < class T >
void DynStack<T>::pop()
{
    if (isEmpty())
    {
        cout <<"The stack is empty.\n";
    }
    else
    {
        top--;
    }
}

//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************
template < class T >
bool DynStack<T>::isEmpty() const
{
    return (top == -1);
}

//****************************************************
// Member function makeEmpty empties the stack       *
//****************************************************
template < class T >
void DynStack<T>::makeEmpty()
{
    top = -1;
}

//****************************************************
// Template Class for displaying the stack           *
//****************************************************
template < class T >
void DynStack<T>::display()
{
    // Test to check if the stack is empty.
    if (isEmpty())
    {
      cout << "The stack is empty.\n";
    }
    else  // loop to display values
    {
        for (int i = 0; i < top; i++ ) {
            cout <<dynStackArr[i];
        }
    }
}

//****************************************************
// Template Class for computing the stack size       *
//****************************************************
template < class T >
int DynStack<T>::stackSize()
{
    // Test to check if the stack is empty.
    if (isEmpty())
    {
      cout << "The stack is empty.\n";
    }
    else  // loop to display values
    {
        return top;
    }
}

//**************************************************
// Create a template for dynamic Queue class
//**************************************************
template < class T >
class DynQueue
{
private:

    T *queArray;            // Pointer to dynamic queue array
    int queFront;           // Subscript to front of queue
    int queRear;            // Subscript to rear of queue
    int numItems;           // Number of items in the queue

public:

    DynQueue();             // Default Constructor
    ~DynQueue();            // Destructor
    void enqueue( T );      // Add to queue
    int dequeue();          // Remove from queue
    bool isEmpty() const;   // Boolean check for empty
    int queSize();          // Get size of the queue
    void makeEmpty();       // Empties the queue
    T getFront();           // Returns front value
    T getPtr(int);          // Return array PTR value
    void display();         // Displays the queue
};

//**************************************************
// Constructor                                     *
// This function creates the dynamic Queue array   *
//**************************************************
template < class T >
DynQueue<T>::DynQueue()
{
    queArray = new T;
    queFront = -1;
    queRear = -1;
    numItems = 0;
}

//**************************************************
// Destructor                                      *
// This function deletes the dynamic Queue array   *
//**************************************************
template < class T >
DynQueue<T>::~DynQueue()
{
    delete [] queArray;
}

//************************************************
// Member function returns the front index value *
// from the Queue                                *
//************************************************
template < class T >
T DynQueue<T>::getFront()
{
    return queArray[queFront];
}

//************************************************
// Member function returns the index value (val) *
// from the Queue dynamic pointer array queArray *
//************************************************
template < class T >
T DynQueue<T>::getPtr(int val)
{
    return queArray[val];
}

//************************************************
// Member function push adds the value (argument)*
// onto the Queue.                               *
//************************************************
template < class T >
void DynQueue<T>::enqueue( T val )
{
    if (queRear == numItems)
        queRear = 0;
    else
        queRear = queRear + 1;

    // Insert item to queue
    queArray[queRear] = val;
    // Update item count
    numItems++;
}

//************************************************
// Member function removes the value at front    *
// of the Queue.                                 *
//************************************************
template < class T >
int DynQueue<T>::dequeue()
{
    // Move front
    queFront = (queFront + 1) % numItems;

    // Update item count
    numItems--;

    // Retrieve front item
    return queArray[queFront];
}

//************************************************
// Member function returns true if Queue empty   *
//************************************************
template < class T >
bool DynQueue<T>::isEmpty() const
{
    return (numItems == 0);
}

//************************************************
// Member function makes the Queue empty         *
//************************************************
template < class T >
void DynQueue<T>::makeEmpty()
{
    queFront = -1;
    queRear = -1;
    numItems = 0;
}

//************************************************
// Member function shows Queue size              *
//************************************************
template < class T >
int DynQueue<T>::queSize()
{
    return numItems;
}

//****************************************************
// Template Class for displaying the Queue           *
//****************************************************
template < class T >
void DynQueue<T>::display()
{
    // Test to check if the Queue is empty.
    if (isEmpty())
    {
//      cout << "The queue is empty.\n";
    }
    else  // loop to display values
    {
        for (int i = 0; i < numItems; i++ ) {
            cout <<queArray[i];
        }
    }
}

//****************************************************
// Template Class for comparing stack and queue      *
//****************************************************
template <class T>
bool check(DynStack<T> stackPar, DynQueue<T> queuePar)
{
    bool equalFlag = false;

    if (stackPar.stackSize() != queuePar.queSize())
        return false;

    DynStack<T> stackReverse;

    for (int i = 0, initialSize = stackPar.stackSize(); i < initialSize; ++i)
        stackReverse.push(stackPar.getPtr(i));

    for (int i = 0; i <= stackReverse.stackSize(); ++i)
    {
        if (stackReverse.getPtr(i) == queuePar.getPtr(i))
            equalFlag = true;
        else
            return false;
    }
    return equalFlag;
}


//****************************************************
// Template Class for checking if braces are paired  *
//****************************************************
template <class T>
bool ArePair(T opening,T closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
    else if(opening == '<' && closing == '>') return true;
	return false;
}

//****************************************************
// Template Class for checking if braces are paired  *
//****************************************************
template <class T>
bool BracesBalanced(DynStack<T> s, DynQueue<T> q)
{
	DynStack<T>  Stemp;
	for(int i =0;i<s.stackSize();i++)
	{
		if(s.getPtr(i) == '(' || s.getPtr(i) == '{' || s.getPtr(i) == '[' || s.getPtr(i) == '<')
            Stemp.push(s.getPtr(i));
		else if(s.getPtr(i) == ')' || s.getPtr(i) == '}' || s.getPtr(i) == ']' || s.getPtr(i) == '>')
		{
			if(Stemp.isEmpty() || !ArePair(Stemp.getTop(),s.getPtr(i)))
                return false;
			else
               Stemp.pop();
		}
	}
	return Stemp.isEmpty() ? true:false;
}

//**************************************************
// Main function                                   *
// This function drives the program.               *
//**************************************************
int main()
{
    // Declare variable for user Input
    int choice;
    DynStack<char> s; // Create stack object
    DynQueue<char> q; // Create queue object

	cout <<"*** Welcome to our Stack / Queue Program ***\n\n";
	cout <<"The function of this program is to :\n\n";
	cout <<"    1-\t Validate that a stack and a\n";
	cout <<"    \t queue is identical.\n";
	cout <<"    \t Stacks / queues are the same if\n";
	cout <<"    \t they have the same number of elements, symbols,\n";
	cout <<"    \t and their elements and symbols at the\n";
	cout <<"    \t corresponding positions are the same.\n\n";
	cout <<"    2-\t The program also outputs whether the elements\n";
	cout <<"    \t have the same matching group symbols.\n\n";

    // Main do while loop
    do {
            try
            {
                // Variables for queue / stack comparisons
                bool equalItems = false;
                bool balanced = false;

                cout <<"Select from the following menu\n";
                cout <<"1.  Enter Stack / Queue Values.\n";
                cout <<"9.  Terminate the program.  ";
                cin >> choice;

                // Error checking for input validation
                if (!(cin) || (choice != 1))
                throw choice;

                // Start of switch-case
                switch (choice) {

                    case 1:
                        // Input the stack values
                        char stackVal;
                        cout <<"\nEnter Stack Values terminated by ;   ";
                        while (stackVal != ';') {
                            cin >>stackVal;
                            s.push(stackVal);
                        }
                        // Input the queue values
                        char queueVal;
                        cout <<"Enter Queue Values terminated by ;   ";
                        while (queueVal != ';') {
                            cin >>queueVal;
                            if (queueVal != ';')
                            q.enqueue(queueVal);
                        }

                        // Buffer line
                        cout <<endl;

                        // Check if stack and queue are
                        // totally identical calling check function
                        equalItems = check(s,q);

                        // If they are equal
                        if (equalItems)
                            cout <<"Stack and Queue are identical\n\n";
                        // If stack and queue are not identical
                        else
                            cout <<"Stack and Queue are not identical\n\n";

                        // Check if all braces are identical by calling function
                        balanced = BracesBalanced(s,q);

                        // If braces are identical
                        if (balanced)
                            cout <<"First Expression does have matching grouping symbols.\n";
                        else
                            cout <<"First Expression does not have matching grouping symbols.\n";

                        // Buffer lines
                        cout <<endl<<endl;

                        // Empty stack and queue objects
                        s.makeEmpty();
                        q.makeEmpty();
                        stackVal = 0;
                        queueVal = 0;

                        break; // Break out of case 1
                    default:
                        break;
                } // End of switch-case
            } // Validation catch for improper input on try
            catch (int choice) {
                cout << endl << endl;
                if (choice !=9)
                cout <<"Invalid Option"<<endl<<endl<<endl;
                cin.clear();    // Clear the buffer
                cin.ignore(256,'\n');
            }

    } while (choice != 9);  // End of main do-while loop

    cout <<"\n*** Program is terminated. Written by Bruce Adams ***\n";

    // Deallocate dynamic memory from stack and queue
    s.~DynStack();
    q.~DynQueue();

	return 0;
}
