/*----------------------------------------------------------------------
Exercise 10.22: 
Rewrite the program to count words of size 6 or less using functions 
in place of the lambdas.
----------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
using namespace placeholders;

unsigned ex10_22(const vector<string> &v);
bool check_size(const string &s, string::size_type sz);

int main(int argc, char const *argv[])
{
	vector<string> words = {"my", "name", "is", "coding"};
	cout << ex10_22(words);

	return 0;
}

unsigned ex10_22(const vector<string> &v)
{
	return count_if(v.begin(), v.end(), bind(check_size, _1, 6));
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() <= sz;
}