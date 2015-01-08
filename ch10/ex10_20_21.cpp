/*----------------------------------------------------------------------------
Exercise 10.20: 
The library defines an algorithm named count_if. Like find_if, this 
function takes a pair of iterators denoting an input range and a 
predicate that it applies to each element in the given range. count_if
returns a count of how often the predicate is true. Use count_if to 
rewrite the portion of our program that counted how many words are 
greater than length 6.

Exercise 10.21: 
Write a lambda that captures a local int variable and decrements that 
variable until it reaches 0. Once the variable is 0 additional calls 
should no longer decrement the variable. The lambda should return a
bool that indicates whether the captured variable is 0.
-----------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

unsigned ex10_20(vector<string> &v);
void ex10_21(int x);

int main(int argc, char const *argv[])
{
	vector<string> words = {"my", "name", "is", "ilikecoding"};
	cout << ex10_20(words) << endl;

	return 0;
}

unsigned ex10_20(vector<string> &v)
{
	return count_if(v.begin(), v.end(),
		[] (const string &s) { return s.size() > 6; } );
}

void ex10_21(int x)
{
	auto f = [&] ()
	{
		bool flag = x == 0;
		while(x != 0)
		{
			x--;
		}
		return flag;
	};
}