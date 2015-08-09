#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		int len = strlen(s.c_str());
		if (len == 0)
			return true;
		if (len % 2 != 0)
			return false;

		//括号匹配问题，用数据结构栈辅助实现
		stack<char> sta;
		for (int i = 0; i < len; i++)
		{
			if (s[i] != ')' && s[i] != ']' && s[i] != '}')
				sta.push(s[i]);
			else
			{
				if (sta.size() <= 0)
					return false;
				if (s[i] == PairLetter(sta.top()))
					sta.pop();
				else
					return false;
			}//else
		}//for
		if (sta.size() == 0)
			return true;
		else
			return false;
	}

	char PairLetter(const char &c)
	{
		switch (c)
		{
		case '(':
			return ')'; break;
		case '[':
			return ']'; break;
		case '{':
			return '}'; break;
		default:
			return 0; break;
		}
	}
};

int main()
{
	//string str = "()";
	//string str = "";
	//string str = "()()[][]{}{}";
	string str = "([{]}){}";

	Solution *s = new Solution();
	if (s->isValid(str))
		cout << str <<" : "<<  "true" << endl;
	else
		cout << str << " : " << "false" << endl;

	system("pause");
	return 0;

}