#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	/*方法一：字符串比较；如果version1 > version2 则返回1 相等返回0 反之返回-1*/
	int compareVersion1(string version1, string version2) {
		if (version1.empty() && version2.empty())
			return 0;
		else if (version2.empty())
			return 1;
		else if (version1.empty())
			return -1;
		else
		{
			//分别得到版本号的第一部分和第二部分
			int pos = 0;
			for (int i = 0; version1[i] != '\0' && version1[i] != '.'; ++i)
			{
				++pos;
			}//for
			string fir_version1;
			string sec_version1;
			if (pos == version1.length())
			{
				fir_version1 = version1;
				sec_version1 = "";
			}
			else{
				fir_version1 = version1.substr(0, pos);
				sec_version1 = version1.substr(pos + 1, version1.length() - pos - 1);
			}
			//要略过第一部分版本号的开头的0
			pos = 0;
			while (fir_version1[pos] != '\0' && fir_version1[pos] == '0')
			{
				++pos;
			}//while
			if (fir_version1[pos] == '\0')
				fir_version1 = "0";
			else
				fir_version1 = fir_version1.substr(pos, fir_version1.length() - pos);



			pos = 0;
			for (int i = 0; version2[i] != '\0' && version2[i] != '.'; ++i)
			{
				++pos;
			}//for
			string fir_version2;
			string sec_version2;
			if (pos == version2.length())
			{
				fir_version2 = version2;
				sec_version2 = "";
			}
			else{
				fir_version2 = version2.substr(0, pos);
				sec_version2 = version2.substr(pos + 1, version2.length() - pos - 1);
			}//else

			pos = 0;
			while (fir_version2[pos] != '\0' && fir_version2[pos] == '0')
			{
				++pos;
			}//while
			if (fir_version2[pos] == '\0')
				fir_version2 = "0";
			else
				fir_version2 = fir_version2.substr(pos, fir_version2.length() - pos);


			if (strcmp(fir_version1.c_str(), fir_version2.c_str()) != 0)
				return strcmp(fir_version1.c_str(), fir_version2.c_str());
			else
				return strcmp(sec_version1.c_str(), sec_version2.c_str());		
		}
	}

	//方法二：化为整数比较
	int compareVersion(string version1, string version2) {
		int val1, val2;
		int idx1 = 0, idx2 = 0;
		while (idx1 < version1.length() || idx2 < version2.length()) {
			val1 = 0;
			while (idx1 < version1.length()) {
				if (version1[idx1] == '.') {
					++idx1;
					break;
				}
				val1 = val1 * 10 + (version1[idx1] - '0');
				++idx1;
			}
			val2 = 0;
			while (idx2 < version2.length()) {
				if (version2[idx2] == '.') {
					++idx2;
					break;
				}
				val2 = val2 * 10 + (version2[idx2] - '0');
				++idx2;
			}
			if (val1 > val2) return 1;
			if (val1 < val2) return -1;
		}
		return 0;
	}
};

int main()
{
	//0.1 < 1.1 < 1.2 < 13.37
	string version1 = "1.0", version2 = "1.2";

	Solution s;
	cout << s.compareVersion(version1, version2) << endl;

	system("pause");
	return 0;
}