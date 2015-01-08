/*
Exercise 7.29: Revise your Screen class so that move, set, and display
functions return Screen and check your prediction from the previous
exercise.
*/

#include "Screen.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
	return 0;
}