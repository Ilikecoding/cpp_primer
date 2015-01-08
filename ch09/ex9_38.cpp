/*----------------------------------------
ex9_38:
Write a program to explore how vectors 
grow in the library you use.
----------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> ivec;
	int ival;

	while(cin >> ival)
	{
		ivec.push_back(ival);
		cout << ivec.capacity() << endl;
	}

	return 0;
}