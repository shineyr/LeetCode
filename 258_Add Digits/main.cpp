#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	//常规方法计算
	int addDigits1(int num) {
		if (num / 10 == 0)
			return num;
		
		while (num / 10 != 0)
		{
			//求出num的各个位数字之和
			int tmp = 0;
			while (num)
			{
				tmp += num % 10;
				num /= 10;
			}//while
			num = tmp;
		}//while
		return num;
	}
	//结果为：(num - 1) % 9 + 1
	int addDigits(int num) {
		return (num - 1) % 9 + 1;
	}

};

int main()
{
	Solution s;
	cout << s.addDigits(38) << endl;

	system("pause");
	return 0;
}
