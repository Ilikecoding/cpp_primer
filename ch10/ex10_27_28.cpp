/*---------------------------------------------------------------------------
Exercise 10.27: 
In addition to unique (§ 10.2.3, p. 384), the library defines function 
named unique_copy that takes a third iterator denoting a destination 
into which to copy the unique elements. Write a program that uses 
unique_copy to copy the unique elements from a vector into an initially 
empty list.

Exercise 10.28: 
Copy a vector that holds the values from 1 to 9 inclusive, into three 
other  containers. Use an inserter, a back_inserter, and a front_inserter, 
respectivly to add elements to these containers. Predict how the output 
sequence varies by the kind of inserter and verify your predictions by 
running your programs.
---------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

void print_list(list<int> &l);

int main(int argc, char const *argv[])
{
	vector<int> ivec = {2, 3, 4, 6, 4, 3};

    //ex10_27
	list<int> ilst;
    sort(ivec.begin(), ivec.end());
	unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst));
	print_list(ilst);

    //ex10_28

    list<int> l1;
    copy(ivec.cbegin(), ivec.cend(), inserter(l1, l1.begin()));
    print_list(l1);

    list<int> l2;
    copy(ivec.cbegin(), ivec.cend(), back_inserter(l2));
    print_list(l2);

    list<int> l3;
    copy(ivec.cbegin(), ivec.cend(), front_inserter(l3));
	print_list(l3);

	return 0;
}

void print_list(list<int> &l)
{
	for(auto i : l)
	{
		cout << i << " ";
	}
	cout << endl;
}