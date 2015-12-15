#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	//字符串模式匹配问题，s为匹配串，p为模式串
	bool isMatch(string s, string p) {
		return isMatch2(s.c_str(), p.c_str());
	}

	/*转换为字符串指针解决该问题*/
	bool isMatch2(const char *s, const char *p)
	{
		if (p == NULL || s == NULL)
			return false;
		else if (*p == '\0')
			return (*s == '\0');
		else
		{
			if (*p == '*')
			{
				while (*p == '*')
					++p;

				/*处理'*'可以匹配任意长度任意格式的字符串*/
				while (*s != '\0')
				{
					if (isMatch2(s, p))
						return true;
					++s;
				}//while

				return isMatch2(s, p);
			}
			else if((*s!='\0' && *p == '?') || (*s == *p)){
				return isMatch2(++s, ++p);
			}//else
			return false;
		}//else
	}
};

int main()
{
	Solution s;

	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "aa") << endl;
	cout << s.isMatch("aaa", "aa") << endl;
	cout << s.isMatch("aa", "*") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("ab", "?*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;
	cout << s.isMatch("a", "ab*") << endl;

	system("pause");
	return 0;

}