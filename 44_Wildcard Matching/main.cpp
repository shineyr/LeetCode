#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	//字符串模式匹配问题，s为匹配串，p为模式串
	bool isMatch(string s, string p) {
		return isMatch1(s.c_str(), p.c_str());
	}

	/*方法一：采用贪心的性质  AC*/
	bool isMatch1(const char *s, const char *p) {
		//? match one
		//* match 0,1,2,3..
		// aaaabc *c true
		const char* star = nullptr;
		const char* rs = nullptr;

		while (*s) {
			if (*s == *p || *p == '?') { //match
				s++; p++;
				continue;
			}
			if (*p == '*') {
				star = p; // record star
				p++; //match from next p
				rs = s; // record the position of s , star match 0
				continue;
			}
			if (star != nullptr) { //if have star in front then backtrace
				p = star + 1; //reset the position of p 
				s = rs + 1;
				rs++; //star match 1,2,3,4,5....
				continue;
			}
			return false; //if not match return false
		}
		while (*p == '*') p++; //skip continue star
		return *p == '\0'; // successful match
	}

	/*方法二：利用字符串指针递归解决 性能不好 TLE*/
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