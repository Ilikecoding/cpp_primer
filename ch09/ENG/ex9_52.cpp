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

class Solution
{
public:
	string conversion(string s, int nRows)
	{
		if(s.size() <= nRows || nRows == 1 || s.size() == 0)
		{
			return s;
		}

		string new_s;

		for(int i = 0; i < s.size(); i += 2 * (nRows - 1))
		{
			new_s.append(s[i]);
		}
		for(int i = 1; i < nRows - 1; i++)
		{
			for(int j = i; j < s.size(); j += 2 * (nRows - 1))
			{
				new_s += s[j];
				if(j + 2 * (nRows - 1 - i) < s.size())
				{
					new_s += s[j + 2 * (nRows - 1 - i)];
				}
			}
		}
		for(int i = nRows - 1; i < s.size(); i += 2 * (nRows - 1))
		{
			new_s += s[i];
		}

		return new_s;
	}
};


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

	Solution solution;
	string s("abcdefg");
	cout << solution.conversion(s, 3) << endl;
	return 0;
}