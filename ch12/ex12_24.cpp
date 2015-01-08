/*
Exercise 12.24: Write a program that reads a string from the standard input
into a dynamically allocated character array. Describe how your program
handles varying size inputs. Test your program by giving it a string of data
that is longer than the array size you’ve allocated.
*/

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	char *s;
    std::string str;
    while(std::cin >> str)
    {
    	s = new char[str.size()];
    	str.copy(s, str.size());
    	std::cout << s << "\n";
    }
    delete [] s;
	return 0;
}