#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution{
public:

	Solution()
	{

	}

	~Solution()
	{

	}
	int Value(char c)
	{
		switch (c)
		{
		case 'I':
			return 1; break;
		case 'V':
			return 5; break;
		case 'X':
			return 10; break;
		case 'L':
			return 50; break;
		case 'C':
			return 100; break;
		case 'D':
			return 500; break;
		case 'M':
			return 1000; break;
		default:
			return 0; break;
		}
	}
	int romanToInt(string s) {
		int ret = 0;
		if (s == "")
			return ret;
		ret += Value(s[0]);
		for (int i = 0; s[i+1] != '\0'; i++)
		{
			if (Value(s[i + 1]) <= Value(s[i]))
				ret += Value(s[i + 1]);
			else
				ret = ret + Value(s[i + 1]) - 2 * Value(s[i]);
		}
		return ret;
	}
};

int main()
{
	Solution *s = new Solution();
	cout << s->romanToInt("I") << endl;
	cout << s->romanToInt("IV") << endl;
	cout << s->romanToInt("MDCCCLXXXIV") << endl;
	cout << s->romanToInt("MCMXCVI") << endl;
	system("pause");
	return 0;
}