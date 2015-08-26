#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n <= 0)
			return NULL;

		//n=1时，结果为"1"
		string ret = "1";
		if (n == 1)
			return ret;
		else
		{
			for (int i = 2; i <= n; i++)
				ret = Count(ret);
		}//else
		return ret;
		
	}

	string Count(const string &str)
	{
		int size = strlen(str.c_str());
		//保存结果
		stringstream ret;
		//保存标识字符
		char flag = str[0];
		//计算标识字符的出现次数
		int count = 0 , i = 0;
		while( i < size )
		{
			//临时循环位
			int pos = i;
			while (str[pos] == flag)
			{
				count++;
				pos++;
			}//while
			ret << count << flag;
			flag = str[pos];
			count = 0;
			//设置下一个循环位
			i = pos;
		}//for
		return ret.str();
	}
};

int main()
{
	Solution s;
	for (int i = 1; i <= 10; i++)
		cout <<"n = "<<i<<"   say: "<< s.countAndSay(i) << endl;

	system("pause");
	return 0;
}