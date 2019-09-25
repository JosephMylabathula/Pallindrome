/*
 * Stack.h
 *
 *  Created on: Apr 26, 2018
 *      Author: Joseph Mylabathula and Gaoussou Diallo
 */

#ifndef Stack_H_
#define Stack_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;

template <class stackdata>
class Stack
{
    public:
        /**constructors and destructors*/

        Stack();

        //initializes an empty stack
        //postcondition: an empty stack

        Stack(const Stack &S);
        //initializes this stack to have same elements as S
        //postcondition: a copy of stack


        ~Stack();
        //frees memory allocated to the stack
        //postcondition: memory for stack has been freed

        /**manipulation procedures*/

        void pop();
        //removes an element from the top of the stack
        //precondition: size != 0
        //postcondition: an element has been removed from the top of the stack

        void push(stackdata data);
        //adds an element to the top of the stack
        //postcondition: an element added to the top of the stack

        /**accessors*/


       bool operator==(const Stack &S);
       //returns whether this stack is equal to another stack S

       stackdata peek() const;
       //returns the element at the top of the stack
       //precondition: size != 0

       int getSize() const;
       //returns the size of the stack

       bool isEmpty() const;
       //returns whether the stack is empty


       /**additional operations*/

       void displayStack(ostream& out) const;
       //prints the elements in the stack each element separate by a blank space to stdout

    private:
       struct Node {
           stackdata data;
           Node* next;

           Node(stackdata ndata) {
                data = ndata;
                next = NULL;
          }
       };

       Node* top;
       int size;

};
template<class stackdata>
Stack <stackdata>:: Stack()
{
	top = NULL;
	//end = NULL;
	size = 0;
}


template<class stackdata>
Stack <stackdata> :: Stack(const Stack &S)
{
	if(S.top == NULL)
	{
		top=NULL;
	}
	else
	{
		top= new Node(S.top -> data);
		Node *temp = S.top;
		Node *Gtemp = top;

		while(temp->next != NULL)
		{
			temp = temp->next;
			Gtemp->next = new Node(temp->data);
			Gtemp = Gtemp->next;
		}
		end = Gtemp;
	}
	size = S.size;
}


template<class stackdata>
Stack <stackdata>:: ~Stack()
{
	 	Node* b = top;
	    Node* a = NULL; 				// a stands for "after" (i.e. after b)
	    while (b != NULL)
	    {
	        a = b->next;			    // move a to node after b
	        delete b; 					// remove b (you know it is not NULL from if)
	        b = a; 						// b "catches up" with a (both point to same place in list)
	    }
}


template<class stackdata>
void Stack <stackdata>:: push(stackdata data)
{
	 	Node* N = new Node(data);
	    if (size == 0)
	    {
	        top = N;
	        N->next = NULL;
	    }
	    else
	    {
	    	N->next = top;
	    	top = N;
	    }

	    size++;
}

template<class stackdata>
void Stack <stackdata>:: pop()
{
	{
		assert(!isEmpty());
		if(getSize()==1)
		{
			delete top;
			top = NULL;
		}

		else
		{
			Node *temp = top;
			top = top->next;
			delete temp;
		}

		size--;
	}
}

template<class stackdata>
stackdata Stack<stackdata>:: peek() const
{
	assert(!isEmpty());
	return top->data;
}

template<class stackdata>
int Stack<stackdata>::getSize()const
{
	return size;
}

template<class stackdata>
void Stack<stackdata> ::displayStack(ostream& out) const
{
	 Node* temp = top; 								// create a temporary iterator
	    while (temp != NULL)
	    {
	    	out << temp->data;						// print the data at the temp
	    	temp = temp->next;
	    	cout << endl;
	    }
	    out << endl;				   				// Create Space for the next output
}

template<class stackdata>
bool Stack<stackdata> :: isEmpty() const
{
	if(size ==0)
		return true;
	else
		return false;
}

template<class stackdata>
bool Stack<stackdata> :: operator==(const Stack &S)
{
	if(size != S.size)
		        return false;
		    Node* temp1 = top;
		    Node* temp2 = S.top;
		    while(temp1 != NULL)
		    {
		        if(temp1->data != temp2->data)
		            return false;
		        temp1 = temp1->next;
		        temp2 = temp2->next;
		    }
		    return true;
}

#endif /* Stack_H_ */
