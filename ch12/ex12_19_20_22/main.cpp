/*
Exercise 12.19: Define your own version of StrBlobPtr and update your
StrBlob class with the appropriate friend declaration and begin and end
members.

Exercise 12.20: Write a program that reads an input file a line at a time
into a StrBlob and uses a StrBlobPtr to print each element in that
StrBlob.

Exercise 12.22: What changes would need to be made to StrBlobPtr to
create a class that can be used with a const StrBlob? Define a class
named ConstStrBlobPtr that can point to a const StrBlob.
*/

#include <iostream>
#include <fstream>
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"
using namespace std;

int main(int argc, char const *argv[])
{
	// ex12_20
	ifstream in("test.txt");
	string line;
	StrBlob sb;
	StrBlobPtr p(sb);
	while(getline(in, line))
	{
		sb.push_back(line);
		cout << p.deref() << endl;
		p.incr();
	}

    // ex12_22
    const StrBlob sb1({"zyx", "zyg", "zyh"});
    ConstStrBlobPtr p1(sb1);
    for(int i = 0; i != 3; ++i)
    {
    	cout << p1.deref() << endl;
    	p1.incr();
    }

	return 0;
}