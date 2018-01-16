//      Author:      Bruce Adams
//
//      This is a program that inputs from text files and stores
//      the data in a struct to be printed out in a specified format

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

const int SIZE = 6;                         //constant for size

struct SalesPersonRecord
{
    int SalesPersonID;                      //salesperson's ID
    double saleByQuarter[4];                //array for total sales per quarter
    double totalSale;                       //salesperson's yearly sales amount
};

struct Names
{
    int salesId;                               //salesperson's ID
    string firstName;                          //salesperson's first name
    string lastName;                           //salesperson's last name

};

void getData(SalesPersonRecord d[]);            //prototype function sales data
void sales(SalesPersonRecord d[]);              //prototype employee sales data
void empSalesData(SalesPersonRecord d[]);       //prototype employee total sales data
void printRep(SalesPersonRecord d[]);           //prototype print annual report
void name(Names e[]);                           //prototype to input employee names
void maxSales(SalesPersonRecord d[],Names e[]); //prototype to find max sale
void maxQuarter(SalesPersonRecord d[]);         //prototype max quarterly sales data

int main()
{
    //struct objects
    SalesPersonRecord d[SIZE];
    Names e[SIZE];

    //function to print report in specified format
    printRep(d);
    //function call to import sales data into struct
    getData(d);
    //function call to print sales data
    sales(d);
    //function call to get quarterly data
    empSalesData(d);
    //function call to get employee names
    name(e);
    //function call to print employee name with max sales amount for year
    maxSales(d,e);
    //function call to find max quarter amount for year
    maxQuarter(d);

    //final output to console of author
    cout <<"\n\n\nBruce Adams - CFO\n";
    cout <<"November - 30 - 2015\n";

	return 0;
}

void getData(SalesPersonRecord d[])
{
    //open sales.txt to read data
    ifstream input;
    input.open("sales.txt");

    //file validation
	if (!input)
    {
        cout << "ERROR - File failed to open." << endl;
        exit(0);
    }

    //nested for loops to input data into struct
    for (int i=0; i<SIZE; i++) {
        input >> d[i].SalesPersonID;
        for (int j=0; j <4; j++) {
            input >> d[i].saleByQuarter[j];
        }
    }
    //close the input file
    input.close();
}

void sales(SalesPersonRecord d[])
{
    //for loop to output data to console
    for (int i=0; i<SIZE; i++) {
        cout <<d[i].SalesPersonID<<setprecision(2)<<left<<fixed<<"\t";
        d[i].totalSale=0;
        for (int j=0; j<4; j++) {
           cout <<"\t"<<d[i].saleByQuarter[j]<<"\t";
           d[i].totalSale += d[i].saleByQuarter[j];
        }
        cout <<"      "<<d[i].totalSale;
        cout<<endl;
    }
}

void maxQuarter(SalesPersonRecord d[])
{
    //array for total quarterly sales
    double q[4];
    //variable to store quarter number
    int quarter = 1;

    //for loop to add up quarterly data
    for (int i=0; i<SIZE; i++)
    {
        q[0] += d[i].saleByQuarter[0];
        q[1] += d[i].saleByQuarter[1];
        q[2] += d[i].saleByQuarter[2];
        q[3] += d[i].saleByQuarter[3];
    }

    //variable for largest quarter amount
    double largest = q[0];

    //for loop to find highest quarter total
    for (int i=0; i<4; i++) {
        if (q[i] > largest )  {
            largest = q[i];
            quarter = i+1;
        }
    }
    cout <<"Max Sale by Quarter:\n\n";
    cout <<"Quarter = "<<quarter<<"         Amount = $"<<largest;
}

void printRep(SalesPersonRecord d[])
{
    cout<<"\t\t\t   Night Ya Night Prime Coffee\n";
    cout<<"\t\t----------- Annual Sales Report - 2013 -----------\n\n";
    cout<<"ID"<<"              "<<"QT1"<<"             "<<"QT2"<<"             "<<"QT3"<<"             "<<"QT4"<<"           "<<"Total\n";
    cout<<"_____________________________________________________________________________________\n";
}


void name(Names e[])
{
    //open empNames.txt to read data
    ifstream input;
    input.open("empNames.txt");

    //file validation
	if (!input)
    {
        cout << "ERROR - File failed to open." << endl;
        exit(0);
    }

    cout<<endl;
    //for loop to read ID, first name, last name from input file
    for (int i=0; i<SIZE; i++) {
        input >>e[i].salesId>>e[i].firstName>>e[i].lastName;
    }

    //close the input file
    input.close();
}

void maxSales(SalesPersonRecord d[], Names e[])
{
    string firstName;
    string lastName;
    int id;

    //need to add buffer line
    cout<<endl;

    //variable for largest sale amount
    double largest = d[0].totalSale;

    //for loop to find highest yearly total and associated ID
    for (int i=0; i<SIZE; i++) {
        if (d[i].totalSale > largest) {
            largest = d[i].totalSale;
            id = d[i].SalesPersonID;
        }
    }

    //for loop to pair associated ID with first and last name
    for (int i=0; i<SIZE; i++) {
        if (id == e[i].salesId) {
            firstName = e[i].firstName;
            lastName = e[i].lastName;
        }
    }

    //output data to console
    cout <<"Max Sale by Sales Person:\n\n";
    cout <<"Sales Person Name: "<<firstName<<"   "<<lastName<<endl;
    cout <<"Sales Person ID =  "<<id<<" ,      Amount = $"<<largest<<"\n\n";
}

void empSalesData(SalesPersonRecord d[])
{
    //variables for total quarterly sales
    double q[4];
    double qTotal = 0;

    //for loop to add up quarterly data
    for (int i=0; i<SIZE; i++)
    {
        q[0] += d[i].saleByQuarter[0];
        q[1] += d[i].saleByQuarter[1];
        q[2] += d[i].saleByQuarter[2];
        q[3] += d[i].saleByQuarter[3];
    }

    qTotal = q[0] + q[1] + q[2]+ q[3];

    cout<<"\n\nTotal\t";
    cout <<setprecision(2)<<left<<fixed;
    for (int j=0; j<4; j++) {
       cout <<"\t"<<q[j]<<"  ";
    }
    cout<<"     "<<qTotal;
    cout<<endl;
}
