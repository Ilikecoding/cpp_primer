#include <iostream>
using namespace std;

/*---------------------------------------------------------
The function reads the stream until it hits end_of_file, 
and prints what it reads to the standard output.
---------------------------------------------------------*/
istream &f(istream &in)
{
	int ival;
	while(in >> ival, !in.eof())
	{
		if(in.bad())   //input stream is corrupted
		{
			throw runtime_error("IO stream corrupted.");
		}

		if(in.fail())  //bad input
		{
			cerr << "Bad date, try again:";
			in.clear();
			in.setstate(istream::eofbit);    
			continue;
		}

		cout << ival << endl;
	}

	in.clear();   //reset the stream
	return in;
}

int main(int argc, char const *argv[])
{
	cout << "Input some vals(ctrl + z to end):\n";
	f(cin);
	return 0;
}