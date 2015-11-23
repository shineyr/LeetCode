#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		if (str.empty())
			return false;

		//从输入的字符串源串得到字符串数组
		vector<string> strs;
		string s = "";
		for (int i = 0; str[i] != '\0'; ++i)
		{
			if (str[i] == ' ')
			{
				strs.push_back(s);
				s = "";
			}
			else
				s += str[i];
		}//for
		//保存末尾单词
		strs.push_back(s);

		if (pattern.size() != strs.size())
			return false;
		//判断模式匹配
		int len = pattern.size();
		unordered_map<char, string> um1;
		unordered_map<string, char> um2;
		for (int i = 0; i < len; ++i)
		{
			auto iter1 = um1.find(pattern[i]);
			auto iter2 = um2.find(strs[i]);
			
			if (iter1 != um1.end() && iter2 != um2.end())
			{
				if ((*iter1).second == strs[i] && (*iter2).second == pattern[i])
					continue;
				else
					return false;
			}//if
			else if (iter1 == um1.end() && iter2 != um2.end())
				return false;
			else if (iter1 != um1.end() && iter2 == um2.end())
				return false;
			else
				um1.insert({ pattern[i], strs[i] });
				um2.insert({ strs[i], pattern[i] });
		}//for
		return true;
	}
};

int main()
{
	string pattern = "abba", str = "dog cat cat fish";
	Solution s;
	cout << s.wordPattern(pattern, str) << endl;

	system("pause");
	return 0;
}