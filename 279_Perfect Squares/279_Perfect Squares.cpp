#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	/* 如果一个数x可以表示为一个任意数a加上一个平方数bｘb，也就是x = a + bｘb，
	 * 那么能组成这个数x最少的平方数个数，就是能组成a最少的平方数个数加上1（因为b*b已经是平方数了）。
	 */
	int numSquares(int n) {
		// 将所有非平方数的结果置最大，保证之后比较的时候不被选中
		vector<int> nums(n + 1, INT_MAX);

		// 将所有整平方数的结果置1
		for (int i = 0; i*i <= n; ++i)
		{
			nums[i*i] = 1;
		}//for

		// 从小到大找任意数a
		for (int a = 0; a <= n; ++a)
		{
			// 从小到大找平方数b*b
			for (int b = 0; a + b*b <= n; ++b)
			{
				// 因为a+b*b可能本身就是平方数，所以我们要取两个中较小的
				nums[a + b*b] = min(nums[a] + 1, nums[a + b*b]);
			}//for
		}//for
		return nums[n];
	}
};

int main()
{
	Solution s;
	cout << s.numSquares(12) << endl;

	cout << s.numSquares(13) << endl;

	system("pause");
	return 0;
}