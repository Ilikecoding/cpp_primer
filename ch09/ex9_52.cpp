/*-----------------------------------------------------------
ex9_52:
Use a stack to process parenthesized expressions. When
you see an open parenthesis, note that it was seen. When 
you see a close parenthesis after an open parenthesis, 
pop elements down to and including the open parenthesis 
off the stack. push a value onto the stack to indicate 
that a parenthesized expression was replaced.
-----------------------------------------------------------*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string expression("This is (pezy).");
	bool flag = false;
	stack<char> stk;
	for(const auto &s : expression)
	{
		if(s == '(')         
		{ 
			flag = true;	
			continue; 
		}
		else if(s == ')')    flag = false;
		if(flag)             stk.push(s);
	}

	string str;
	while(!stk.empty())
	{
		str += stk.top();
		stk.pop();
	}

	expression.replace(expression.find("(") + 1, str.size(), str);
	cout << expression << endl;
	return 0;
}