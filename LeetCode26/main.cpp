#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1)
			return nums.size();
		
		int i = 0, j = 1;
		while (j < nums.size())
		{
			if (nums[i] == nums[j])
			{
				++j;
			}
			else
			{
				nums[++i] = nums[j++];
			}
		}
		return i + 1;
	}
};

int main()
{
	int arr[3] = { 1, 2 , 2};
	vector<int> v(arr, arr +3);

	Solution *s = new Solution();
	int len = s->removeDuplicates(v);
	cout << len << endl;
	for (int i = 0; i < len; i++)
		cout << v[i] << "\t";
	system("pause");

	return 0;

}