#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		if (s.empty())
			return 0;

		//求出所给表达式的长度
		int len = s.length();

		//操作符栈
		stack<char> op_stack;

		//操作数栈
		stack<int> num_stack;
		for (int i = 0; i < len; ++i)
		{
			//(1) 跳过空格
			if (s[i] == ' ')
				continue;

			//(2) 操作符入栈
			else if (s[i] == '(' || s[i] == '+' || s[i] == '-')
			{
				op_stack.push(s[i]);
				continue;
			}//elif
			
			//(3) 右括号
			else if (s[i] == ')')
			{
				while (op_stack.top() != '(')
				{
					//从数据栈弹出两个操作数
					int num2 = num_stack.top();
					num_stack.pop();
					int num1 = num_stack.top();
					num_stack.pop();

					//从符号栈，弹出操作符
					char op = op_stack.top();
					op_stack.pop();

					if (op == '+')
						num_stack.push(num1 + num2);
					else if (op == '-')
						num_stack.push(num1 - num2);
				}//while

				//弹出左括号
				op_stack.pop();		
				
				//此时查看操作数和操作符栈
				while (!op_stack.empty() && op_stack.top() != '(')
				{
					//从数据栈弹出两个操作数
					int num2 = num_stack.top();
					num_stack.pop();
					int num1 = num_stack.top();
					num_stack.pop();

					//从符号栈，弹出操作符
					char op = op_stack.top();
					op_stack.pop();

					if (op == '+')
						num_stack.push(num1 + num2);
					else if (op == '-')
						num_stack.push(num1 - num2);
				}//while
			}//elif
			else{
				int num = 0;
				while (i < len && isDigit(s[i]))
				{
					num = num * 10 + (s[i] - '0');
					i++;
				}//while
				//回退一个字符
				--i;
				num_stack.push(num);

				//此时查看操作数和操作符栈
				while (!op_stack.empty() && op_stack.top() != '(')
				{
					//从数据栈弹出两个操作数
					int num2 = num_stack.top();
					num_stack.pop();
					int num1 = num_stack.top();
					num_stack.pop();

					//从符号栈，弹出操作符
					char op = op_stack.top();
					op_stack.pop();

					if (op == '+')
						num_stack.push(num1 + num2);
					else if (op == '-')
						num_stack.push(num1 - num2);
				}//while
			}		
		}//for
		return num_stack.top();
	}

	//判断是否为数字
	bool isDigit(char c)
	{
		if (c >= '0' && c <= '9')
			return true;
		else
			return false;
	}
};

int main()
{
	string str = "(7)-(0)+(4)";
	Solution s;

	cout << s.calculate(str) << endl;

	system("pause");
	return 0;
}

