/*************************************************************
Authors: Bruce Adams

Program Description: The program creates an integer array of size 30
and then assigns -1 to each location. Half of the array is then filled
with random numbers from 100 to 500. Linear probing is used for
collisions. A menu gives the user options to 1) display the array,
2) search for a number, 3) insert a new number, 4) delete a number
from the array, and 5) end the program
**************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <assert.h>


using namespace std;


// Function prototypes
bool validateInt(int);
int randomNum();

// Table size declaration
const int TABLE_SIZE = 30;

// Class definition for key value pairing of hashes
class HashEntry {
private:
      int key;
      int value;

public:
    HashEntry(int key, int value) {
        this->key = key;
        this->value = value;
    }

    int getKey() {
        return key;
    }

    int getValue() {
        return value;
    }
};



// Class HashMap Definition
class HashMap {

private:
    HashEntry **table;
    int hashed = 0;
    int probes = 0;

public:
    // Constructor
    HashMap() {
        table = new HashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
              table[i] = NULL;
    }

    // Function returns key value
    int get(int key ) {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;

        if (table[hash] == NULL)
              return -1;
        else
              return table[hash]->getValue();
    }

    //Function creates key value pair
    void put(int key, int value) {
        int hash = (key % TABLE_SIZE);
        if (table[hash] != NULL)
            hashed += 1;

        // Linear probing while loop
        while (table[hash] != NULL && table[hash]->getKey() != key)
        {
            probes++;
            hash = (hash + 1) % TABLE_SIZE;
        }

        if (table[hash] != NULL)
              delete table[hash];
        table[hash] = new HashEntry(key, value);
    }

    // Increases probes by 1
    void setProbe() {
        probes++;
    }

    // Returns number of hashes
    int getHash() {
        return hashed;
      }

    // Returns number of probes
    int getProbe() {
        return probes;
      }

    // Function displays the hash array
    void display() {
        for (int i = 0; i < TABLE_SIZE/2; i++)
            cout <<table[i]->getValue()<<" ";
        cout<<endl<<endl;
        for (int i = 15; i < TABLE_SIZE; i++)
            cout <<table[i]->getValue()<<" ";
        cout <<endl;
    }

    // Destructor
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
              if (table[i] != NULL)
                    delete table[i];
        delete[] table;
    }
};


//**************************************************
// Main function                                   *
// This function drives the program.               *
//**************************************************
int main()
{
    // Variables
    int choice;
    int arrNum, insertNum, deleteNum;
    bool valid = false;
    bool found;
    int value;
    int count = 0;
    srand(time(NULL));

    // Create Hash Table Array
    HashMap hArr;

    // Fill with -1 for each element
    for (int i=0; i<TABLE_SIZE; i++)
        hArr.put(i, -1);

    // Fill half array with random numbers
     for (int i=0; i<TABLE_SIZE; i++)
     {
         int val = randomNum();
         if (i%2==0) //Only add to even i
         hArr.put(i, val);
     }


    // Output to console the program instructions
    cout <<"Welcome to Program Assignment 7 - Hashes."<<endl<<endl;

    // Output to console hash array data
    cout <<"HASH Table   "<<endl;
    cout <<"-------------------------------------------------------"<<endl;
    hArr.display();
    cout<<endl<<endl;

    // Main do while loop
    do {
        try {
            cout <<endl;
            cout <<"1. Display the array\n";
            cout <<"2. Search for a number (between 100-500) in the array\n";
            cout <<"3. Insert a number (between 100-500) into the array\n";
            cout <<"4. Delete a number (between 100-500) from array.\n";
            cout <<"5. Exit The Program\n\n";

            // Ask user to enter their choice
            cout <<"Enter your choice ---->   ";
            cin >> choice;
            cout <<endl;

            // Error checking for input validation
            if (!(cin) || (choice < 1 || choice > 5) )
               throw choice;

            // Main switch loop for program
            switch (choice) {

                // Display hash array
                case 1:
                    cout <<"Hash Table Array Displayed : \n";
                        cout <<"-------------------------------------------------------"<<endl;
                    // Display the array
                    hArr.display();
                    //
                    break;

                // Search hash array
                case 2:
                    while (!valid) {
                        cout <<"Enter number to SEARCH for (100-500) in the array : ";
                        cin >> arrNum;
                        valid = validateInt(arrNum);
                    }

                    for(int i = 0; i<TABLE_SIZE; i++)
                    {
                        value = hArr.get(i);
                        if (value == arrNum) //Values match
                        {
                            found = true;
                            break;
                        }
                        else
                            found = false;
                    }
                    if (found)
                        cout <<arrNum <<" FOUND in Hash Table\n";
                    else
                        cout <<arrNum <<" NOT found in Hash Table\n";
                    valid = false;
                    found = false;
                    break;

                // Input number to hash array
                case 3:
                    while (!valid) {
                        cout <<"Enter number (100-500) to INSERT into the array : ";
                        cin >> insertNum;
                        valid = validateInt(insertNum);
                    }

                    for(int i = 0; i<TABLE_SIZE; i++)
                    {
                        value = hArr.get(i);
                        if (value == -1) //key is not used
                        {
                            hArr.put(i, insertNum);
                            count++;
                            valid = false;
                            break;
                        }
                        else if (count>=15)
                        {
                            hArr.setProbe();
                            hArr.put(i, insertNum);
                            valid = false;
                            break;
                        }
                    }
                    valid = false;
                    break;

                // Delete number from hash array
                case 4:
                    while (!valid) {
                        cout <<"Enter number (100-500) to DELETE from the array : ";
                        cin >> deleteNum;
                        valid = validateInt(deleteNum);
                    }

                    for( int i =0; i<TABLE_SIZE; i++)
                    {
                        if(deleteNum == hArr.get(i))
                        {
                            hArr.put(i, -1);
                            valid = false;
                            break;
                        }
                    }
                    valid = false;
                    break;

                // Exit program
                case 5:
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
    } while (choice != 5);  // End of main do-while loop

    // Program is exiting
    cout <<"Program is exiting."<<endl;

    // Add statistics
    cout <<"Number of times hashed when adding element : "<<hArr.getHash()<<endl;
    cout <<"Number of linear probe collisions : "<<hArr.getProbe()<<endl;

    // Program terminated to output
    // Display to console the signature lines
    cout <<endl;
    cout <<"This APP was designed and implemented \n";
    cout <<"by Bruce Adams\n";
    cout <<"April, 2017\n\n";

    // Delete hArr array object
    hArr.~HashMap();

    return 0;
}   // End of main driver


// Function to validate input numbers for array
bool validateInt(int n)
{
    if(!cin || n<100 || n>500)
    {
        cout <<"Invalid choice! Enter a valid number."<<endl;
        cin.clear();    // Clear the buffer
        cin.ignore(256,'\n');
        return false;
    }
    else
        return true;
}

// Function to create random number from 100 to 500
int randomNum() {
    int num;
    num = rand()%401+100;
    return num;
}
