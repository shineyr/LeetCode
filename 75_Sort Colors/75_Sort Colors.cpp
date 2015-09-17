#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.empty())
			return;

		//初始化一个count数组，count[0] , count[1] , count[2] 分别记录nums中0 ， 1 ， 2出现个数
		vector<int> count(3, 0);

		vector<int>::iterator iter = nums.begin();

		for (; iter != nums.end(); iter++)
		{
			if (*iter == 0)
				count[0]++;
			else if (*iter == 1)
				count[1]++;
			else if (*iter == 2)
				count[2]++;
		}//for

		//对原数组排序
		int i = 0;
		while (i < count[0])
			nums[i++] = 0;
		while (i < (count[0] + count[1]))
			nums[i++] = 1;
		while (i < (count[0] + count[1] + count[2]))
			nums[i++] = 2;

		return;

	}
};

int main()
{
	Solution s;
	vector<int> v = { 0, 1, 1, 1, 2, 2, 2, 0, 0, 0, 1 };
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;

	s.sortColors(v);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;

	system("pause");
	return 0;
}