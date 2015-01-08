/*---------------------------------------------------------------
ex10_9:
Implement your own version of elimDups. Test your program by 
printing the vector after you read the input, after the call 
to unique, and after the call to erase.
---------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print_vec(vector<string> &v);

int main(int argc, char const *argv[])
{
	vector<string> words = {"a", "b", "g", "w", "b", "e", "b"};

	sort(words.begin(), words.end());
	print_vec(words);

	auto end_unique = unique(words.begin(), words.end());
	print_vec(words);

	words.erase(end_unique, words.end());
	print_vec(words);

	return 0;
}

void print_vec(vector<string> &v)
{
	for(auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}