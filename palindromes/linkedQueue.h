///@author   Andrés Breucop
///@file     linkedQueue.h
///@version  2021-02-11
///@note     This file defines a template for the linkedQueue class, a queue
///          data structure made using linked lists.

#ifndef linkedQueue_h
#define linkedQueue_h

template <class myType>
struct queueNodeType
{
    myType info;                            //data to store in node
    queueNodeType<myType> *link;            //a pointer to this node
};

template <class myType>
class linkedQueue
{
private:
    queueNodeType<myType> *queueFront;      //pointer to first item in queue
    queueNodeType<myType> *queueRear;       //pointer to last item in queue
    int count;                              //the number of items in queue

public:
    linkedQueue();
    ~linkedQueue();
    bool isEmptyQueue() const;
    void enqueue(const myType& newItem);
    myType dequeue();
    void printQueue();
};

//---------------------------------------------------------------------------
//                  F U N C T I O N     D E F I N I T I O N S
//---------------------------------------------------------------------------


/// --------------------------------------------------------------------
/// @brief      Default constructor. Initializes variables.
/// --------------------------------------------------------------------

template <class myType>
linkedQueue<myType>::linkedQueue()
{
    queueFront = nullptr;
    queueRear = nullptr;
    count = 0;
}

/// --------------------------------------------------------------------
/// @brief      Default destructor. Deletes dynamically allocated memory.
/// --------------------------------------------------------------------
template <class myType>
linkedQueue<myType>::~linkedQueue()
{
    queueNodeType<myType> *temp;                //pointer to traverse list

    while (queueRear != nullptr)
    {
        temp = queueRear;
        queueRear = queueRear->link;
        delete temp;
        count--;
    }

    queueFront = nullptr;
    queueRear = nullptr;
    count = 0;
}

/// --------------------------------------------------------------------
/// @brief      Determines if queue is empty.
///
/// @return     true if empty, false if items in queue
/// --------------------------------------------------------------------
template <class myType>
bool linkedQueue<myType>::isEmptyQueue() const
{
    return (queueFront == nullptr);
}

/// --------------------------------------------------------------------
/// @brief          Adds an item to the back of the qeueue.
///
/// @param  newItem The address in memory of the item to add to queue.
/// --------------------------------------------------------------------
template <class myType>
void linkedQueue<myType>::enqueue(const myType& newItem)
{
    queueNodeType<myType> *newNode;             //create a new pointer variable

    newNode = new queueNodeType<myType>;        //set new pointer to new node

    newNode->info = newItem;                    //store data in new node
    newNode->link = nullptr;                    //set this pointer to NULL

    if (queueFront == nullptr)                  //if queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else                                        //else add to back of queue
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }

    count++;                                    //increment count
}

/// --------------------------------------------------------------------
/// @brief   Removes the front item in the queue. Decrements count by 1.
///
/// @return  The data contained in the first item in queue.
/// --------------------------------------------------------------------
template <class myType>
myType linkedQueue<myType>::dequeue()
{
    queueNodeType<myType> *temp = nullptr;
    myType data = 0;

    if (!isEmptyQueue())
    {
        data = queueFront->info;
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
        count--;

        if (queueFront == nullptr)
        {
            queueRear = nullptr;
        }
    }

    return data;
}


/// --------------------------------------------------------------------
/// @brief   Prints out items queue.
/// --------------------------------------------------------------------
template <class myType>
void linkedQueue<myType>::printQueue()
{
    queueNodeType<myType> *temp = queueRear;

    while (temp != nullptr)
    {
        std::cout << temp->info;
        temp = temp->link;
    }
}

#endif /* linkedQueue_h */
