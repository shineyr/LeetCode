#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		if (n <= 0)
			return 0;
		//保存[1,n]每个值对应的二叉查找树个数
		vector<int> nums(n+1, 0);

		//空子树也算一颗
		nums[0] = 1;

		for (int r = 1; r <= n; ++r)
		{
			//当 n == 1 或者 n == 2时，满足要求的树的个数为n
			if (r <= 2)
			{
				nums[r] = r;
				continue;
			}//if

			//对于 [1 , r]之间的每个元素都可作为根节点
			for (int i = 1; i <= r; i++)
			{
				//此时能构成的二叉查找树个数 = [1,i-1]构成的左子树数目 * [i+1 , r]构成的右子树数目
				int lefts = nums[i - 1];

				//[i+1 , r]为连续的 r-i 个元素，所构成的树数目等于元素[1 , r-i]构成的数目
				int rights = nums[r - i];

				//
				nums[r] += lefts * rights;
			}//for
		}//for
		return nums[n];
	}
};

int main(){
	Solution s;
	int c = s.numTrees(3);
	cout << c << endl;

	system("pause");
	return 0;
}