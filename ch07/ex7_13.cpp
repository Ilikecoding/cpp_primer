/*
Exercise 7.13: Rewrite the program from page 255 to use the istream
constructor.
*/

#include "ex7_12.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Sales_data total(cin);
	if(!total.isbn().empty())
	{
		while(cin)
		{
			Sales_data trans(cin);
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
	}
	else
	{
		cerr << "No data" << endl;
	}
	
	return 0;
}