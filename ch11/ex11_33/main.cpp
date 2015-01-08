/*
Exercise 11.33: Implement your own version of the word-transformation
program.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

map<string, string> build_map(ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	while(map_file >> key && getline(map_file, value))
	{ 
		if(value.size() > 1)
		{
			trans_map.insert({key, value.substr(1)});
		    //	Or: trans_map[key] = value.substr(1);
		}
		else
		{
			throw runtime_error("No matching value.");
		}
	}
	return trans_map;
}

const string &transform(const string &s, const map<string, string> &trans_map)
{
	auto map_it = trans_map.find(s);
	if(map_it != trans_map.cend())
	{
		return map_it->second;
	}
	else
	{
		return s;
	}
}

void word_transform(ifstream &map_file, ifstream &input)
{
	map<string, string> trans_map = build_map(map_file);
	string line;
	while(getline(input, line))
	{
		istringstream text(line);
		bool first_word = true;
		string word;
		while(text >> word)
		{
			if(first_word)
			{
				first_word = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	ifstream map_file("word_transform_file.txt");
	ifstream input("transform_text.txt");
	if(!map_file || !input)
	{
		cout << "Can not open the files." << endl;
	}
	else
	{
		word_transform(map_file, input);
    }
	return 0;
}