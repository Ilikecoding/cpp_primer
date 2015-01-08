#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
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

    inline Screen& set(char);
    inline Screen& set(pos, pos, char);

    Screen& display(std::ostream &os) 
        { do_display(os); return *this; }
    const Screen& display(std::ostream &os) const
        { do_display(os); return *this; }

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;
	void do_display(std::ostream &os) const { os << contents; }
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

Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen& Screen::set(pos row, pos col, char c)
{
	contents[row * width + col] = c;
	return *this;
}

#endif