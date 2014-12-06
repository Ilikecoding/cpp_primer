#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int count_of_int(vector<int> &v, int val);

int main(int argc, char const *argv[])
{
	vector<int> ivec = {2, 3, 1, 4, 2, 5};
	cout << count_of_int(ivec, 2) << endl;

	return 0;
}

int count_of_int(vector<int> &v, int val)
{
	return count(v.begin(), v.end(), val);
}