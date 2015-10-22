#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*利用算法库的排序实现，复杂度为O(nlogn)*/
	//int singleNumber(vector<int>& nums) {
	//	if (nums.empty())
	//		return -1;
	//	sort(nums.begin(), nums.end());
	//	
	//	int size = nums.size();

	//	for (int i = 0; i < size - 1; i += 2)
	//	{
	//		if (nums[i] != nums[i + 1])
	//		{
	//			return nums[i];
	//		}//if
	//	}//for
	//	return nums[size - 1];
	//}

	/*利用异或运算实现，复杂度为O(n) a^b = b^a ; a^a = 0 ; 0^a = a^0 = a*/
	int singleNumber(vector<int>& nums) {
		if (nums.empty())
			return -1;
		int ret = 0 , size = nums.size();
		for (int i = 0; i < size; ++i)
			ret = ret ^ nums[i];
		return ret;
	}

};

int main()
{
	Solution s;
	vector<int> v = { 2, 3, 4, 3, 2 };

	cout << s.singleNumber(v) << endl;

	system("pause");
	return 0;
}