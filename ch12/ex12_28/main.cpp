/*
Exercise 12.28: Write a program to implement text queries without defining
classes to manage the data. Your program should take a file and interact
with a user to query for words in that file. Use vector, map, and set
containers to hold the data for the file and to generate the results for the
queries.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
using line_no = vector<string>::size_type;

void build_vec(ifstream &is, vector<string> &v)
{
	string line;
	while(getline(is, line))
	{
		v.push_back(line);
	}
}

void search(const string &key, 
	          const vector<string> &v, 
	          map<string, set<line_no>> &m)
{
	for(size_t i = 0; i < v.size(); i++)
	{
		istringstream is(v[i]);
		string word;

		while(is >> word)
		{
			if(word == key)
			{
				m[word].insert(i);
			}
		}
	}
}

void print(const string &key, 
	       const vector<string> &v,
	       map<string, set<line_no>> &m)
{
	set<line_no> lines = m[key];
	cout << "the word " << key << " occurs " 
	    << lines.size() << " times:\n";
	for(const auto &l : lines)
	{
		cout << "\t(line " << l + 1 
			<< "): " << v[l] << "\n";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	ifstream input("test.txt");
	vector<string> text;
	map<string, set<line_no>> word_map;
    build_vec(input, text);
    
    while(true)
    {
	    cout << "enter the word to search, or q to quit: "; 
	    string word;
	    cin >> word;
	    if(word == "q") break;
	    search(word, text, word_map);
		print(word, text, word_map);
    }

	return 0;
}