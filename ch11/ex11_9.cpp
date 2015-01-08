/*--------------------------------------------------------------
Exercise 11.9: Define a map that associates words with a list 
of line numbers on which the word might occur.
--------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, list<size_t>> m;

	map<vector<int>::iterator, int> mv; 
    vector<int> vi;
	mv.insert(pair<vector<int>::iterator, int>(vi.begin(), 0));

	map<list<int>::iterator, int> ml;
	list<int> li;
	ml.insert(pair<list<int>::iterator, int>(li.begin(), 0));
	return 0;
}