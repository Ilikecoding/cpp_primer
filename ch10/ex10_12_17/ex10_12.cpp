/*-------------------------------------------------------------------
Exercise 10.12: 
Write a function named compareIsbn that compares the isbn() members 
of two Sales_data objects. Use that function to sort a vector that 
holds Sales_data objects.
-------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Sales_data.h"
using namespace std;

bool compareIsbn(const Sales_data &d1, const Sales_data &d2);

int main(int argc, char const *argv[])
{
	Sales_data d1("aaa"), d2("ac"), d3("zzz"), d4("aa");
	vector<Sales_data> v = {d1, d2, d3, d4};
	sort(v.begin(), v.end(), compareIsbn);
	
	for(auto i : v)
	{
		cout << i.isbn() << " ";
	}
	cout << endl;
	return 0;	
}

bool compareIsbn(const Sales_data &d1, const Sales_data &d2)
{
	return d1.isbn().size() < d2.isbn().size();
}