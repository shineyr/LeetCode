#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*方法一：递归实现,对大数据组会TLE*/
	bool isInterleave1(string s1, string s2, string s3) {
		int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();

		if (len2 == 0)
			return s1 == s3;
		else if (len1 == 0)
			return s2 == s3;
		else if (len3 == 0)
			return len1 + len2 == 0;
		else
		{
			if (s1[0] == s3[0] && s2[0] != s3[0])
				return isInterleave1(s1.substr(1), s2, s3.substr(1));
			else if (s1[0] != s3[0] && s2[0] == s3[0])
				return isInterleave1(s1, s2.substr(1), s3.substr(1));
			else if (s1[0] == s3[0] && s2[0] == s3[0])
				return isInterleave1(s1.substr(1), s2, s3.substr(1)) || isInterleave(s1, s2.substr(1), s3.substr(1));
			else
				return false;
		}//else
	}

	/*方法二：二维动态规划*/
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
		if (len1 + len2 != len3)
			return false;
		else if (len2 == 0)
			return s1 == s3;
		else if (len1 == 0)
			return s2 == s3;
		else if (len3 == 0)
			return len1 + len2 == 0;
		else
		{
			vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
			dp[0][0] = 1;
			for (int i = 1; i <= len1; ++i)
			{
				if (s1[i - 1] == s3[i - 1])
					dp[i][0] = 1;
				else
					break;
			}//for

			for (int j = 1; j <= len2; ++j)
			{
				if (s2[j - 1] == s3[j - 1])
					dp[0][j] = 1;
				else
					break;
			}//for

			for (int i = 1; i <= len1; ++i)
			{
				for (int j = 1; j <= len2; ++j)
				{
					if (s1[i - 1] == s3[i + j - 1])
						dp[i][j] = dp[i - 1][j] || dp[i][j];
					if (s2[j - 1] == s3[i + j - 1])
						dp[i][j] = dp[i][j - 1] || dp[i][j];
				}//for
			}//for
			return dp[len1][len2] == 1;
		}//else
	}
};

int main()
{
	Solution s;
	string s1 = "a", s2 = "b", s3 = "aba";

	cout << s.isInterleave(s1, s2, s3) << endl;

	system("pause");
	return 0;
}
