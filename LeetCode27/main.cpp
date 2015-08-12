#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0 , k = 0;
		while (i < nums.size())
		{
			if (nums[i] != val)
				nums[k++] = nums[i];
			i++;
		}
		return k;
	}
};

int main()
{
	int arr[10] = { 1, 2, 5, 5, 6, 23, 5, 6, 7, 10 };
	vector<int> v(arr, arr + 10);
	Solution *s = new Solution();
	int len = s->removeElement(v , 5);

	for (int i = 0; i < len; i++)
		cout << v[i] << "\t";

	cout << endl;

	system("pause");
	return 0;

}
