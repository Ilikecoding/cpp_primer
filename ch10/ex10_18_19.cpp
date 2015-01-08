/*-------------------------------------------------------------------
Exercise 10.18: 
Rewrite biggies to use partition instead of find_if. We described 
the partition algorithm in exercise 10.13 in § 10.3.1 (p.387).

Exercise 10.19: 
Rewrite the previous exercise to use stable_partition, which like 
stable_sort maintains the original element order in the paritioned 
sequence.
-------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void biggies_partition(vector<string> &v, string::size_type sz);
void biggies_stable_partition(vector<string> &v, string::size_type sz);
void elimdups(vector<string> &v);

int main(int argc, char const *argv[])
{
	//ex10_18
	vector<string> words = {"vhdl", "zyx", "zyg", "zyh", "noreason", "hehe", "zyx"};
	biggies_partition(words, 4);

    //ex10_19
	vector<string> words_ = {"vhdl", "zyx", "zyg", "zyh", "noreason", "hehe", "zyx"};
	biggies_stable_partition(words_, 4);

	return 0;
}

void biggies_partition(vector<string> &v, string::size_type sz)
{
    elimdups(v);
	auto new_end = partition(v.begin(), v.end(), 
		[sz](const string &s){ return s.size() < sz; });

	for_each(new_end, v.end(), [](const string &s){ cout << s << " "; });
	cout << endl;
}

void biggies_stable_partition(vector<string> &v, string::size_type sz)
{
    elimdups(v);
	auto new_end = stable_partition(v.begin(), v.end(), 
		[sz](const string &s){ return s.size() < sz; });

	for_each(new_end, v.end(), [](const string &s){ cout << s << " "; });
	cout << endl;
}

void elimdups(vector<string> &v)
{
	sort(v.begin(), v.end());
	auto unique_end = unique(v.begin(), v.end());
	v.erase(unique_end, v.end());
	
	stable_sort(v.begin(), v.end(), [](const string &a, const string &b){
    	return a.size() < b.size();
    });
}