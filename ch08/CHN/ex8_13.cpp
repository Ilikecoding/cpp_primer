#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

fstream& open_file(fstream &fOpen, const string &FileName);

int main(int argc, char const *argv[])
{
	string FileName;
	cout << "Input the name of file: ";
	cin >> FileName;

	fstream fOpen;	
	open_file(fOpen, FileName);

	return 0;
}

/*--------------------------------------------------------
The function to open the file and print out the words.
--------------------------------------------------------*/
fstream& open_file(fstream &fOpen, const string &FileName)
{
	fOpen.clear();
	fOpen.open(FileName);
	if(!fOpen)
	{
		cerr << "Can not open the file " << FileName << endl;
		return fOpen;
	}

	string s;
	while(fOpen >> s)
	{
		cout << s << " ";
	}
    fOpen.close();
    return fOpen;
}
