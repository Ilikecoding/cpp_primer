/*-----------------------------------------------------------------------------
Exercise 11.16: Using a map iterator write an expression that assigns a
value to an element.

Exercise 11.17: Assuming c is a multiset of strings and v is a vector
of strings, explain the following calls. Indicate whether each call is legal:
(1) works:
copy(v.begin(), v.end(), inserter(c, c.end()));  
(2) doesn't work (push_back is not the member of multiset):
copy(v.begin(), v.end(), back_inserter(c));
(3) works:
copy(c.begin(), c.end(), inserter(v, v.end()));
(4) works:
copy(c.begin(), c.end(), back_inserter(v));
------------------------------------------------------------------------------*/

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	map<int, string> m;  // ex11_16
	m[25] = "zyx";
	auto it = m.begin();	
	it->second = "zyg";
	cout << it->second;

	multiset<string> c = {"aa", "bb", "cc"};   // ex11_17
	vector<string> v = {"dd", "ee", "ff"};
	copy(v.begin(), v.end(), inserter(c, c.end()));
	copy(c.begin(), c.end(), inserter(v, v.end()));
	copy(c.begin(), c.end(), back_inserter(v)); 

	return 0;
}