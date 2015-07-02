#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> index;
		map<int, int> hashMap;
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			if (!hashMap.count(numbers[i]))
				hashMap.insert(make_pair(numbers[i], i));
			if (hashMap.count(target - numbers[i]))
			{
				int pos = hashMap[target - numbers[i]];
				if (pos < i)
				{
					index.push_back(pos + 1);
					index.push_back(i + 1);
				}
			}//if
		}//for
		return index;
	}//twoSum
};

int main()
{
	Solution s;
	int arr[3] = { 3, 2, 4 };
	int target = 6;
	vector<int> numbers(arr, arr + 3);
	vector<int> index;
	index = s.twoSum(numbers, target);

	cout << "index1=" << index[0] << ", index2=" << index[1] << endl;

	system("pause");
	return 0;
}
