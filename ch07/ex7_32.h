#ifndef EX7_32_H
#define EX7_32_H

#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr
{
public:
	typedef std::vector<Screen>::size_type ScreenIndex;
	inline Window_mgr(Screen); 
	Screen& get(ScreenIndex i) { return screens[i]; }
    inline void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

class Screen
{
public:
	typedef std::string::size_type pos;
    friend void Window_mgr::clear(ScreenIndex);

	Screen() = default;
	Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

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

Window_mgr::Window_mgr(Screen s)
{
	screens.push_back(s);
}

void Window_mgr::clear(ScreenIndex i)
{
	if(i >= screens.size())
		return;
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
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