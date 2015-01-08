/*
Exercise 11.23: Rewrite the map that stored vectors of children’s names
with a key that is the family last name for the exercises in § 11.2.1 (p. 424)
to use a multimap.
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	multimap<string, string> family;
	string last_name, child_name;
	while(cin >> last_name >> child_name)
	{
		family.emplace(last_name, child_name);
	}

	for(const auto &f : family)
	{
		cout << f.first << " " << f.second << endl;
	}
	return 0;
}