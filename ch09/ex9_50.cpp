/*---------------------------------------------------------------
ex9_50:
Write a program to process a vector<string>s whose elements 
represent integral values. Produce the sum of all the elements 
in that vector. Change the program so that it sums of strings 
that represent floating-point values.
---------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sum_of_int(vector<string> &svec);
float sum_of_float(vector<string> &svec);

int main(int argc, char const *argv[])
{
	vector<string> svec = {"11", "12", "13.5"};
	cout << sum_of_int(svec) << endl;
	cout << sum_of_float(svec) << endl;

	return 0;
}

int sum_of_int(vector<string> &svec)
{
	int sum = 0;

	for(auto i : svec)
	{
		sum += stoi(i);
	}

    return sum;
}

float sum_of_float(vector<string> &svec)
{
	float sum = 0.0;

	for(auto i : svec)
	{
		sum += stof(i);
	}

	return sum;
}