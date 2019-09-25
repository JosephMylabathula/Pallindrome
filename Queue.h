/*
 * Queue.h
 *
 *  Created on: Apr 26, 2018
 *      Author: Joseph Mylabathula and Gaoussou Diallo
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cstddef>
#include <assert.h>
using namespace std;

template<class queuedata>
class Queue {
public:
    /**constructors and destructors*/

    Queue();
    //initializes an empty queue
    //post: an empty queue created with default values for all fields

    Queue(const Queue &Queue);
    //initializes queue to have same elements as another queue
    //post: a deep copy of queue

    ~Queue();
    //frees memory allocated to the queue
    //post: memory for queue has been freed

    /**manipulation procedures*/

    void dequeue();
    //removes an element from the front of the queue
    //pre: size!=0
    //post: an element removed from the front of the queue

    void enqueue(queuedata data);
    //adds an element to the end of the queue
    //post: an element added to the end of the queue

    /**accessors*/

    bool operator==(const Queue &Q);
    //returns whether this queue is equal to another queue

    queuedata getFront() const;
    //returns the element at the front of the queue
    //pre: size != 0

    int getSize() const;
    //returns the size of the queue

    bool isEmpty() const;
    //returns whether the queue is empty

    /**additional queue operations*/
    void displayQueue(ostream& out) const;
    //prints the elements in the queue separated by a blank space

private:
    struct Node {

        queuedata data;
        Node* next;
        Node(queuedata d) {
            next = NULL;
            data = d;
        }
    };

    Node* front;
    Node* end;
    int size;

};

template<class queuedata>
Queue <queuedata>:: Queue()
{
	front = NULL;
	end = NULL;
	size = 0;
}

template<class queuedata>
Queue <queuedata>:: Queue(const Queue &Q)
{
	if(Q.front == NULL)
	{
		front = end = NULL;
	}
	else
	{
		front = new Node(Q.front -> data);
		Node *temp = Q.front;
		Node *Gtemp = front;

		while(temp->next != NULL)
		{
			temp = temp->next;
			Gtemp->next = new Node(temp->data);
			Gtemp = Gtemp->next;
		}
		end = Gtemp;
	}
	size = Q.size;
}

template<class queuedata>
Queue <queuedata>:: ~Queue()
{
	 	Node* b = front;
	    Node* a = NULL; 				// a stands for "after" (i.e. after b)
	    while (b != NULL)
	    {
	        a = b->next;			    // move a to node after b
	        delete b; 					// remove b (you know it is not NULL from if)
	        b = a; 						// b "catches up" with a (both point to same place in list)
	    }
}

template<class queuedata>
void Queue <queuedata>:: enqueue(queuedata data)
{

    Node* N = new Node(data);
    if (size == 0)
    {
        front = N;
    }
    else
    {
    	end->next = N;
    }

    end = N;

    size++;
}

template<class queuedata>
void Queue <queuedata>:: dequeue()
{
	assert(!isEmpty());
	if(getSize()==1)
	{
		delete front;
		front = end = NULL;
	}

	else
	{
		Node *temp = front;
		front = front->next;
		delete temp;
	}

	size--;
}


template<class queuedata>
void Queue <queuedata> ::displayQueue(ostream& out) const
{
	 Node* temp = front; 							// create a temporary iterator
	    while (temp != NULL) {

	    	out << temp->data;						// print the data at the temp
	    	temp = temp->next;
	    	cout << endl;
	    }
	    out << endl;				   				// Create Space for the next output
}

template<class queuedata>
queuedata Queue <queuedata>:: getFront() const
{
	assert(!isEmpty());
	return front->data;
}


template<class queuedata>
int Queue <queuedata>:: getSize() const
{
	return size;
}

template<class queuedata>
bool Queue <queuedata>:: operator==(const Queue &Q)
{
	if(size != Q.size)
	        return false;
	    Node* temp1 = front;
	    Node* temp2 = Q.front;
	    while(temp1 != NULL)
	    {
	        if(temp1->data != temp2->data)
	            return false;
	        temp1 = temp1->next;
	        temp2 = temp2->next;
	    }
	    return true;
}


template<class queuedata>
bool Queue <queuedata>:: isEmpty() const
{
	if(size == 0)
		return true;

		else
			return false;

}


#endif /* QUEUE_H_ */

