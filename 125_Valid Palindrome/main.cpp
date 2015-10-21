#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty())
			return true;

		int size = s.length();

		int lhs = 0, rhs = size - 1;
		while (lhs < rhs)
		{
			if (!isalpha(s[lhs]))
			{
				++lhs;
				continue;
			}
			if (!isalpha(s[rhs]))
			{
				--rhs;
				continue;
			}//if

			if (s[lhs] != s[rhs])
				return false;
			else
			{
				++lhs;
				--rhs;
			}

		}//while
		return true;
	}
	//判断是否是字母数字，如果是大写字母则将其转化为小写字母
	bool isalpha(char &c){
		if ((c >= 'A'&&c <= 'Z')){
			c = c - 'A' + 'a';
			return true;
		}
		return (c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9');
	}
};

int main()
{
	Solution s;

	string str = "A man, a plan, a canal: Panama";

	cout << s.isPalindrome(str) << endl;

	system("pause");

	return 0;
}