/*--------------------------------------------------------------------------
Exercise 11.14: Extend the map of children to their family name that you
wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a
pair that holds a child’s name and birthday.
--------------------------------------------------------------------------*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, vector<pair<string, string>>> family;    
	string family_name, child_name, birthday;

	cout << "Input the family's last name" << endl;
	while(cin >> family_name)
	{
		cout << "Input the children's name and birthday" << endl;
		while(cin >> child_name >> birthday)
		{
			family[family_name].push_back({child_name, birthday});
		}
		cin.clear();
	}

	for(auto f : family)
	{
		cout << f.first << endl;
		for(auto e : f.second)
		{
			cout << e.first << " " << e.second << endl;
		}
	}
	return 0;
}