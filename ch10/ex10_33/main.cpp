/*-------------------------------------------------------------------------------
Exercise 10.33: 
Write a program that takes the names of an input file and two output files. 
The input file should hold integers. Using an istream_iterator read the 
input file. Using ostream_iterators, write the odd numbers into the first 
output file. Each value should be followed by a space. Write the even numbers 
into the second file. Each of these values should be placed on a separate line.
-------------------------------------------------------------------------------*/

#include <fstream>
#include <iterator>
using namespace std;

void one_write_two(const string &infile, const string &odd_outfile, const string &even_outfile);

int main(int argc, char const *argv[])
{
	one_write_two("input.txt", "odd_output.txt", "even_output.txt");
	return 0;
}

void one_write_two(const string &infile, const string &odd_outfile, const string &even_outfile)
{
	ifstream input(infile);
	istream_iterator<int> in_iter(input), eof;

	ofstream odd_output(odd_outfile), even_output(even_outfile);
    ostream_iterator<int> odd_out_iter(odd_output, " ");
    ostream_iterator<int> even_out_iter(even_output, "\n");

    while(in_iter != eof)
    {
    	if(*in_iter % 2)
    	{
    		*odd_out_iter++ = *in_iter++;
    	}
    	else
    	{
    		*even_out_iter++ = *in_iter++;
    	}
    }
}