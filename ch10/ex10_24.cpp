/*-------------------------------------------------------------------
Exercise 10.24: 
Use bind and check_size to find the first element in a vector of 
ints that has a value greater than the length of a specified
string value.
-------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

inline bool check_size(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

inline vector<int>::iterator 
find_first_greater(vector<int> &v, const string &s)
{
	return find_if(v.begin(), v.end(), bind(check_size, s, _1));
}

int main(int argc, char const *argv[])
{
	vector<int> ivec = {0, 1, 2, 3, 4, 5};
	string s("zyxh");
	cout << *find_first_greater(ivec, s) << endl;

	return 0;
}