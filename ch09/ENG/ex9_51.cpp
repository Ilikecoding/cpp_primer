/*--------------------------------------------------------------
ex9_51:
Write a class that has three unsigned members representing 
year, month, and day. Write a constructor that takes a string
representing a date. Your constructor should handle a variety 
of date formats, such as January 1, 1900, 1/1/1900, 
Jan 1, 1900, and so on.
--------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
	Date(const string &s);
	unsigned year;
	unsigned month;
	unsigned day;
};

Date::Date(const string &s)
{
	if(s.find_first_of("/") != string::npos)
	{
		day = stoi(s.substr(0, s.find_first_of("/")));
		month = stoi(s.substr(s.find_first_of("/") + 1, s.find_last_of("/") - s.find_first_of("/") - 1));
		year = stoi(s.substr(s.find_last_of("/") + 1, 4));
	}

	else if(s.find_first_of(" ") != string::npos && s.find_first_of(" ") == 3)
	{
		string sub = s.substr(0, s.find_first_of(" "));

		if(sub == "Jan")    month = 1;
		if(sub == "Feb")    month = 2;
		if(sub == "Mar")    month = 3;
		if(sub == "Apr")    month = 4;
		if(sub == "May")    month = 5;
		if(sub == "Jun")    month = 6;
		if(sub == "Jul")    month = 7;
		if(sub == "Aug")    month = 8;
		if(sub == "Sep")    month = 9;
		if(sub == "Oct")    month = 10;
		if(sub == "Nov")    month = 11;
		if(sub == "Dec")    month = 12;

		day = stoi(s.substr(s.find_first_of(" ") + 1, s.find_first_of(",") - s.find_first_of("1234567890")));
		year = stoi(s.substr(s.find_last_of(" ") + 1, 4));
	}

	else
	{
		string sub = s.substr(0, s.find_first_of(" "));

		if(sub == "January")    month = 1;
		if(sub == "February")    month = 2;
		if(sub == "March")    month = 3;
		if(sub == "April")    month = 4;
		if(sub == "May")    month = 5;
		if(sub == "June")    month = 6;
		if(sub == "July")    month = 7;
		if(sub == "August")    month = 8;
		if(sub == "September")    month = 9;
		if(sub == "October")    month = 10;
		if(sub == "November")    month = 11;
		if(sub == "December")    month = 12;

		day = stoi(s.substr(s.find_first_of(" ") + 1, s.find_first_of(",") - s.find_first_of("1234567890")));
		year = stoi(s.substr(s.find_last_of(" ") + 1, 4));
	}
}

int main(int argc, char const *argv[])
{
	Date d1("24/10/2015"), d2("Oct 24, 2015"), d3("October 24, 2015");
	
	cout << d1.year << " " << d1.month << " " << d1.day << endl;
	cout << d2.year << " " << d2.month << " " << d2.day << endl;
	cout << d3.year << " " << d3.month << " " << d3.day << endl;

	return 0;
}