#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	Solution()
	{
		for (int i = 1; i <= 26; ++i)
		{
			char c = 'A' + i - 1;
			levelMap.insert({ i,c });
		}//for
	}
	string convertToTitle(int n) {
		if (n <= 0)
			return "";
		string str = "";
		while (n)
		{
			if (n >= 1 && n <= 26)
			{
				str += levelMap[n];
				reverse(str.begin(), str.end());
				return str;
			}
			else{
				if (n % 26 == 0)
				{
					str += 'Z';
					n -= 26;
				}
				else
				{
					str += levelMap[n % 26];
				}//else
				n /= 26;
			}
		}
		return str;
	}

private:
	map<int, char> levelMap;
};

int main()
{
	Solution *s = new Solution();

	cout << s->convertToTitle(27) << endl;

	cout << s->convertToTitle(104) << endl;

	system("pause");
	return 0;
}