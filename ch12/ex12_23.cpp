/*
Exercise 12.23: Write a program to concatenate two string literals, putting
the result in a dynamically allocated array of char. Write a program to
concatenate two library strings that have the same value as the literals
used in the first program.
*/

#include <iostream>
#include <string>
using namespace std;

char* concat_literal(const char* s1, const char* s2)
{
	char* result = new char[sizeof(s1) + sizeof(s2) + 10];
	char* p = result;
	while(*s1 != '\0')
	{
		*p++ = *s1++;
	}
	while(*s2 != '\0')
	{
		*p++ = *s2++;
	}
	*p = '\0';
	return result;
}

char* concat_literal(const string &s1, const string &s2)
{
	char* result = new char[s1.size() + s2.size() + 10];
	char* p = result;
	for(const auto &c : s1)
	{
		*p++ = c;
	}
	for(const auto &c : s2)
	{
		*p++ = c;
	}
	*p = '\0';
	return result;
}


int main(int argc, char const *argv[])
{
	char s1[10] = "abc", s2[10] = "de";
	char* ret1 = concat_literal(s1, s2);
	cout << ret1 << endl;
    delete [] ret1;

	string str1("abc"), str2("de");
	char* ret2 = concat_literal(str1, str2);
	cout << ret2 << endl;
	delete [] ret2;

	return 0;
}