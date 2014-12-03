#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> &lines(const string &FileName, vector<string> &v);
void PrintWord(vector<string> &v);

int main(int argc, char const *argv[])
{
	vector<string> v;
	lines("test1.txt", v);
	PrintWord(v);

	return 0;
}

/*-----------------------------------------
The function saves each line of the file
as an element of the vector.
-----------------------------------------*/
vector<string> &lines(const string &FileName, vector<string> &v)
{
	ifstream input(FileName);

	if(!input)
	{
		cerr << "Can not open the file" << endl;
		return v;
	}
    
    string line;
    while(getline(input, line))
    {
    	v.push_back(line);
    }
    input.close();

    return v;
}

/*----------------------------------------------------------
The function reads words of each line and prints them out.
----------------------------------------------------------*/
void PrintWord(vector<string> &v)
{
	for(vector<string>::const_iterator it = v.begin();
		it != v.end(); ++it)
	{
		istringstream in(*it);
		string word;
		while(in >> word)
		{
			cout << word << endl;
		}
	}
}