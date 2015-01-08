/*
Exercise 12.27: The TextQuery and QueryResult classes use only
capabilities that we have already covered. Without looking ahead, 
write your own versions of these classes.

Exercise 12.30: Define your own versions of the TextQuery and
QueryResult classes and execute the runQueries function from § 12.3.1
(p. 486).

Exercise 12.33: In Chapter 15 we’ll extend our query system and will need
some additional members in the QueryResult class. Add members named
begin and end that return iterators into the set of line numbers returned
by a given query, and a member named get_file that returns a
shared_ptr to the file in the QueryResult object.
*/

#include <iostream>
#include <fstream> 
#include <string>

#include "QueryResult.h"
#include "TextQuery.h"

void RunQuery(std::ifstream &is)
{
	TextQuery tq(is);
	while(true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		std::cin >> s;
		if(s == "q") break;
		print(std::cout, tq.query(s));
		std::cout << std::endl;
	}
}

int main(int argc, char **argv)
{
	std::ifstream is("test.txt");
	RunQuery(is);
	return 0;
}