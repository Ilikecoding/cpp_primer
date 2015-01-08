/*----------------------------------------------------------------------------------
Exercise 10.13: 
The library defines an algorithm named partition that takes a predicate and 
partitions the container so that values for which the C++ Primer, Fifth Edition
predicate is true appear in the first part and those for which the predicate is
false appear in the second part. The algorithm returns an iterator just past
the last element for which the predicate returned true. Write a function that
takes a string and returns a bool indicating whether the string has five
characters or more. Use that function to partition words. Print the elements
that have five or more characters.
----------------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool greater5(const string &s);

int main(int argc, char const *argv[])
{
	vector<string> v = {"abcde", "abc", "aaa", "abcdij", "abcd"};
	auto larger_end = partition(v.begin(), v.end(), greater5);

	for(auto it = v.begin(); it != larger_end; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}

bool greater5(const string &s)
{
	return s.size() >= 5;
}