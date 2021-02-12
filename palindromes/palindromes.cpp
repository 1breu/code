///@author   Andrés Breucop
///@file     palindromes.cpp
///@version  2021-02-11
///@note     This program determines if a given string input is a palindrome.
///          Program outputs a string with results.

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "linkedQueue.h"
#include "linkedStack.h"

int main(int argc, char *argv[])
{
    // ------------------------------
    //  Declarations and headers.

    const string RESPONSE[2] = {"' is not ", "' is "};  //array of strings

    linkedQueue<char> charQ;                //create a linked queue of chars
    linkedStack<char> charStack;            //create a linked stats of chars
    int     itemNum = 0;                    //counter used in algorithm
    bool    result = true;                  //stores result of comparison

    // ------------------------------
    //  Verify command line arguments.

    if (argc == 1)
    {
        cout << "Error, missing command line argument." << endl;
        exit(1);
    }

    if (argc != 2)
    {
        cout << "Error, too many command line arguments." << endl;
        exit(1);
    }

    string userInput(argv[1]);              //array of chars from user input

    // ------------------------------
    //  Read each character in userInput, and add to list if appropriate.

    for (unsigned int index = 0; index < userInput.size(); index++)
    {
        if (isalpha(userInput[index]))
        {
            charQ.enqueue(toupper(userInput[index]));
            charStack.push(toupper(userInput[index]));
            itemNum++;
        }
        else if (isdigit(userInput[index]))
        {
            charQ.enqueue(userInput[index]);
            charStack.push(userInput[index]);
            itemNum++;
        }
    }

    for (int index = 0; index < itemNum; index++)
    {
        if (charQ.dequeue() != charStack.pop())
        {
            result = false;
        }
    }

    cout << "\nThe string: '" << userInput << RESPONSE[result]
    << "a palindrome.\n" << endl;

    return 0;
}
