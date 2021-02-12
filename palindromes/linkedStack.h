///@author   Andrés Breucop
///@file     linkedStack.h
///@version  2021-02-11
///@note     This file defines a template for the linkedStack class, a stack
///          data structure made using linked lists.

#ifndef linkedStack_h
#define linkedStack_h

#include <iostream>

template <class myType>
struct nodeType
{
    myType item;                                //data to store in node
    nodeType<myType> *link;                     //a pointer to this node
};

template <class myType>
class linkedStack
{
private:
    nodeType<myType> *stackTop;                 //pointer to first item in stack
    int itemCount;                              //the number of items in queue

public:
    linkedStack();
    ~linkedStack();
    bool isEmpty() const;
    void push(const myType &newItem);
    myType pop();
};

//------------------------------------------------------------------------------
//                  F U N C T I O N     D E F I N I T I O N S
//------------------------------------------------------------------------------


/// ----------------------------------------------------------------------------
/// @brief      Default constructor. Initializes variables.
/// ----------------------------------------------------------------------------
template <class myType>
linkedStack<myType>::linkedStack()
{
    stackTop = nullptr;
    itemCount = 0;
}

/// ----------------------------------------------------------------------------
/// @brief      Default destructor. Deletes dynamically allocated memory.
/// ----------------------------------------------------------------------------
template <class myType>
linkedStack<myType>::~linkedStack()
{
    nodeType<myType> *temp;                     //pointer to traverse list

    while (stackTop != nullptr)
    {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
        itemCount--;
    }
    itemCount = 0;
}

/// ----------------------------------------------------------------------------
/// @brief      Determines if stack is empty.
///
/// @return     true if empty, false if items in stack
/// ----------------------------------------------------------------------------
template <class myType>
bool linkedStack<myType>::isEmpty() const
{
     return (stackTop == nullptr);
}

/// ----------------------------------------------------------------------------
/// @brief          Adds an item to the stack.
///
/// @param  newItem The address in memory of the item to add to stack.
/// ----------------------------------------------------------------------------
template <class myType>
void linkedStack<myType>::push(const myType &newItem)
{
    nodeType<myType> *newNode;          //pointer to the new node

    newNode = new nodeType<myType>;     //create the new node

    newNode->item = newItem;            //store the new item in the node
    newNode->link = stackTop;           //insert newNode before first
    stackTop = newNode;
    itemCount++;                        //increment count
}

/// ----------------------------------------------------------------------------
/// @brief   Removes the first item in the item. Decrements count by 1.
///
/// @return  The data contained in the first item.
/// ----------------------------------------------------------------------------
template <class myType>
myType linkedStack<myType>::pop()
{
    nodeType<myType> *temp;             //pointer to the new node
    myType data;                        //return variable

    if (stackTop != nullptr)
    {
        data = stackTop->item;
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
        itemCount--;
        return data;
    }
    else
    {
        std::cout << "Cannot remove from empty stack." << std::endl;
        return 0;
    }
}

#endif /* linkedStack_h */
