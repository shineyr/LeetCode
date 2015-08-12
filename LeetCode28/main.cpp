#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
	//简单模式匹配算法（BF算法）
	int strStr(string haystack, string needle) {
		int len = strlen(haystack.c_str()), nl = strlen(needle.c_str());

		int i = 0, j = 0;
		while (i < len && j < nl)
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else{
				i = i - j + 1;
				j = 0;
			}//else
		}//while

		if (j == nl)
			return i - nl;
		else
			return -1;
	}

	//从字符串haystack的第pos个位置开始匹配
	int KMP(const string &haystack, const string &needle, int pos)
	{
		int len = strlen(haystack.c_str()), nl = strlen(needle.c_str());

		int i = pos, j = 0;
		int *n = Next(needle);
		while (i < len && j < nl)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++; 
				j++;
			}
			else{
				j = n[j];
			}//else		
		}//while

		if (j == nl)
			return i - nl;
		else
			return -1;

	}

	int* Next(const string &s)
	{
		int i = 0, j = -1;
		int next[500] ;
		int len = strlen(s.c_str());
		next[0] = -1;;
		while (i < len)
		{
			while (j >-1 && s[i] != s[j])
				j = next[j];
			i++;
			j++;

			if (s[i] == s[j])
				next[i] = next[j];
			else
				next[i] = j;				
		}//while
		return next;
	}
};

int main()
{
	string h = "ababcabcacbab", t = "abaabcac";
	//string h = "", t = "";
	Solution *s = new Solution();

	cout << s->KMP(h, t , 0) << endl;
	
	system("pause");
	return 0;
}