#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		if (path.empty())
			return string();

		stack<string> st;
		int len = path.length();

		for (int i = 0; i < len;)
		{
			//跳过/
			while (i < len && path[i] == '/')
				i++;
			//找到以/分隔的目录名
			string s = "";
			while ( i < len && path[i] != '/')
			{
				s += path[i];
				i++;
			}

			//如果为..则需要弹栈
			if (s == ".." && !st.empty())
				st.pop();
			//如果既不是. 也不是.. 则需要入栈
			else if (s != "" && s != "." && s != "..")
				st.push(s);

		}
		//如果栈空，则为根目录
		if (st.empty())
		{
			return "/";
		}

		//否则链接各级目录并返回
		string ret;
		while (!st.empty())
		{
			ret = '/' + st.top() + ret;
			st.pop();
		}

		return ret;
	}

};

int main()
{
	Solution s;

	string path = "/a/./b/../../c/";

	cout << s.simplifyPath(path) << endl;

	system("pause");
	return 0;
}