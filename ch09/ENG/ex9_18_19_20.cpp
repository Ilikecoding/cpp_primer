/*-----------------------------------------------------------
ex9_18:
Write a program to read a sequence of strings from the
standard input into a deque. Use iterators to write a 
loop to print the elements in the deque.

ex9_19:
Rewrite the program from the previous exercise to use a
list. List the changes you needed to make.

ex9_20:
Write a program to copy elements from a list<int> into
two deques. The even-valued elements should go into one 
deque and the odd ones into the other.
----------------------------------------------------------*/

#include <iostream>
#include <deque>
#include <list>
#include <string>
using namespace std;

void ex9_18();
void ex9_19();
void ex9_20();

int main(int argc, char const *argv[])
{
    ex9_18();
    ex9_19();
    ex9_20();

	return 0;
}

void ex9_18()
{
	deque<string> sdeq;
	string str;

	while(cin >> str)
	{
		sdeq.push_back(str);
	}

	for(auto i : sdeq)
	{
		cout << i << endl;
	}
}

void ex9_19()
{
	list<string> slst;
	string str;

	while(cin >> str)
	{
		slst.push_back(str);
	}

	for(auto i : slst)
	{
		cout << i << endl;
	}
}

void ex9_20()
{
	list<int> ilst {0, 1, 2, 3, 4};
	deque<int> dq1, dq2;

	for(auto it = ilst.begin(); it != ilst.end(); it++)
	{
		if(*it % 2 == 1)
		{
			dq1.push_back(*it);
		}
		else
		{
			dq2.push_back(*it);
		}
	}
}