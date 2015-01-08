/*
Exercise 11.38: Rewrite the word-counting (§ 11.1, p. 421) and wordtransformation
(§ 11.3.6, p. 440) programs to use an unordered_map.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;

void wordCount()
{
	unordered_map<string, int> word_count;
	string word;
	while(cin >> word)
	{
		++word_count[word];
	}

	for(const auto &w : word_count)
	{
		cout << w.first << ": " << w.second << endl;
	}
}

void wordTransform()
{
	ifstream trans_file("word_transform_file.txt");
	ifstream input("transform_text.txt");

	unordered_map<string, string> trans_map;
	string key;
	string value;
	while(trans_file >> key && getline(trans_file, value))
	{
		trans_map[key] = value.substr(1);
	}

	string line;
	while(getline(input, line))
	{
		istringstream text(line);
		bool firstWord = true;
		string word;
		while(text >> word)
		{
			if(firstWord)
			{
				firstWord = false;
			}
			else
			{
				cout << " ";
			}

            auto map_it = trans_map.find(word);
			if(map_it != trans_map.cend())
			{
				cout << map_it->second;
			}
			else
			{
				cout << word;
			}
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	// wordCount();
	wordTransform();
	return 0;
}