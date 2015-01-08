/*----------------------------------------------------------------------
Exercise 11.3: Write your own version of the word-counting program.
Exercise 11.4: Extend your program to ignore case and punctuation. 
For example, “example.” “example,” and “Example” should all increment 
the same counter.
----------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

void ex11_3();
void ex11_4();

int main(int argc, char const *argv[])
{
	ex11_3();
	ex11_4();

	return 0;
}

void ex11_3()
{
	map<string, size_t> word_count;
	string word;

	while(cin >> word)
	{
		++word_count[word];
	}

	cin.clear();

	for(const auto &w : word_count)
	{
		cout << w.first << " : " << w.second << endl;
	}
}

void ex11_4()
{
	map<string, size_t> word_count;
	string word;

	while(cin >> word)
	{
		for(auto &ch : word)
		{
			ch = tolower(ch);
		}

		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		++word_count[word];
	}

	cin.clear();

	for(const auto &w : word_count)
	{
		cout << w.first << " : " << w.second << endl;
	}
}