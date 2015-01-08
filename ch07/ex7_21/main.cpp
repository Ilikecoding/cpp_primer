/*
Exercise 7.21: Update your Sales_data class to hide its implementation.
The programs you’ve written to use Sales_data operations should still
continue to work. Recompile those programs with your new class definition to
verify that they still work.
*/

#include "Sales_data.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	Sales_data total;
	if(read(cin, total))
	{
		Sales_data trans;
		while(read(cin, trans))
		{
			if(total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data" << endl;
	}
	return 0;
}