#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int len = strlen(s.c_str());
		if (len == 0)
			return 0;

		int count = 0 , p = 0;
		for (int i = len-1; i >= 0; i--)
		{
			count = count + Num(s[i]) * pow(26, p);
			p++;
		}
		return count;
	}

	int Num(char c)
	{
		switch (c)
		{
		case 'A':
			return 1; break;
		case 'B':
			return 2; break;
		case 'C':
			return 3; break;
		case 'D':
			return 4; break;
		case 'E':
			return 5; break;
		case 'F':
			return 6; break;
		case 'G':
			return 7; break;
		case 'H':
			return 8; break;
		case 'I':
			return 9; break;
		case 'J':
			return 10; break;
		case 'K':
			return 11; break;
		case 'L':
			return 12; break;
		case 'M':
			return 13; break;
		case 'N':
			return 14; break;
		case 'O':
			return 15; break;
		case 'P':
			return 16; break;
		case 'Q':
			return 17; break;
		case 'R':
			return 18; break;
		case 'S':
			return 19; break;
		case 'T':
			return 20; break;
		case 'U':
			return 21; break;
		case 'V':
			return 22; break;
		case 'W':
			return 23; break;
		case 'X':
			return 24; break;
		case 'Y':
			return 25; break;
		case 'Z':
			return 26; break;
		default:
			return 0;  break;
		}
	}
};

int main()
{
	string s = "A";
	string s1 = "ZZ";
	string s2 = "AAA";

	Solution *so = new Solution();
	cout << so->titleToNumber(s) << endl;
	cout << so->titleToNumber(s1) << endl;
	cout << so->titleToNumber(s2) << endl;

	system("pause");
	return 0;
}