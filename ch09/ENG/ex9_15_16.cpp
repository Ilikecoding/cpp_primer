/*-------------------------------------------
ex9_15:
Write a program to determine whether two 
vector<int>s are equal.

ex9_15:
Repeat the previous program, but compare
elements in a list<int> and a vector<int>
-------------------------------------------*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*ex9_15*/
bool is_equal1(const vector<int> &v1, const vector<int> &v2);

/*ex9_16*/
bool is_equal2(const vector<int> &v, const list<int> &l);


int main(int argc, char const *argv[])
{
	vector<int> v1{0, 1, 2};
	vector<int> v2{0, 1, 3};
    list<int> l{0, 1, 2};

    if(is_equal1(v1, v2))
    {
    	cout << "v1 and v2 are equal." << endl;
    }
    else
    {
    	cout << "v1 and v2 are different." << endl;
    }

    if(is_equal2(v1, l))
    {
    	cout << "v1 and l are equal." << endl;
    }
    else
    {
    	cout << "v1 and l are different." << endl;
    }
	return 0;
}

bool is_equal1(const vector<int> &v1, const vector<int> &v2)
{
	return v1 == v2;
}

bool is_equal2(const vector<int> &v, const list<int> &l)
{
	if(v.size() != l.size())
	{
		return false;
	}

	auto vit = v.begin();
	auto lit = l.begin();
	while(vit != v.end())
	{
		if(*vit++ != *lit++)
		{
			return false;
		}
	}

	return true;
}

