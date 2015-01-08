/*
Exercise 12.10: Explain whether the following call to the process function
defined on page 464 is correct. If not, how would you correct the call?
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
Correct.
*/

#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "inside the process function: " << ptr.use_count() << endl;
}

int main(int argc, char const *argv[])
{
	shared_ptr<int> p(new int(42));
	process(p);
	cout << p.use_count() << endl;
	auto q = p;
	cout << p.use_count() << endl;
	cout << "the int p now points to: " << *p << endl;
	return 0;
}