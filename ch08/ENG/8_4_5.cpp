/*--------------------------------------------------------------------
Write a function to open a file for input and read its contents 
into a vector of strings, storing each line(ex84)/word(ex85)
 as a seperate element in the vector.
--------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> &ex84(const string &file_name, vector<string> &v);
vector<string> &ex85(const string &file_name, vector<string> &v);

int main(int argc, char const *argv[])
{
	vector<string> v;
	ex84("test.txt", v);   // Why  v = ex84("test.txt", v)  is wrong?

    for(vector<string>::iterator it = v.begin(); it != v.end(); ++it)
    {
    	cout << *it << endl;
    }


    vector<string> w;
    ex85("test.txt", w);   

    for(vector<string>::iterator it = w.begin(); it != w.end(); ++it)
    {
    	cout << *it << endl;
    }

    system("Pause");
	return 0;
}

 // We can also return void? And v shouldn't be local variable.
vector<string> &ex84(const string &file_name, vector<string> &v) 
{
	string line;
	ifstream fin(file_name);

	if(fin.is_open())
	{
		cout << "opened" << endl;
	}
	else
	{
		cout << "failed" << endl;
	}

	while(getline(fin, line))
	{
		v.push_back(line);
	}

	return v;
}

vector<string> &ex85(const string &file_name, vector<string> &v)
{
	string word;
	ifstream fin(file_name);

	if(fin.is_open())
	{
		cout << "opened" << endl;
	}
	else
	{
		cout << "failed" << endl;
	}

	while(fin >> word)
	{
		v.push_back(word);
	}

    return v;
}