#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

		if (s.empty() || numRows == 1)
			return s;
		//声明numRows个字符串，对该之字型序列处理
		string *res = new string[numRows];
		int i = 0, j, gap = numRows - 2;
		while (i < s.size()){
			for (j = 0; i < s.size() && j < numRows; ++j) res[j] += s[i++];
			for (j = gap; i < s.size() && j > 0; --j) res[j] += s[i++];
		}
		string str = "";
		for (i = 0; i < numRows; ++i)
			str += res[i];
		return str;
	}

};

int main()
{
	Solution s;

	cout << s.convert("PAYPALISHIRING", 3) << endl;

	system("pause");
	return 0;
}