/*----------------------------------------------------------------------
ex_10_6: 
Using fill_n, write a program to set a sequence of int values to 0.

ex_10_7: 
Determine if there are any errors in the following programs and, if 
so, correct the error(s):
(a)
vector<int> vec; list<int> lst; int i;
while (cin >> i)
lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
(b)
vector<int> vec;
vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
fill_n(vec.begin(), 10, 0);
---------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

void print_vec(vector<int> &v);

int main(int argc, char const *argv[])
{
	//ex10_6
	cout << "ex10_6:" << endl;
	vector<int> ivec = {2, 3, 4, 1, 9};
	fill_n(ivec.begin(), ivec.size(), 0);
	print_vec(ivec);

    //ex10_7_a
    cout << "ex10_7_a:" << endl;
    vector<int> vec;
	list<int> lst;
	int i;
	while(cin >> i)
	{
		lst.push_back(i);
	}
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    print_vec(vec);

    //ex10_7_b
    cout << "ex10_7_b:" << endl;
    vector<int> _vec;
    _vec.resize(10);
    fill_n(_vec.begin(), 10, 0);
    print_vec(_vec);

	return 0;
}

void print_vec(vector<int> &v)
{
	for(auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}