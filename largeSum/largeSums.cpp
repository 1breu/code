///@author      Andrés Breucop
///@file        largeSums.cpp
///@version     2021-02-11
///@brief       This program calculates the sum of two numbers by using a linked
///             list object.

#include <iostream>
#include <string>
#include "linkedList.h"
#include "unorderedLinkedList.h"

void readNum (string& list1, string& list2, unorderedLinkedList<int>& num1,
              unorderedLinkedList<int>& num2);
void addNum (unorderedLinkedList<int>& num1, unorderedLinkedList<int>& num2,
             unorderedLinkedList<int>& num3);

using namespace std;

int main() {

    string op1;                     //variable to hold user input
    string op2;                     //variable to hold user input

    unorderedLinkedList<int> list1; //linked list to store digits from op1
    unorderedLinkedList<int> list2; //linked list to store digits from op2
    unorderedLinkedList<int> result; //linked list to store sum

    cout << "Enter first number:" << endl;
    cin >> op1;

    cout << "\nEnter second number:" << endl;
    cin >> op2;

    readNum(op1, op2, list1, list2);

    addNum(list1, list2, result);

    cout << "\nResult of sum:" << endl;
    result.print();
    cout << endl;

    return 0;
}

void readNum (string& list1, string& list2, unorderedLinkedList<int>& num1,
              unorderedLinkedList<int>& num2)
{
    for (size_t index = 0; index < list1.length(); index++)
    {
        int digit = list1[index] - '0';  //holds int value of digits in list1

        num1.insertFirst(digit);
    }

    for (size_t index = 0; index < list2.length(); index++)
    {
        int digit = list2[index] - '0'; //holds int value of digits in list2

        num2.insertFirst(digit);
    }

}

void addNum (unorderedLinkedList<int>& num1, unorderedLinkedList<int>& num2,
             unorderedLinkedList<int>& num3)
{
    int carry = 0;

    linkedListIterator<int> it1 = num1.begin();
    linkedListIterator<int> it2 = num2.begin();

    for (; it1 != num1.end() && it2 != num2.end(); ++it1, ++it2)
    {
        int result = *it1 + *it2 + carry;

        if (result <= 9)
        {
            num3.insertFirst(result);
            carry = 0;
        }
        else
        {
            int digit = result%10;
            carry = result/10;
            num3.insertFirst(digit);
        }

    }

    for (; it1 != num1.end(); ++it1)
    {
        int result = *it1 + carry;

        if (result <= 9)
        {
            num3.insertFirst(result);
            carry = 0;
        }
        else
        {
            int digit = result%10;
            carry = result/10;
            num3.insertFirst(digit);
        }

    }

    for (; it2 != num2.end(); ++it2)
    {
        int result = *it2 + carry;

        if (result <= 9)
        {
            num3.insertFirst(result);
            carry = 0;
        }
        else
        {
            int digit = result%10;
            carry = result/10;
            num3.insertFirst(digit);
        }

    }

    if (carry > 0)
    {
        num3.insertFirst(carry);
    }
}
