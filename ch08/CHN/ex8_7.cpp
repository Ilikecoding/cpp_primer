#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream& ex8_7(ifstream &input, vector<string> &files);

int main(int argc, char const *argv[])
{
	vector<string> files;          /*save name of files*/
	files.push_back("test1.txt");
	files.push_back("test2.txt");
	files.push_back("test3.txt");
    files.push_back("test4.txt");

    ifstream input;
	ex8_7(input, files);

	return 0;
}


/*---------------------------------------------
Read contents of the file, and print them out.
---------------------------------------------*/
ifstream& ex8_7(ifstream &input, vector<string> &files)
{
	for(vector<string>::const_iterator it = files.begin(); 
		it != files.end(); ++it)
    {
    	input.open(*it);

    	if(!input)
    	{
    		cerr << "Error: can not open the file " << *it << endl;
    		input.clear();
    	}
    	else  
    	{
    		string s;
    		while(input >> s)
    		{
    			cout << s << endl;
    		}
    		input.close();
    		input.clear();
    	}
    }

    return input;
}