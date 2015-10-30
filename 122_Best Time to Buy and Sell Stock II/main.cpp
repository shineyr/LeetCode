#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		int sum = 0;
		//只要后项比前项大，这部分值就一定可以变为利润
		for (size_t i = 1; i < prices.size(); ++i)
		{
			if (prices[i] > prices[i - 1])
				sum += (prices[i] - prices[i - 1]);
		}
		return sum;
	}
};

int main()
{
	vector<int> v = { 2, 1, 3, 5, 4, 7 };
	Solution s;
	cout << s.maxProfit(v) << endl;

	system("pause");
	return 0;
}