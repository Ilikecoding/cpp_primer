/*-------------------------------------------
Open the file given and read the contents.
-------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

istream &f(istream &in);
int OpenFile(string &FileName);

int main(int argc, char const *argv[])
{
	string FileName;
	cout << "Input the name of file" << endl;
	cin >> FileName;

	OpenFile(FileName);

	return 0;
}

istream &f(istream &in)
{
	string str;
	while(in >> str, !in.eof())
	{
		if(in.bad())
		{
			throw runtime_error("IO stream corrupted.");
		}
		if(in.fail())
		{
			cerr << "Bad data, try again." << endl;
			in.clear();
			in.setstate(istream::eofbit);
			continue;
		}
		cout << str << endl;
	}
	in.clear();
	
	return in;
}

int OpenFile(string &FileName)
{
	fstream fOpen;
	fOpen.clear();
	fOpen.open(FileName);

	if(!fOpen)
	{
		cerr << "Can not open the file" << endl;
		return -1;
	}

	string s;
	while(fOpen >> s)
	{
		f(fOpen);
		cout << s << " ";
	}
	fOpen.close();
	return 1;
}