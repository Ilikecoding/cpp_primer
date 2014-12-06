/*-----------------------------------------------------------
ex9_26:
Using the following definition of ia, copy ia into a vector 
and into a list. Use the single-iterator form of erase to 
remove the elements with odd values from your list and the 
even values from your vector.
-----------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> ivec(ia, ia + 11);
	list<int> ilst(ia, ia + 11);
    

    auto lit = ilst.begin();
	while(lit != ilst.end())
	{
		if(*lit % 2 == 1)
		{
			lit = ilst.erase(lit);
		}
		else
		{
			lit++;
		}
	}

	auto vit = ivec.begin();
	while(vit != ivec.end())
	{
		if(*vit % 2 == 0)
		{
			vit = ivec.erase(vit);
		}
		else
		{
			vit++;
		}
	}


    cout << "ilst:\t";
	for(auto i : ilst)
	{
		cout << i << "\t";
	}
	cout << "\nivec:\t";
    for(auto i : ivec)
    {
    	cout << i << "\t";
    }
    cout << endl;

	return 0;
}