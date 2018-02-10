/****************************************************
Name: Bruce Adams
Date: November 14, 2016
CS 2308-005
Homework 9
*****************************************************/

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

//Struct to hold stack data
struct node
{
    char data;
    node *next;
}

//Assign stack variables
*head = NULL,
*topStack = NULL,
*temp = NULL,
*ptr;

//Push function
void push(char var)
{
    head = new node;
    head->data = var;
    head->next = NULL;

    if (topStack == NULL)
    {
        topStack = head;
    }
    else
    {
        temp = topStack;
        topStack = head;
        head->next = temp;
    }
}

//Pop function
char pop()
{
    if (topStack == NULL)
    {
        cout<<"Error";
    }
    else
    {
        ptr = topStack;
        topStack = topStack->next;
        return(ptr->data);
        delete ptr;
    }
}

//Main driver function
int main()
{
    //Define variables and char array
    int i;
    char arr[50], a, b, c;

    cout << "Enter an expression:\n";
    cin >> arr;

    for (i = 0; i < strlen(arr); i++)
    {
        if ((arr[i] == '(') || (arr[i] == '{') || (arr[i] == '['))
        {
                push(arr[i]);
        }
        else
        {
            //Switch case to detect parentheses, brackets, and braces
            switch(arr[i])
            {
            case ')':
                a = pop();
                if ((a == '{') || (a == '['))
                {
                    cout<<"Invalid expression!";
                }
                break;
            case '}':
                b = pop();
                if ((b == '[') || (b == '('))
                {
                    cout<<"Invalid expression!";
                }
                break;
            case ']':
                c = pop();
                if ((c == '{') || (c == '('))
                {
                    cout<<"Invalid expression!";
                }
                break;
            }
        }
    }

    //If topStack is empty, then expression is balanced
    if (topStack == NULL)
        cout<<"Balanced expression!";
    else
        cout<<"Expression is not balanced!";
}
