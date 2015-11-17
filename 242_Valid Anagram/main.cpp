#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	//方法一：排序判断
	bool isAnagram1(string s, string t) {
		if (s.empty() && t.empty())
			return true;
		else if (s.empty() || t.empty())
			return false;
		
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		if (s == t)
			return true;
		return false;		
	}
	//方法二：字母个数判相等
	bool isAnagram(string s, string t) {
		vector<int> count(26, 0);
		for (int i = 0; i < s.size(); i++)
			count[s[i] - 'a'] ++;
		for (int i = 0; i < t.size(); i++)
			count[t[i] - 'a'] --;
		for (int i = 0; i < 26; i++)
		if (count[i] != 0)
			return false;
		return true;
	}
};

int main()
{
	Solution s;
	string s1 = "anagram", s2 = "nagaram";
	cout << s.isAnagram(s1, s2) << endl;

	system("pause");
	return 0;
}