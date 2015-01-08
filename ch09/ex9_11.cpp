/*------------------------------------
ex9_13:
Initialize a vector<double> from 
a list<int> and vector<int>.
------------------------------------*/

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	list<int> ilst{4, 3, 8, 9};
	vector<int> ivec{2, 4, 8};

	vector<double> dvec1(ilst.begin(), ilst.end());  /*Initialized from list<int>*/
	for(auto i : ilst)
	{
		cout << i << " ";
	}
	cout << endl;
	for(auto i : dvec1)
	{
		cout << i << " ";
	}
	cout << endl;

	vector<double> dvec2(ivec.begin(), ivec.end());  /*Initialized from vector<int>*/
	for(auto i : ivec)
	{
		cout << i << " ";
	}
	cout << endl;
	for(auto i : dvec2)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}