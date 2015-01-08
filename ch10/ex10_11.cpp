/*--------------------------------------------------------------
Exercise 10.11: 
Write a program that uses stable_sort and isShorter to sort 
a vector passed to your version of elimDups. Print the vector 
to verify that your program is correct.
--------------------------------------------------------------*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isShorter(const string &s1, const string &s2);
void elimDups(vector<string> &v);

int main(int argc, char const *argv[])
{
	vector<string> words = {"I", "was", "the", "lucky", "one", "one"};
	elimDups(words);

	for(auto i : words)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &v)
{
	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end());
	stable_sort(v.begin(), v.end(), isShorter);
}