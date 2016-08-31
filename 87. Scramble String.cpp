//87. Scramble String
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*方法一：递归判断，把两个字符串分别分隔为两部分*/
	bool isScramble1(string s1, string s2) {
		if (s1.empty() && s2.empty())
			return true;

		int l1 = s1.length(), l2 = s2.length();
		if (l1 != l2)
			return false;

		if (l1 == 1)
			return s1 == s2;

		string tmp1 = s1, tmp2 = s2;
		sort(tmp1.begin(), tmp1.end());
		sort(tmp2.begin(), tmp2.end());

		for (int i = 0; i < l1; ++i)
			if (tmp1[i] != tmp2[i])
				return false;

		bool ret = false;
		//以下标i为分割点，将两个字符串分割为两部分
		for (int i = 1; i < l1 && !ret; ++i)
		{
			string s11 = s1.substr(0, i);
			string s12 = s1.substr(i,l1-i);

			string s21 = s2.substr(0, i);
			string s22 = s2.substr(i,l1-i);

			ret = isScramble1(s11, s21) && isScramble1(s12, s22);
			if (!ret)
			{
				s21 = s2.substr(0, l1 - i);
				s22 = s2.substr(l1 - i,i);
				ret = isScramble1(s11, s22) && isScramble1(s12, s21);
			}//if
		}//for

		return ret;
	}


	/*方法二：动态规划*/
	bool isScramble(string s1, string s2)
	{
		int l1 = s1.length(), l2 = s2.length();
		if (l1 != l2)
			return false;

		if (l1 == 0)
			return true;

		//dp[k][i][j]表示s1[i,i+k]与s2[j,j+k]的关系
		vector<vector<vector<int>>> dp(l1, vector<vector<int>>(l1, vector<int>(l1, 0)));
		for (int i = 0; i < l1; ++i)
		{
			for (int j = 0; j < l1; ++j)
			{
				if (s1[i] == s2[j])
					dp[0][i][j] = 1;
			}//for
		}//for

		for (int k = 2; k <= l1; ++k)
		{
			for (int i = l1 - k; i >= 0; --i)
			{
				for (int j = l1 - k; j >= 0; --j)
				{
					bool ret = false;
					for (int m = 1; m < k && !ret; ++m)
					{
						ret = (dp[m - 1][i][j] && dp[k - m - 1][i + m][j + m]) ||
							(dp[m - 1][i][j + k - m] && dp[k - m - 1][i + m][j]);
					}//for

					dp[k - 1][i][j] = ret ? 1 : 0;
				}//for
			}//for
		}//for
		return dp[l1 - 1][0][0];
	}


};

int main()
{
	cout << Solution().isScramble1("great", "rgtae") << endl;

	system("pause");
	return 0;
}
