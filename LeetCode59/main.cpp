#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = strlen(s.c_str());

		//如果是空字符串或者是单字符，则直接返回长度
		if (len == 0)
			return len;


		int i = len-1 , j = 0;
		//从后向前找到非空字符
		while (i>=0 && s[i] == ' ')
			--i;

		for (j = i; j>=0 && s[j] != ' '; --j)
			;

		return i - j;
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLastWord("   ") << endl;
	
	system("pause");
	return 0;
}