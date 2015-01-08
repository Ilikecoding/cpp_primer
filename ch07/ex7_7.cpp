/*
Exercise 7.7: Rewrite the transaction-processing program you wrote for the
exercises in § 7.1.2 (p. 260) to use these new functions.
*/

#include "ex7_6.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	Sales_data total;
	if(read(std::cin, total))
	{
		Sales_data trans;
		while(read(std::cin, trans))
		{
			if(total.bookNo == trans.bookNo)
			{
				total.combine(trans);
			}
			else
			{
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
	    print(std::cout, total) << std::endl;
	}
	else
	{
		std::cerr << "No data" << std::endl;
	}
	return 0;
}