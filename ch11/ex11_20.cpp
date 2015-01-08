/*----------------------------------------------------------------------------
Exercise 11.20: Rewrite the word-counting program from § 11.1 (p. 421) to
use insert instead of subscripting. Which program do you think is easier to
write and read? Explain your reasoning.
--------------------------------------------------------------------------- */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, int> word_count;
	string word;
	while(cin >> word)
	{
		auto ret = word_count.insert({word, 1});
		if(!ret.second)
		{
			++ret.first->second;
		}
		
		// Second way: 
		// ++word_count.insert({word, 0}).first->second;
	}
    
	for(const auto &w : word_count)
	{
		cout << w.first << ":" << w.second << endl;
	}
	return 0;
}