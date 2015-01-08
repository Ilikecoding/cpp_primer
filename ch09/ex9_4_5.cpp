/*--------------------------------------------------------------------
ex9_4:
Write a function that takes a pair of iterators to a vector<int> 
and an int value. Look for that value in the range and return a 
bool indicating whether it was found.

ex9_5:
Rewrite the previous program to return an iterator to the requested
element. Note that the program must handle the case where the 
element is not found.
--------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

/* ex9_4 */
bool find(const vector<int>::iterator &first, const vector<int>::iterator &last, int val);

/* ex9_5 */
vector<int>::iterator find2(const vector<int>::iterator &first, const vector<int>::iterator &last, int val);


int main(int argc, char const *argv[])
{
	vector<int> ivec = {2, 4, 10, 6};
	cout << find(ivec.begin(), ivec.end(), 10) << endl;
	return 0;
}

bool find(const vector<int>::iterator &first, const vector<int>::iterator &last, int val)
{
	for(auto it = first; it != last; ++it)
	{
		if(*it == val)
		{
			return true;
		}
	}

    return false;
}

vector<int>::iterator find2(const vector<int>::iterator &first, const vector<int>::iterator &last, int val)
{
	for(auto it = first; it != last; ++it)
	{
		if(*it == val)
		{
			return it;
		}
	}

	return last;
}