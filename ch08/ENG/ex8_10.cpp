/*-----------------------------------------------------
Write a program to store each line from a file
in a vector<string>. Use an istringstream to 
read each element from the vector a word at a time.
-----------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> &ex84(const string& filename, vector<string> &v);

int main(int argc, char const *argv[])
{
	vector<string> v;
	v = lines("test.txt", v);

    /*Read each element from v a word at a time.*/
    for(vector<string>::iterator it = v.begin(); it != v.end(); ++it)
    {
    	istringstream sfin(*it);
    	string s;
    	while(sfin >> s)
    	{
    		cout << s << " ";
    	}
    }
	return 0;
}


/*------------------------------------------------------
The function stores each line from the filename in v.
------------------------------------------------------*/
vector<string> &lines(const string &filename, vector<string> &v)
{
	string line;
	ifstream fin(filename);

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
