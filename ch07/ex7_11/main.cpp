/*
Exercise 7.11: Add constructors to your Sales_data class and write a
program to use each of the constructors.
*/

#include "ex7_11.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Sales_data item1;
	print(cout, item1) << endl;

	Sales_data item2("0-201-78345-x");
	print(cout, item2) << endl;

	Sales_data item3("0-201-78345-x", 3, 20.00);
	print(cout, item3) << endl;

	Sales_data item4(cin);
	print(cout, item4) << endl;

	return 0;
}