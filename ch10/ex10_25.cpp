/*--------------------------------------------------------------
Exercise 10.25: 
In the exercises for § 10.3.2 (p. 392) you wrote a version of 
biggies that uses partition. Rewrite that function to use
check_size and bind.
--------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

void biggies(vector<string> &v, string::size_type sz)
{
	sort(v.begin(), v.end());
	auto unique_end = unique(v.begin(), v.end());
	v.erase(unique_end, v.end());

    stable_sort(v.begin(), v.end(), 
    	[](const string &a, const string &b) { return a.size() < b.size(); });

    auto new_end = partition(v.begin(), v.end(), bind(check_size, _1, sz));

    for(auto it = new_end; it != v.end(); ++it)
    {
    	cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
	vector<string> words = {"vhdl", "zyx", "zyg", "zyh", "noreason", "hehe", "zyx"};
	biggies(words, 4);
	return 0;
}