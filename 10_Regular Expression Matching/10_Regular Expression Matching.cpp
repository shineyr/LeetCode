#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		//如果字符串为空，那么模式串为空则返回true，否则返回false
		if (p.empty())
			return s.empty();

		//求模式串的长度
		int s_len = s.length();

		//求字符串的长度
		int p_len = p.length();

		if (p[1] == '*')
		{
			while ((s[0] != '\0' && p[0] == '.') || (s[0] == p[0]))
			{
				//字符串与模式串匹配0/1/2...个字符的情况 
				if (isMatch(s, p.substr(2, p_len - 2)))
					return true;
				s = s.substr(1, s_len - 1);
			}
			// 字符串与模式串不能匹配  
			return isMatch(s, p.substr(2, p_len - 2));
		}
		else
		{
			if ((s[0] != '\0' && p[0] == '.') || (s[0] == p[0]))
				return isMatch(s.substr(1, s_len - 1), p.substr(1, p_len - 1));
			return false;
		}
	}
};

int main()
{
	Solution s;

	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "aa") << endl;
	cout << s.isMatch("aaa", "aa") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("aa", ".*") << endl;
	cout << s.isMatch("ab", ".*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;
	cout << s.isMatch("a", "ab*") << endl;
	system("pause");
	return 0;

}