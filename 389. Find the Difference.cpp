//
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		int sL = s.length(), tL = t.length();

		vector<int> v(256, 0);
		for (int i = 0; i < sL; ++i)
			++v[s[i]];

		for (int i = 0; i < tL; ++i)
		{
			--v[t[i]];
			if (v[t[i]] < 0)
				return t[i];
		}//for
		return ' ';
	}

};



