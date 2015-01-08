/*--------------------------------------------------------------------
Exercise 11.18: Write the type of map_it from the loop on page 430
without using auto or decltype.
--------------------------------------------------------------------*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, size_t> word_count;
	map<string, size_t>::const_iterator map_it = word_count.cbegin();

	while(map_it != word_count.cend())
	{
		cout << map_it->first << " occurs " 
		    << map_it->second << " times" << endl;
        ++map_it;
	}

	return 0;
}