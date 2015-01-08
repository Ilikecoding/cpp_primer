/*---------------------------------------------------------------------------
Exercise 11.12: Write a program to read a sequence of strings and ints,
storing each into a pair. Store the pairs in a vector.
Exercise 11.13: There are at least three ways to create the pairs in the
program for the previous exercise. Write three versions of that program,
creating the pairs in each way. Explain which form you think is easiest to
write and understand, and why.
---------------------------------------------------------------------------*/

#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	pair<string, int> p;
	vector<pair<string, int>> v;

	string word;
	int i;
	while(cin >> word >> i)
	{
		// way1: p = {word, i};
		// way2: p = pair<string, int>(word, i);
		// way3:
		p = make_pair(word, i);
		v.push_back(p);
	}

	for(auto e : v)
	{
		cout << e.first << " : " << e.second << endl;
	}
	return 0;
}