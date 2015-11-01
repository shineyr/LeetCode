#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty())
			return;

		//首先，反转整个字符串
		reverse(s.begin(), s.end());

		int n = s.size();

		//再反转每个单词,同时删除多余的空格，最终的字符串头尾不能是空格，且单词之间不能有多余的空格（最多一个）
		string tmp = s;
		s.clear();
		//标记第一个单词,方便处理单词间的空格
		bool flag = true;
		for (int i = 0; i < n;)
		{		
			//找到第一个非空格
			if (tmp[i] == ' ')
			{
				++i;
				continue;
			}//if

			string::iterator beg = tmp.begin() + i, end = tmp.begin();
			
			for (int j = i; j < n; ++j)
			{				
				//到达一个单词间的空格或者到整个字符串的结束
				if (tmp[j] == ' ')
				{
					end += j;

					reverse(beg, end);
					//链接反转后的第一个单词
					if (flag)
					{
						s = s + tmp.substr(i, j - i);
						flag = false;
					}
					else{
						s = s + " " + tmp.substr(i, j - i);
					}
					
					i = j + 1;
					break;
				}//if
				
				if (j == n - 1)
				{
					reverse(beg, tmp.end());
					if (flag)
					{
						s = s + tmp.substr(i, j - i + 1);
					}
					else{
						s = s + " " + tmp.substr(i, j - i + 1);
					}
					i = j + 1;
					break;
				}
			}//for
		}//for
	}
};

int main()
{
	Solution s;
	string str = "    the sky     is blue    ";

	s.reverseWords(str);
	cout << str << "hahaha";

	system("pause");
	return 0;
}