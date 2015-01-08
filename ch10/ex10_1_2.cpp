/*-----------------------------------------------------------------------
ex10_1: 
The algorithm header defines a function named count that, like find, 
takes a pair of iterators and a value. count returns a count of how 
often that value appears. Read a sequence of ints into a vector and 
print the count of how many elements have a given value. 

ex10_2: 
Repeat the previous program, but read values into a list of strings.
-----------------------------------------------------------------------*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	//ex10_1
	vector<int> ivec = {2, 3, 1, 4, 2, 5};
	cout << count(ivec.begin(), ivec.end(), 2) << endl;

    //ex10_2
    vector<string> svec = {"zyx", "zyg", "abc", "zyh", "zyg"};
    cout << count(svec.begin(), svec.end(), "abc") << endl;

	return 0;
}