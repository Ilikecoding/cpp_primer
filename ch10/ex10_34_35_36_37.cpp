/*--------------------------------------------------------------------------
Exercise 10.34: Use reverse_iterators to print a vector in reverse order.
Exercise 10.35: Now print the elements in reverse order using ordinary
iterators.
Exercise 10.36: Use find to find the last element in a list of ints with
value 0.
Exercise 10.37: Given a vector that has ten elements, copy the elements
from positions 3 through 7 in reverse order to a list.
Exercise 10.42: 
Reimplement the program that eliminated duplicate words that we wrote in 
§ 10.2.3 (p. 383) to use a list instead of a vector.
--------------------------------------------------------------------------*/

#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> vi = {1, 2, 3, 4, 5};

    //ex10_34
	for(auto it = vi.crbegin(); it != vi.crend(); ++it)
	{
		cout << *it << endl;
	}

    //ex10_35
    for(auto it = vi.cend() - 1; it != vi.cbegin() - 1; --it)
    {
    	cout << *it << endl;
    }

    //ex10_36
    list<int> ilst = {3, 4, 6, 5, 0, 3, 0, 8};
    auto r_it = find(ilst.rbegin(), ilst.rend(), 0);

    //ex10_37
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> l;
    copy(ivec.rbegin() + 3, ivec.rbegin() + 8, back_inserter(l));
    for(auto i : l)
    {
    	cout << i << " ";
    }
    cout << endl;

    //ex10_42
    list<string> words = {"aa", "aa", "aa", "aaa"};
    words.unique();
    for(auto i : words)
    {
    	cout << i << endl;
    }

	return 0;
}