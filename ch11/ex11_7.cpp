/*------------------------------------------------------------------------------
Exercise 11.7: Define a map for which the key is the family’s last name and
the value is a vector of the children’s names. Write code to add new families 
and to add new children to an existing family.
------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, vector<string> > names;

	string last_name;
	cout << "Input the family's last name : " << endl;
	while(cin >> last_name)
	{
		string child_name;
		cout << "Input the children's name :" << endl;
		while(cin >> child_name)
		{
			names[last_name].push_back(child_name);
		}
		cin.clear();
	}

    for(auto l : names)
    {
    	cout << l.first << " : ";
    	for(auto c : l.second)
    	{
    		cout << c << " ";
    	}
    	cout << endl;
    }

	return 0;
}