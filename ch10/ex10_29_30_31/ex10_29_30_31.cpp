/*--------------------------------------------------------------------------
Exercise 10.29: 
Write a program using stream iterators to read a text file into a vector 
of strings.

Exercise 10.30: 
Use stream iterators, sort, and copy to read a sequence of integers from 
the standard input, sort them, and then write them back to the standard 
output.

Exercise 10.31: 
Update the program from the previous exercise so that it prints only the 
unique elements. Your program should use unqiue_copy (§10.4.1, p. 403).
---------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

void read_text_to_vec(const string &s, vector<string> &v);    // ex10_29
void read_sort_write(istream &is, ostream &os);               // ex10_30
void read_sort_write_unique(istream &is, ostream &os);        // ex10_31  

int main(int argc, char const *argv[])
{
	vector<string> words;	
	read_text_to_vec("test.txt", words);
    cout << endl;

    read_sort_write(cin, cout);

    read_sort_write_unique(cin, cout);

	return 0;
}

void read_text_to_vec(const string &s, vector<string> &v)
{
	ifstream input(s);

	if(!input)
	{
		cout << "Can not open file." << endl;
		return;
	}

	istream_iterator<string> fin_it(input), eof;
	while(fin_it != eof)
	{
		v.push_back(*fin_it++);
	}

	ostream_iterator<string> fout_it(cout, " ");
	for(auto i : v)
	{
		*fout_it++ = i;
	}
}

void read_sort_write(istream &is, ostream &os)
{
	vector<int> v;

	istream_iterator<int> in_it(is), eof;
	while(in_it != eof)
	{
		v.push_back(*in_it++);
	}

	sort(v.begin(), v.end());

	ostream_iterator<int> out_it(os, " ");
	copy(v.begin(), v.end(), *out_it++);
}

void read_sort_write_unique(istream &is, ostream &os)
{
	vector<int> v;

	istream_iterator<int> in_it(is), eof;
	while(in_it != eof)
	{
		v.push_back(*in_it++);
	}

    sort(v.begin(), v.end());

	ostream_iterator<int> out_it(os, " ");
    unique_copy(v.begin(), v.end(), *out_it++);
}