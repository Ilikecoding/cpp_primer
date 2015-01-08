/*--------------------------------------------------
ex9_41:
Write a program that initializes a string from a
vector<char>.
--------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<char> c_vec = {'2', 'a', 'i', 'j'};
	string s;

	for(auto i : c_vec)
	{
		s.push_back(i);
	}
	cout << s << endl;

	return 0;
}