/*---------------------------------------------------------------------
Exercise 9.43: 
Write a function that takes three strings, s, oldVal, and
newVal. Using iterators, and the insert and erase functions 
replace all instances of oldVal that appear in s by newVal. 
Test your function by using it to replace common abbreviations, 
such as “tho” by “though” and “thru” by “through”.

Exercise 9.44: 
Rewrite the previous function using an index and replace.

Exercise 9.45: 
Write a funtion that takes a string representing a name and two 
other strings representing a prefix, such as “Mr.” or “Ms.” and 
a suffix, such as “Jr.” or “III”. Using iterators and the insert 
and append functions, generate and return a new string with the 
suffix and prefix added to the given name.

Exercise 9.46: 
Rewrite the previous exercise using a position and length to
manage the strings. This time use only the insert function.
----------------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

string& ex9_43(string &s, const string &oldVal, const string &newVal);
string &ex9_44(string &s, const string &oldVal, const string &newVal);
string &ex9_45(string &name, const string &prefix, const string &suffix);
string &ex9_46(string &name, const string &prefix, const string &suffix);


int main(int argc, char const *argv[])
{
	string s("thru, thru");
	cout << ex9_43(s, "thru", "zyx") << endl;
	cout << ex9_44(s, "thru", "zyx") << endl;

	string name("Kobe");
	cout << ex9_45(name, "Mr.", "Bryant.") << endl;
	cout << ex9_46(name, "Mr.", "Bryant.") << endl;

	return 0;
}


string& ex9_43(string &s, const string &oldVal, const string &newVal)
{
	for(auto it = s.begin(); it != s.end(); ++it)
	{
		if(s.substr(it - s.begin(), oldVal.size()) == oldVal)
		{
		    s.erase(it, it + oldVal.size());
		    s.insert(it, newVal.begin(), newVal.end());					
		}
	}

	return s;
}

string &ex9_44(string &s, const string &oldVal, const string &newVal)
{
	for(string::size_type i = 0; i != s.size(); i++)
	{
		if(s.substr(i, oldVal.size()) == oldVal)
		{
			s.replace(i, oldVal.size(), newVal);
		}
	}

	return s;
}

string &ex9_45(string &name, const string &prefix, const string &suffix)
{
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(suffix);
	return name;
}

string &ex9_46(string &name, const string &prefix, const string &suffix)
{
	name.insert(0, prefix);
	name.insert(name.size(), suffix);
	return name;
}