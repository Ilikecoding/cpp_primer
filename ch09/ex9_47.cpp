/*-----------------------------------------------------------
ex9_47:
Write a program that finds each numeric character and then
each alphabetic character in the string "ab2c3d7R4E6". 
Write two versions of the program. The first should use 
find_first_of, and the second find_first_not_of.
-----------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

void ex9_47();
void ex9_48();

int main(int argc, char const *argv[])
{
	string s("ab2c3d7R4E6");
	string numbers("0123456789");
	string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    /*Using find_first_of*/
    cout << "Using find_first_of:" << endl;
    string::size_type pos = 0;
    cout << "Numeric characters:  ";
	while((pos = s.find_first_of(numbers, pos)) != string::npos)
	{
		cout << s[pos] << " ";
		++pos;
	}

    pos = 0;
	cout << "\nAlphabetic characters:  ";
	while((pos = s.find_first_of(alphabet, pos)) != string::npos)
	{
		cout << s[pos] << " ";
		++pos;
	}
    cout << endl;

    /*Using find_first_not_of*/
    cout << "Using find_first_not_of:" << endl;
    pos = 0;
    cout << "Numeric characters:  ";
	while((pos = s.find_first_of(numbers, pos)) != string::npos)
	{
		cout << s[pos] << " ";
		++pos;
	}

    pos = 0;
	cout << "\nAlphabetic characters:  ";
	while((pos = s.find_first_of(alphabet, pos)) != string::npos)
	{
		cout << s[pos] << " ";
		++pos;
	}
    cout << endl;

	return 0;
}