/*-----------------------------------------------------------------
Exercise 10.17: 
Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda 
in the call to sort instead of the compareIsbn function.
-----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Sales_data d1("aaa"), d2("ac"), d3("zzz"), d4("aa");
	vector<Sales_data> v = {d1, d2, d3, d4};
	sort(v.begin(), v.end(), [](const Sales_data &lhs, const Sales_data &rhs)
		                     { return lhs.isbn().size() < rhs.isbn().size(); });

	for(auto i : v)
	{
		cout << i.isbn() << " ";
	}
	cout << endl;

	return 0;
}