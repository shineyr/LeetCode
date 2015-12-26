#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	/*用删除的方法将串s变换到t，计算变换方法数*/
	int numDistinct(string s, string t) {
		if (s.empty() || t.empty())
			return 0;
		else if (s.length() < t.length())
			return 0;
		else
		{
			//动态规划
			int ls = s.length(), lt = t.length();
			/*保存由字符串s(0,i) --> t(0,j)的方法数*/
			vector<vector<int> > dp(ls + 1, vector<int>(lt + 1, 0));
			dp[0][0] = 1;
			for (int i = 0; i < ls; ++i)
			{
				/*s(0,i) 转换为 t(0)的方法数为1*/
				dp[i][0] = 1;
			}//for
			for (int i = 1; i <= ls; ++i)
			{
				for (int j = 1; j <= lt; ++j)
				{
					/*首先不管当前字符是否相同，为dp[i][j]赋初值*/
					dp[i][j] = dp[i - 1][j];
					if (s[i-1] == t[j-1])
					{
						/*如果s和t的当前字符相同，有两种选择保留或不保留*/
						dp[i][j] += dp[i - 1][j - 1];
					}//if
				}//for
			}//for
			return dp[ls][lt];
		}
	}	
};

int main()
{
	Solution s;
	cout << s.numDistinct("b", "a") << endl;

	system("pause");
	return 0;
}