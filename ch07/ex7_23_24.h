/*
Exercise 7.23: Write your own version of the Screen class.

Exercise 7.24: Give your Screen class three constructors: a default
constructor; a constructor that takes values for height and width and
initializes the contents to hold the given number of blanks; and a constructor
that takes values for height, width, and a character to use as the contents of
the screen.
*/
#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen
{
public:
	typedef std::string::size_type pos;

	Screen() = default;
	Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    inline char get(pos, pos) const;
    inline Screen& move(pos, pos);

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;
};

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

#endif