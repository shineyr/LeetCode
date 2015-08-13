#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	//寻找整数序列num的下一个全排序列
	void nextPermutation(vector<int> &num) {
		if (num.size() < 2) return;

		int i, k;
		for (i = num.size() - 2; i >= 0; --i) 
			if (num[i] < num[i + 1]) 
				break;
		//若不存在子升序，则说明当前排列是最大排列，此时i = -1，下一排列即是最小排列，翻转整个序列即可
		if (i < 0)
		{
			reverse(num.begin() , num.end());
			return;
		}
		//找到了子升序
		for (k = num.size() - 1; i >= 0 && k > i ; --k)
			if (num[i] < num[k]) 
				break;
		if (i >= 0)
		{
			swap(num[i], num[k]);
			reverse(num.begin() + i + 1, num.end());
			return;
		}
	}
};

int  main()
{
	int arr[3] = { 3, 2, 1};
	vector<int> v(arr, arr + 3);

	Solution *s = new Solution();
	s->nextPermutation(v);

	for (int i = 0; i < 3; i++)
		cout << v[i] << "\t";
	cout << endl;
	system("pause");

	return 0;
}