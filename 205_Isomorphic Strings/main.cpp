#include <iostream>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;
		//求两个字符串的长度
		int len = s.size();

		//首先验证字符串s—>t的映射
		unordered_map<char, char> um;
		for (int i = 0; i < len; ++i)
		{
			auto pos = um.find(s[i]);
			if (pos == um.end())
				um.insert({ s[i], t[i] });
			else{
				if ((*pos).second != t[i])
					return false;
			}//else
		}//for

		//再验证字符串t—>s的映射
		um.clear();
		for (int i = 0; i < len; ++i)
		{
			auto pos = um.find(t[i]);
			if (pos == um.end())
				um.insert({ t[i], s[i] });
			else{
				if ((*pos).second != s[i])
					return false;
			}//else
		}//for
		return true;
	}
};

int main()
{
	Solution s;

	cout << s.isIsomorphic("egg", "add") << endl;
	cout << s.isIsomorphic("title", "paper") << endl;
	cout << s.isIsomorphic("foo", "bar") << endl;
	system("pause");

}