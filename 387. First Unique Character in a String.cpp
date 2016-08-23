/*
387. First Unique Character in a String
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
	/*方法一，借助哈希表*/
	int firstUniqChar1(string s) {
		if (s.empty())
			return -1;

		vector<int> v(256, 0);
		int len = s.length();
		for (int i = 0; i < len; ++i)
			++v[s[i]];

		for (int i = 0; i < len; ++i)
			if (v[s[i]] == 1)
				return i;
		return -1;
	}
	/*方法二：*/
	int firstUniqChar(string s) {
		if (s.empty())
			return -1;
		int len = s.length();
		map<char, int> sm;
		for (int i = 0; i < len; ++i)
		{
			++sm[s[i]];
		}//for

		for (int i = 0; i < len; ++i)
			if (sm[s[i]] == 1)
				return i;
		return -1;
	}

	
};