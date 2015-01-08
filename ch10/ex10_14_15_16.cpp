/*-------------------------------------------------------------------
Exercise 10.14: 
Write a lambda that takes two ints and returns their sum.

Exercise 10.15: 
Write a lambda that captures an int from its enclosing function 
and takes an int parameter. The lambda should return the sum of
the captured int and the int parameter.

Exercise 10.16: 
Write your own version of the biggies function using lambdas.
--------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void biggies(vector<string> &words, string::size_type sz);

int main(int argc, char const *argv[])
{
	//ex10_14
	auto f = [](int x, int y){ return x + y; };
	cout << f(1, 2) << endl;

    //ex10_15
	int x = 1;
	auto l = [&x](int y){ return x + y; };
	cout << l(2) << endl;

	//ex10_16
	vector<string> words = {"vhdl", "zyx", "zyg", "zyh", "noreason", "hehe", "zyx"};
	biggies(words, 3);

	return 0;
}

void biggies(vector<string> &words, string::size_type sz)
{
	sort(words.begin(), words.end());
	auto unique_end = unique(words.begin(), words.end());
	words.erase(unique_end, words.end());

	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size();});

	auto wc = find_if(words.begin(), words.end(),[sz](const string &s) {return s.size() > sz;});

	for(auto it = wc; it != words.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}