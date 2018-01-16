/*************************************************************
Authors: Bruce Adams

Program Description: Create a linked list that builds a list of
19 random integer numbers that are between 10 and 20.
The program then manipulates the list in various ways.
**************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Class for Linked List named numberList
class numberList{

private:
    // Linked list is a struct of a value and a pointer
    // called next. The Linked List struct is called listNode
    // it is composed of nodes of pointers and integer values
    struct listNode
    {
        int value;
        listNode *next;
    };
    // Declare the head of the list as pointer
    listNode * head;

public:
    // Default constructor
    numberList();
    // Overloaded constructor
    numberList(const numberList & src);
    // Destructor
    ~numberList();

    // Function prototypes, all are public
    void appendNode(int);
    void insertNode(int);
    void insertByPosition(int, int);
    void deleteNode(int);
    void searchList(int);
    void deleteByPosition(int);
    void displayList();
    void shiftNode();
    void displayReverse();
    void splitList();
    void removeDuplicates();
    void searchNum(int);
};

// Main driver
int main()
{
    // Variable for console input
    char userInput;

    // Instance of class
    numberList listClass;

    // Used in order to get proper randomization
    srand(time(0));

    // Intro console welcome
    cout <<"Welcome to Bruce and Jesse's Linked List Manipulation Program."<<endl<<endl;

    // Main do-while loop for program
    do
    {
        // Loop loads 19 random values into the linked list
        for(int i =0; i< 19; i++)
        {
            int num = rand()%(21-10) +10;
            listClass.insertNode(num);
        }

        // Display sorted list of 19 random integers
        cout <<"A. A sorted Main list of 19 random integers that "<<endl;
        cout <<"are between 10 and 20 are as follows:"<<endl;
        listClass.displayList();
        cout<<endl;
        // Insert -100 into LL
        cout<<"B. Main list after inserting new number -100 at the beginning: "<<endl;
        listClass.insertByPosition(-100,0);
        listClass.displayList();
        cout<<endl;
        // Insert 15 into third position of LL
        cout<<"C. Main list after inserting new number 15 at the third location: "<<endl;
        listClass.insertByPosition(15, 2);
        listClass.displayList();
        cout<<endl;
        // Append 1000 to LL
        cout<<"D. Main list after appending new number 1000: "<<endl;
        listClass.appendNode(1000);
        listClass.displayList();
        cout<<endl;
        // Delete 5 from LL, or state that that 5 is not in LL
        cout<<"E. Main list after removing number 5: "<<endl;
        listClass.deleteNode(5);
        listClass.displayList();
        cout<<endl;
        // Delete second element of LL
        cout<<"F. Main list after removing second element: "<<endl;
        listClass.deleteByPosition(1);
        listClass.displayList();
        cout<<endl;
        // Shifts every element in LL one to the right
        cout<<"G. Main list after rotating the list one position to the right: "<<endl;
        listClass.shiftNode();
        listClass.displayList();
        cout<<endl;
        // Searches the LL for the 17th element
        cout<<"H. Searching the main list for item number 17: "<<endl;
        listClass.searchList(17);
        listClass.displayList();
        cout<<endl;
        // Displays the LL backwards
        cout<<"I. Displaying the main list backwards: "<<endl;
        listClass.displayReverse();
        cout<<endl;
        // Splits the LL into 2 others, with half of the elements in each
        cout<<"J. Splitting the list into 2 sub lists(sub_List_1 and sub_List_2)."<<endl;
        cout <<"Main list:"<<endl;
        listClass.displayList();
        cout <<endl;
        listClass.splitList();
        cout<<endl;
        // Remove duplicates
        cout<<"K. Main list after duplicates removed from the list. "<<endl;
        listClass.removeDuplicates();
        listClass.displayList();
        cout<<endl;
        cout<<"L. Main list after being deleted. "<<endl;
        listClass.~numberList();
        listClass.displayList();
        cout<<endl;
        // Searches the list for number 35
        cout<<"X. Searching the main list for number 35: "<<endl;
        listClass.searchNum(35);
        listClass.displayList();
        cout<<endl;

        // Output to console for user to continue or not
        cout <<"\nWould you like to re-run the program again?\n";
        cout <<"Enter Y or N --->  ";
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

    // Signature output to console
    cout <<"This LL program was implemented by Bruce Adams"<<endl;
    cout <<"March - 2017"<<endl;

    return 0;
}

// Default Constructor
numberList::numberList()
{
   head = NULL;
}

// Function for Deconstructor
numberList::~numberList() {

    listNode* current = head;
    while( current != 0 ) {
        listNode* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}

// Function to append nodes
void numberList::appendNode(int num)
{
 listNode * newNode;

 newNode = new listNode;
 newNode->value = num;
 newNode->next = NULL;

 if(!head)
    head= newNode;
 else{
    listNode * nodePtr;
    nodePtr = head;

    while(nodePtr->next)
        nodePtr=nodePtr->next;

    nodePtr->next = newNode;
 }
}

// Function to display the linked list
void numberList::displayList()
{
    listNode * nodePtr;

    nodePtr = head;

    // Output to console if empty list
    if (head == NULL)
        cout <<"Empty list"<<endl;

    while(nodePtr)
    {
        cout<<nodePtr->value<<" ";

        nodePtr= nodePtr->next;
    }
cout<<endl;
}

// Function to insert a node into the linked list
// Note that this function sorts the list
void numberList::insertNode(int num)
{

    listNode * newNode;
    listNode * nodePtr;
    listNode * previousNode;

    newNode = new listNode;
    newNode->value = num;

    if(!head){
        head = newNode;
        newNode->next = NULL;
    }
    else{
        nodePtr = head;
        previousNode = NULL;

    while(nodePtr && nodePtr->value< num){
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }
    if(previousNode== NULL){
        head = newNode;
        newNode->next= nodePtr;
    }
    else{
        previousNode->next = newNode;
        newNode->next= nodePtr;
    }
  }
}

// Function to delete a node from the linked list
void numberList::deleteNode(int num)
{
 if(!head)
    return;

 listNode * nodePtr;
 if(head->value == num){
    nodePtr = head;
    head = nodePtr->next;
    delete nodePtr;
 }
 else{
    listNode * previousNode;
    nodePtr = head;

    while(nodePtr && nodePtr->value != num){
        previousNode = nodePtr;
        nodePtr= nodePtr->next;
    }
    if(nodePtr){
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
    else
        cout <<num <<" does not exist in list!"<<endl;
 }
}

// This function will insert an integer into the linked list
// at a specified point in the list
void numberList::insertByPosition(int num, int pos)
{
    // Declare all pointer nodes
    listNode *newNode;
    listNode *nodePtr;
    listNode *previousNode = NULL;

    // Create listNode and head pointer
    newNode = new listNode;
    newNode -> value = num;
    nodePtr = head;
    previousNode = NULL;

    // Loop to determine the position in the list
    for(int i = 0; i < pos; ++i) {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    // Check for a previousNode
    // If so, point the next of the previous Node to the new Node
    if (previousNode) {
        previousNode->next = newNode;
        newNode->next = nodePtr; // point the new node to the next node
    }
    // If there is no previous node place head at newNode
    else {
        head = newNode;
        newNode->next = nodePtr;
    }
}

// This function will delete a specific node by position
// where it is located in the linked list
void numberList::deleteByPosition(int pos)
{
    listNode *p = head;
    for(int i=0; i<pos-1 && p!=NULL; i++)
    {
        p = p->next;
    }
    // Check if list is empty
    if(p!=NULL) {
        if( p->next!=NULL) {
            listNode *todel = p->next;
            p->next = p->next->next;
            delete todel;
      }
      else {
        delete p; //If pos = 0 and it is the last element then delete it
      }
    }
}

// This function searches for a specific number in the LL
void numberList::searchList(int num)
{
int position =0;

listNode * nodePtr;
nodePtr = new listNode;

nodePtr = head;

while(nodePtr)
{
    nodePtr=nodePtr->next;
    position++;

    if(position == num)
        cout<<nodePtr->value<<" is at position "<<num<<endl;
}
  if(position<num)
    cout<<"Number at position "<< num<<" not found"<<endl;
}

// This function shifts all numbers to the right by one position
void numberList::shiftNode()
{
    if(!head)
        return;

    listNode * newNode;
    newNode = new listNode;

    listNode * previousNode = NULL;

    listNode * nodePtr;
    nodePtr = head;

    newNode->value= head->value;

    while(nodePtr->next)
    {
        previousNode=nodePtr;
        nodePtr=nodePtr->next;
    }

    previousNode->next=nodePtr->next;
    delete nodePtr;

    head->value=nodePtr->value;
    nodePtr = head;

    previousNode=nodePtr;
    nodePtr=nodePtr->next;

    previousNode->next=newNode;
    newNode->next=nodePtr;
}

// This function reverses the LL
void numberList::displayReverse()
{
    listNode * lastNode = NULL;
    listNode * nodePtr;

    while(lastNode != head)
    {
        nodePtr = head;
        while(nodePtr->next!= lastNode)
            nodePtr = nodePtr->next;

        cout<<nodePtr->value<<" ";
        lastNode=nodePtr;
    }
        cout<<endl;
    }

// This function splits the list into two sub lists
void numberList::splitList()
{
    listNode * sub_List_1 ;
    listNode * sub_List_2;
    listNode * nodePtr;
    nodePtr = new listNode;
    sub_List_1 = new listNode;
    sub_List_2 = new listNode;

    nodePtr = head;

    cout<<"sub_List_1: "<<endl;

    // Created and Display sub list 1 first 10 items
    for(int i=0; i< 10; i++)
    {
       sub_List_1->value = nodePtr->value;
       cout<<sub_List_1->value<<" ";
       nodePtr= nodePtr->next;
    }
    cout<<endl<<endl;

    // Display sub list 2
    cout<<"sub_List_2: "<<endl;
    while(nodePtr)
    {
        sub_List_2->value = nodePtr->value;
        cout<<sub_List_2->value<<" ";
        nodePtr= nodePtr->next;
    }
    cout<<endl<<endl;

    // Reset to head
    sub_List_1 = head;
    cout <<"Union of sub_list_1 and sub_list_2"<<endl;

    // Union of two sub lists
    while(sub_List_1)
    {
        cout<<sub_List_1->value<<" ";
        sub_List_1 = sub_List_1->next;
    }

    // Display intersection of two sub lists
    cout<<"\n\nIntersection of both sub-lists: "<<endl;

    // Find intersection
    while (sub_List_1 != NULL && sub_List_2 != NULL)
    {
       if (sub_List_1->value == sub_List_2->value)
       {
            cout<<sub_List_1->value<<" ";
            sub_List_1 = sub_List_1->next;
            sub_List_2 = sub_List_2->next;
       }

       nodePtr = nodePtr->next;
    }

    delete sub_List_1;
    delete sub_List_2;
}

// This function removes duplicates from the list
void numberList::removeDuplicates()
{
    // Create pointers to traverse list
    struct listNode *ptr1, *ptr2, *dup;
    ptr1 = head;

    // Pick elements one by one
    while(ptr1 != NULL && ptr1->next != NULL)
    {
     ptr2 = ptr1;

     // Compare the picked element with rest of the elements
     while(ptr2->next != NULL)
     {
       // If duplicate then delete it
       if(ptr1->value == ptr2->next->value)
       {
          // Sequence of steps is important here
          dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          free(dup);
       }
       else // Tricky but must be done
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
    }
}

// This function searches for a specific number in the list
void numberList::searchNum(int num)
{
    // Create pointer to traverse list
    struct listNode* current = head;

    // Create pointer to store the next pointer
    struct listNode* next;

    // If list empty, output to console that list
    // is empty, and return to main
    if (current == NULL)
    {
        //cout <<"List is empty!"<<endl;
        return;
    }

    // Search the list until the end
    while (current->next != NULL)
    {
        if (current->value == num)
        {
            cout <<num<< " number FOUND in list!"<<endl;
            return;
        }
        current = current->next;
    }
    // If number not found, display message to console
    cout <<num<<" number NOT found in list!"<<endl;
}

