/*------------------------------------------
Read the stringstream and print the string.
------------------------------------------*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

istream &f(istream &in);

int main(int argc, char const *argv[])
{
	int val1 = 512, val2 = 1024;
	ostringstream format_message;
	format_message << "val1: " << val1 << " val2: " << val2 << "\n";

	istringstream input_istring(format_message.str());

	f(input_istring);

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
			cerr << "Bad data." << endl;
			in.clear();
			in.setstate(istream::eofbit); 
			continue;
		}
		cout << str << endl; 
	}

	in.clear();
	
	return in;
}