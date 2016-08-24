/*
371. Sum of Two Integers
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	//µÝ¹é½â¾ö
	int getSum1(int a, int b)
	{
		if (a != 0 && b != 0)
		{
			return getSum(a^b, (a&b) << 1);
		}
		else {
			return a | b;
		}//else
	}

	//·ÇµÝ¹é
	int getSum(int a, int b) {
		if (a != 0 && b != 0)
		{
			int sum = a;
			while (b != 0)
			{
				sum = a ^ b;
				b = (a & b) << 1;

				a = sum;
			}//while
			return sum;
		}
		else {
			return a | b;
		}//else
		
	}
};

int main()
{
	cout << Solution().getSum(10, 11) << endl;

	system("pause");
	return 0;
}