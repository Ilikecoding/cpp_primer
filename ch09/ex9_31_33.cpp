/*---------------------------------------------------------
ex9_31:
The program on page 354 to remove even-valued elements
and duplicate odd ones will not work on a list or 
forward_list. Why? Revise the program so that it works 
on these types as well.

ex9_33:
In the final example in this section what would happen 
if we did not assign the result of insert to begin? 
Write a program that omits this assignment to see if 
your expectation was correct.
---------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;

void ex9_31_list();
void ex9_31_forward_list();
void ex9_33();

int main(int argc, char const *argv[])
{
	ex9_31_list();
	ex9_31_forward_list();
	ex9_33();
	return 0;
}

void ex9_31_list()
{
	list<int> ilst = {0, 1, 2, 3, 4};
	auto it = ilst.begin();

	while(it != ilst.end())
	{
		if(*it % 2)
		{
			it = ilst.insert(it, *it);
			++++it;
		}
		else
		{
			it = ilst.erase(it);
		}
	}

	for(auto i : ilst)
	{
		cout << i << " ";
	}
	cout << endl;
}

void ex9_31_forward_list()
{
	forward_list<int> flst = {0, 1, 2, 3};
	auto prev = flst.before_begin();
	auto curr = flst.begin();

	while(curr != flst.end())
	{
		if(*curr % 2)
		{
			curr = flst.insert_after(curr, *curr);
		    prev = curr;
			++curr;
		}
		else
		{
			curr = flst.erase_after(prev);
		}
	}

	for(auto i : flst)
	{
		cout << i << " ";
	}
	cout << endl;
}

void ex9_33()
{
	vector<int> ivec = {0, 1, 2, 3};
	auto begin = ivec.begin();
	while(begin != ivec.end())
	{
		++begin;
		begin = ivec.insert(begin, 42);
		++begin;
	}

	for(auto i : ivec)
	{
		cout << i << " ";
	}
	cout << endl;
}