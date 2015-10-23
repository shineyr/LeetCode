#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty())
			return 0;

		//存储运算数
		stack<int> s;

		//tokens容量
		int size = tokens.size();
		for (int i = 0; i < size; ++i)
		{
			if (!isOper(tokens[i]))
			{
				s.push(strToInt(tokens[i]));
			}
			else{
				char op = tokens[i][0];
				switch (op)
				{
					int op1, op2;
				case '+':
					op1 = s.top();
					s.pop();
					op2 = s.top();
					s.pop();
					s.push(op2 + op1);
					break;
				case '-':
					op1 = s.top();
					s.pop();
					op2 = s.top();
					s.pop();
					s.push(op2 - op1);
					break;
				case '*':
					op1 = s.top();
					s.pop();
					op2 = s.top();
					s.pop();
					s.push(op2 * op1);
					break;
				case '/':
					op1 = s.top();
					s.pop();
					op2 = s.top();
					s.pop();
					s.push(op2 / op1);
					break;
				default:
					break;
				}//switch
			}//else
		}//for
		return s.top();

	}

	//判断是否为运算符
	bool isOper(string &str)
	{
		if (str.size() > 1)
			return false;

		if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
			return true;
		return false;
	}

	//将字符串转换为整数
	int strToInt(string &str)
	{
		if (str.empty())
			return 0;

		//	求字符串长度
		int size = str.size();

		int flag = 1, pos = 0, sum = 0, multi = 1;
		if (str[0] == '-')
		{
			flag = -1;
			pos = 1;
		}

		for (int i = size - 1; i >= pos; --i)
		{
			sum += (str[i] - '0') * multi;
			multi *= 10;
		}

		return flag * sum;
	}
};

int main()
{
	vector<string> v = { "4", "13", "5", "/", "+"};
	Solution s;
	cout << s.evalRPN(v) << endl;

	system("pause");
	return 0;
}
