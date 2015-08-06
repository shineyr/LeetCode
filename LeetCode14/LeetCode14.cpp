#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		else if (strs.size() == 1)
			return *(strs.begin());

		vector<string>::iterator beg, end;
		beg = strs.begin();

		//先得到前两个串的公共前缀
		string str = CommonPrefix(*beg, *(beg+1));

		//迭代器后移两个位置
		beg += 2;

		while (beg != strs.end())
		{
			if (str == "")
				break;
			str = CommonPrefix(str, *(beg++));
		}

		return str;
	}

	string CommonPrefix(const string &str1, const string &str2)
	{
		string common = "";
		if (str1 == "" || str2 == "")
			return common;
		
		int len1 = strlen(str1.c_str()) , len2 = strlen(str2.c_str());

		int len = len1 > len2 ? len2 : len1 ;

		for (int i = 0; i < len; i++)
		{
			if (str1[i] == str2[i])
				common += str1[i];
			else
				break;
		}

		return common;
	}
};

int main()
{
	Solution *s = new Solution();

	//vector<string> v = {"abc" , "abcd" , "abc12342143","abc3434"};
	vector<string> v = {};
	cout << s->longestCommonPrefix(v) << endl;
	
	system("pause");

	return 0;
}