/*
344. Reverse String
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		if (s.empty())
			return s;

		int l = 0, r = s.size() - 1;
		string ret = s;
		while (l < r)
		{
			char t = ret[l];
			ret[l] = ret[r];
			ret[r] = t;

			++l;
			--r;
		}
		return ret;
	}
};