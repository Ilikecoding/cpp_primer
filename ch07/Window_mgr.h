#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include "Screen.h"
#include <vector>

class Window_mgr
{
public:
	typedef std::vector<Screen>::size_type ScreenIndex;
    inline void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

void Window_mgr::clear(ScreenIndex i)
{
	if(i >= screens.size())
		return;
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}