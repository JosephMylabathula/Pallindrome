/*
 * Palindrome.cpp
 *
 *  Created on: Apr 29, 2018
 *      Author: Joseph Mylabathula and Gaoussou Diallo
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Queue.h"
#include "Stack.h"
using namespace std;

const string INFILE = "Palindrome.txt";
int main()
{
	ifstream fin;
	char ch;
	char line[40];
	string str;
	string strch;
	size_t found;
	fin.open(INFILE);

	Stack<string> L1;
	Queue<string> L2;

	while(fin)
		{
			getline(fin,str);
			cout << str << " ";

			// skip lines without sentences
			found = str.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			if(found == string::npos)
				continue;

			// copy string to char array
			strcpy(line, str.c_str());

			int i = 0;
			// Convert to lower case
			ch = tolower(line[i]);

			while(ch != '\0')					// If not end of line
			{
				if (ch >= 'a' && ch <= 'z')		// Lower case alphabets
				{
					strch = ch + '\0';			// Convert characters to string
					L1.push(strch);				// Push to Stack
					L2.enqueue(strch);			// Add to Queue
				}

				i++;
				ch = tolower(line[i]);			// Increment character
			}

			// Delete matching alphabets in Queue and Stack
			while(L1.getSize() != 0 && L2.getSize() != 0)
			{
				if(L1.peek() == L2.getFront())
				{
					L1.pop();
					L2.dequeue();
				}

				else							// If the Alphabets do not match, exit
					break;
			}

			if(L1.getSize() == 0 && L2.getSize() == 0)
				cout << "(Palindrome)" << endl << endl;
			else
			{
				cout << "(Not A Palindrome)" << endl << endl;

				// Clean the Stack and Queue
				while(L1.getSize() != 0 && L2.getSize() != 0)
				{
					L1.pop();
					L2.dequeue();
				}

			}
		}

	fin.close();
}


/*
 * A man, a plan, a canal, Panama. (Palindrome)

Do geese see God? (Palindrome)

Never odd. Even. (Not A Palindrome)

Never odd or even. (Palindrome)

Eye (Palindrome)

Ear (Not A Palindrome)

Able was I ere I saw Elba! (Palindrome)

Was it Eliot's toilet I saw? (Palindrome)

Race cars (Not A Palindrome)

 */

