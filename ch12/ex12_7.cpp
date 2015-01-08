/*
Exercise 12.7: Redo the previous exercise, this time using shared_ptr.
*/

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> dynamic_vector_generator()
{
	return make_shared<vector<int>>();
}

void dynamic_vector_processor(shared_ptr<vector<int>> ptr_v)
{
	int ival;
	while(cin >> ival)
	{
		ptr_v->push_back(ival);
	}
}

void dynamic_vector_printer(shared_ptr<vector<int>> ptr_v)
{
	for(const auto &e : *ptr_v)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	auto ptr_v = dynamic_vector_generator();
	dynamic_vector_processor(ptr_v);
	dynamic_vector_printer(ptr_v);
	return 0;
}