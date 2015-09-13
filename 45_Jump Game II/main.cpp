#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

////贪心算法
//class Solution {
//public:
//	int jump(vector<int>& nums){
//		if (nums.empty() || nums.size() == 1)
//			return 0;
//		
//		int len = nums.size();
//		
//		//记录当前可走的最大步长
//		int maxStep = nums[0];		
//		
//		//记录当前走的步数
//		int steps = 0;
//		for (int i = 1; i < len; ++i)
//		{
//			if (maxStep <= 0)
//				return -1;
//			//若此时步长大于剩余步数
//			else if (maxStep >= (len - i))
//				return steps+1;
//			else{
//				maxStep = max(--maxStep, nums[i]);
//				steps++;
//			}//else
//		}//for
//
//		return steps;
//	}
//};

class Solution {
public:
	int jump(vector<int>& nums) {
	
		//ret:目前为止的jump数
		int ret = 0;
		
		//curMax:从0~i这i+1个A元素中能达到的最大范围	
	
		int curMax = 0;
		//curRch:从nums[0]进行ret次jump之后达到的最大范围
		int curRch = 0;
		
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			//当curRch < i，说明ret次jump已经不足以覆盖当前第i个元素，因此需要增加一次jump，使之达到记录的curMax。
			if (curRch < i)
			{
				ret++;
				curRch = curMax;
			}
			curMax = max(curMax, nums[i] + i);
		}
		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> v1 = { 1, 2, 1, 1, 1 };
	vector<int> v2 = { 1 };
	int ret = s.jump(v1);

	cout << ret << endl;

	system("pause");
	return 0;

}