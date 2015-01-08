/*
Exercise 11.31: Write a program that defines a multimap of authors and
their works. Use find to find an element in the multimap and erase that
element. Be sure your program works correctly if the element you look for is
not in the map.
Exercise 11.32: Using the multimap from the previous exercise, write a
program to print the list of authors and their works alphabetically.
11.3.6. 
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	// ex11_31
	multimap<string, string> works {
		{"b", "b2"}, 
		{"b", "b1"}, 
		{"b", "b3"}, 
		{"a", "a4"}, 
		{"a", "a5"}, 
		{"c", "c6"}
	};
	string author("b");
	string work("b3");
	int count = works.count(author);
	auto it = works.find(author);
	while(count--)
	{
		if(it->second == work)
		{
			works.erase(it);
		}
		it++;
	}

	for(const auto &w : works)
	{
		cout << w.first << ":" << w.second << endl;
	}

    // ex11_32
	map<string, set<string>> order_works;
    for(const auto &w : works)
    {
    	order_works[w.first].insert(w.second);
    }

    for(const auto &w :order_works)
    {
    	cout << w.first << " : ";
    	for(const auto &i : w.second)
    	{
    		cout << i << " ";
    	}
    	cout << endl;
    }
	return 0;
}