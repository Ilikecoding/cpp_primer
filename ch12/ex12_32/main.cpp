/*
Exercise 12.32: Rewrite the TextQuery and QueryResult classes to use
a StrBlob instead of a vector<string> to hold the input file.
*/

#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

void runQuery(ifstream &is)
{
	TextQuery tq(is);	
	while(true)
	{
		cout << "enter the word to look for, or q to quit: ";
		string s;
		cin >> s;
		if(s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, char const *argv[])
{
	ifstream is("test.txt");
	runQuery(is);

	return 0;
}