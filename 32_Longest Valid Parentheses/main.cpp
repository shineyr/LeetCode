#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;

		//求括号字符串长度
		int len = s.length();

		//定义一个长度vector，i处值计量从i开始的到len-1长度字符串的最长有效匹配括号长度
		vector<int> dp(len, 0);
		int maxlen = 0;

		for (int i = len - 2; i >= 0; --i)
		{
			if (s[i] == '(')
			{
				int j = i + 1 + dp[i + 1];
				if (j < len && s[j] == ')')
				{
					dp[i] = dp[i + 1] + 2;
					if (j + 1 < len)
						dp[i] += dp[j + 1];
				}
			}

			//实时求最长有效匹配长度
			if (dp[i] > maxlen)
				maxlen = dp[i];
		}//for
		return maxlen;
	}
};

int main()
{
	Solution s;
	cout << s.longestValidParentheses(")()())") << endl;
	cout << s.longestValidParentheses(")(((((()())()()))()(()))(") << endl;
	system("pause");

	return 0;
}