#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;

		int hash_tab[256]; //保存当前字符上一次出现的下标
		memset(hash_tab, -1, sizeof(hash_tab)); //hash_tab中初始化所有值为-1
		int max_len = 0, pos = -1;//max_len即是最长子串长度 ， pos为当前子串的开始位置

		for (int i = 0; i<s.length(); i++)
		{
			//每个字符的元位置初始化为-1 ，当当前字符是重复字符时，改变子串的开始位置
			if (hash_tab[s[i]] > pos)
			{
				pos = hash_tab[s[i]];
			}//if

			if (i - pos > max_len)
			{
				max_len = i - pos;
			}//if

			//更改首次出现字符的位置
			hash_tab[s[i]] = i;
		}//for
		return max_len;
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("aaabbbbbbaaaa") << endl;

	system("pause");

	return 0;
}