#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	//方法一，一次遍历 TLE
	int rangeBitwiseAnd1(int m, int n) {
		
		int ret = m;
		for (int i = m+1; i <= n; ++i)
		{
			ret = ret & i;
		}//for
		return ret;
	}

	//方法二，采用递归，TLE again！
	int rangeBitwiseAnd2(int m, int n) {
		if (m == n)
			return m;

		int mid = (m + n) / 2;
		return rangeBitwiseAnd(m, mid) & rangeBitwiseAnd(mid + 1, n);
	}

	//方法三：
	int rangeBitwiseAnd(int m, int n) {
		int offset = 0;
		while (m && n)
		{
			//找到最高相同位
			if (m == n)
			{
				return m << offset;
			}
			m >>= 1;
			n >>= 1;
			offset++;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	cout << s.rangeBitwiseAnd(5, 7) << endl;

	system("pause");
	return 0;
}