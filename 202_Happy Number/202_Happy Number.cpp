#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0)
			return false;
		
		if (n == 1)
			return true;
		int sum = n;
		while (sum != 1)
		{
			int tmp = sum;
			sum = 0;
			//求各个位平方和
			while (tmp != 0)
			{
				sum += pow(tmp % 10, 2);
				tmp /= 10;
			}//while

			if (sum == n || sum == 4)
				return false;
		}//while

		if (sum == 1)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;
	int n = 2;

	if (s.isHappy(n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	system("pause");
	return 0;
}