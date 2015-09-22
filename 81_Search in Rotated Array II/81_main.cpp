class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty())
			return false;

		//求所给序列的长度
		int len = nums.size();

		int lhs = 0, rhs = len - 1;
		while (lhs <= rhs)
		{
			//右移一位减半，提升效能
			int mid = (lhs + rhs) >> 1;
			if (target == nums[mid])
				return true;

			//若左侧、中间、右侧值相等 则左右同时内移一位
			if (nums[lhs] == nums[mid] && nums[mid] == nums[rhs])
			{
				lhs++;
				rhs--;
			}//if
			else if (nums[lhs] <= nums[mid])
			{
				if (nums[lhs] <= target && target < nums[mid])
				{
					rhs = mid - 1;
				}
				else{
					lhs = mid + 1;
				}//else
			}//elif
			else{
				if (nums[mid] < target && target <= nums[rhs])
				{
					lhs = mid + 1;
				}//if
				else{
					rhs = mid - 1;
				}//else
			}//else
		}//while
		return false;
	}
};