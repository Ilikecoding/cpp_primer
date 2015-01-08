/*-----------------------------------------------------------------------
Exercise 11.8: Write a program that stores the excluded words in a 
vector instead of in a set. What are the advantages to using a set?
----------------------------------------------------------------------*/

#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	// set version
	set<string> exclude = {"zyx", "zyg", "zyh"};
    string word;
    while(cin >> word)
    {
    	if(exclude.find(word) != exclude.end())
    	{
    		cout << "The word " << word << " excluded." << endl;
    	}
    }
    cin.clear();

    // vector version
    vector<string> excluded = {"zyx", "zyg", "zyh"};
    while(cin >> word)
    {
    	for(const auto &i : excluded)
    	{
    		if(i == word)
    		{
    			cout << "The word " << word << " excluded." << endl;
    		}
    	}
    }
	return 0;
}