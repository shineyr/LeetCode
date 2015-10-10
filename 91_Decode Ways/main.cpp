#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;

		//求字符串长度
		int len = s.length();

		//记录对应长度字符串有几种表示方式
		vector<int> ways(len + 1, 0);

		for (int i = 0; i < len; ++i)
		{
			//对首位字符
			if (i == 0)
			{
				//满足[1,9]
				if ((s[0] - '0') > 0 && (s[0] - '0') <= 9)
				{
					ways[i] = 1;
					continue;
				}
				else
					return 0;
			}
			else{
				//得到前一位
				int tmp1 = s[i - 1] - '0';
				//得到当前位
				int tmp2 = s[i] - '0';

				int tmp = tmp1 * 10 + tmp2;

				//如果该两个字符可以表示为一个字母
				if (tmp >= 10 && tmp <= 26)
				{
					//且当前处理为下标第2或以上字符
					if (i > 1)
					{
						//当前位为0
						if (tmp2 == 0)
							ways[i] = ways[i - 2];
						else
							ways[i] = ways[i - 1] + ways[i - 2];
					}
					//此时处理为下标为0，1的两个字符
					else
					{
						if (tmp2 == 0)
							ways[i] = 1;
						else
							ways[i] = 2;
					}
				}
				else{
					if ((s[i] - '0') > 0 && (s[i] - '0') <= 9)
						ways[i] = ways[i - 1];
					else{
						//此时代表字符串中间嵌入非法0，表示方式为0
						return 0;
					}
				}
			}		
 		}//for

		return ways[len-1];
	}
};

int main()
{
	Solution s;
	string str = "123";

	cout << s.numDecodings(str) << endl;

	system("pause");
	return 0;
}