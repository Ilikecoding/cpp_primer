/*-------------------------------------------------------
Exercise 10.3: 
Use accumulate to sum the elements in a vector<int>.
-------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> ivec = {1, 2, 3, 5};
    int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << sum << endl;
	return 0;
}