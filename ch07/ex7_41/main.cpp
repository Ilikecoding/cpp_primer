/*
Exercise 7.41: Rewrite your own version of the Sales_data class to use
delegating constructors. Add a statement to the body of each of the
constructors that prints a message whenever it is executed. Write
declarations to construct a Sales_data object in every way possible. Study
the output until you are certain you understand the order of execution among
delegating constructors.
*/

#include "Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Sales_data item1("cpp primer", 3, 10);
	Sales_data item2;
	Sales_data item3("cpp primer");
    Sales_data item4(cin);
    
	return 0;
}