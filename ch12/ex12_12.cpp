/*
Exercise 12.12: Using the declarations of p and sp explain each of the
following calls to process. If the call is legal, explain what it does. If the call
is illegal, explain why:
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
    Legal. Copy sp which is a shared_ptr to process().
(b) process(new int());
    Illegal. Plain pointer can not convert to smart pointer implicitly. 
(c) process(p);
    Illegal. Plain pointer can not convert to smart pointer implicitly.
(d) process(shared_ptr<int>(p));
    Legal. Use plain pointer p to construct a shared_ptr, and then copy
    the shared_ptr to process().
*/

#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << ptr.use_count() << endl;
}

int main(int argc, char const *argv[])
{
	auto p = new int();
	auto sp = make_shared<int>();
	process(sp);
	process(shared_ptr<int>(p));
	return 0;
}