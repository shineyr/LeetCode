#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		//输入参数枚举
		enum InputType{
			INVALID, //代表不正确
			SPACE, // 代表空格
			SIGN, // 代表符号
			DIGIT,
			DOT, //代表点符号
			EXPONENT, //代表科学计算
			NUM_INPUTS //数字输入
		};

		int transitionTable[][NUM_INPUTS] =
		{
			-1, 0, 3, 1, 2, -1,     // next states for state 0
			-1, 8, -1, 1, 4, 5,     // next states for state 1
			-1, -1, -1, 4, -1, -1,     // next states for state 2
			-1, -1, -1, 1, 2, -1,     // next states for state 3
			-1, 8, -1, 4, -1, 5,     // next states for state 4
			-1, -1, 6, 7, -1, -1,     // next states for state 5
			-1, -1, -1, 7, -1, -1,     // next states for state 6
			-1, 8, -1, 7, -1, -1,     // next states for state 7
			-1, 8, -1, -1, -1, -1,     // next states for state 8
		};

		
		int state = 0, i = 0;
		while (s[i] != '\0')
		{
			InputType inputType = INVALID;
			if (isspace(s[i]))
				inputType = SPACE;
			else if (s[i] == '+' || s[i] == '-')
				inputType = SIGN;
			else if (isdigit(s[i]))
				inputType = DIGIT;
			else if (s[i] == '.')
				inputType = DOT;
			else if (s[i] == 'e' || s[i] == 'E')
				inputType = EXPONENT;

			state = transitionTable[state][inputType];

			if (state == -1)
				return false;
			else
				i++;
		}
		
		return state == 1 || state == 4 || state == 7 || state == 8;
			
	}
};

int main()
{
	Solution s;
	cout << s.isNumber("0") << endl;

	system("pause");
	return 0;
}