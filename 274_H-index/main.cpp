#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty())
			return 0;
		//对所给序列排序
		sort(citations.begin(), citations.end());

		int len = citations.size(),maxH = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			int h = len - i;
			if (citations[i] >= h && h > maxH)
			{
				maxH = h;
			}
			else{
				break;
			}
		}//for
		return maxH;
	}
};

int main()
{
	vector<int> v = { 3, 0, 6, 1, 5 };
	Solution s;
	
	cout << s.hIndex(v) << endl;

	system("pause");
	return 0;
}