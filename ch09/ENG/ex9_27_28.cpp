/*-----------------------------------------------------
ex9_27:
Write a program to find and remove the odd-valued
elements in a forward_list<int>.

ex9_28:
Write a function that takes a forward_list<string> 
and two additional string arguments. The function 
should find the first string and insert the second 
immediately following the first. If the first string 
is not found, then insert the second string at the 
end of the list.
-----------------------------------------------------*/

#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

void ex9_27();
forward_list<string> &ex9_28(forward_list<string> &flst, const string &s_find, const string &s_insert);

int main(int argc, char const *argv[])
{
	ex9_27();

	forward_list<string> flst = {"zyx", "zyg", "zyh"};
	ex9_28(flst, "zyg", "hdl");

	for(auto i : flst)
	{
		cout << i << endl;
	}

	return 0;
}


void ex9_27()
{
	forward_list<int> flst = {0, 1, 2, 3, 4, 5};
	auto prev = flst.before_begin();
	auto curr = flst.begin();

	while(curr != flst.end())
	{
		if(*curr % 2)
		{
			curr = flst.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}

	for(auto i : flst)
	{
		cout << i << "\t";
	}
	cout << endl;
}


forward_list<string> &ex9_28(forward_list<string> &flst, const string &s_find, const string &s_insert)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();

	while(curr != flst.end())
	{
		if(*curr == s_find)
		{
			flst.insert_after(curr, s_insert);
			return flst;
		}
		prev = curr;
		++curr;
	}

	flst.insert_after(prev, s_insert);

	return flst;
}