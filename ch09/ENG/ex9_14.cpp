/*------------------------------------------
ex9_14:
Assign the elements from a list of char*
to a vector of string
------------------------------------------*/

#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	list<char*> clst(4, "zyx");
	vector<string> svec;
	svec.assign(clst.cbegin(), clst.cend());

	for(auto i : svec)
	{
		cout << i << endl;
	}
	return 0;
}