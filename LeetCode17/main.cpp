#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> vs;

		//求len为数字字符串的长度也对应字母字符串的个数
		int len = strlen(digits.c_str());
		if (len <= 0 )
			return vs;

		if (len == 1)
		{
			string str = letters(digits[0]);
			for (int i = 0; i < strlen(str.c_str()); i++)
			{
				string s = "";
				s += str[i];
			
				vs.push_back(s);
			}
			return vs;
		}

		//前两个单独处理
		
		string str1 = letters(digits[0]);
		string str2 = letters(digits[1]);
		for (int i = 0; i < strlen(str1.c_str()); i++)
		{
			for (int j = 0; j < strlen(str2.c_str()); j++)
			{
				string str = "";
				str = str + str1[i] + str2[j];
				vs.push_back(str);
			}
		}

		for (int i = 2; i < len; i++)
		{
			string str = letters(digits[i]);
			vs = Combine(vs, str);
		}			
		return vs;
	}

	vector<string> Combine(const vector<string> &vs, const string &str2)
	{
		vector<string> v;

		int len = vs.size();
		if (len <= 0)
			return v;

		int len2 = strlen(str2.c_str());

		for (int i = 0; i < len; i++)
		{
			string str = vs[i];
			for (int j = 0; j < len2; j++)
			{
				v.push_back(str + str2[j]);
			}			
		}//for

		return v;
	}

	string letters(const char &num)
	{
		string str = "";

		switch (num)
		{
		case '2':
			str = "abc"; break;
		case '3':
			str = "edf"; break;
		case '4':
			str = "ghi"; break;
		case '5':
			str = "jkl"; break;
		case '6':
			str = "mno"; break;
		case '7':
			str = "pqrs"; break;
		case '8':
			str = "tuv"; break;
		case '9':
			str = "wxyz"; break;
		default:
			str = "";
		}
		return str;
	}
};

int main()
{
	Solution *s = new Solution();

	vector<string> vs = s->letterCombinations("2");

	cout << "[ ";
	for (int i = 0; i < vs.size(); i++)
		cout << "\"" << vs[i] << "\"" << "\t";
	cout << "]" << endl;

	system("pause");
	return 0;
}