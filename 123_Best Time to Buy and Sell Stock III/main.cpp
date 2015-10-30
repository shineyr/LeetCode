#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		int n = prices.size();

		vector<int> profits(n, 0), profits_reverse(n,0);

		//正向遍历，profits[i]表示 prices[0...i]内做一次交易的最大收益.
		int low = prices[0] , cur_profit = 0;
		for (int i = 1; i < n; ++i)
		{
			if (prices[i] < low)
			{
				low = prices[i];
			}
			else{
				if (cur_profit < prices[i] - low)
					cur_profit = prices[i] - low;
			}
			profits[i] = cur_profit;
		}//for

		//逆向遍历, profits_reverse[i]表示 prices[i...n-1]内做一次交易的最大收益.
		//当前最大价格
		int high = prices[n - 1];
		cur_profit = 0;
		for (int i = n - 2; i >= 0; --i)
		{
			if (prices[i] > high)
				high = prices[i];
			else{
				if (cur_profit < high - prices[i])
					cur_profit = high - prices[i];
			}//else
			profits_reverse[i] = cur_profit;
		}

		int max_profile = 0;
		for (int i = 0; i < n; i++)
		{
			if ((profits[i] + profits_reverse[i]) > max_profile)
				max_profile = profits[i] + profits_reverse[i];
		}
		return max_profile;
	}
};
int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6 };
	Solution s;
	cout << s.maxProfit(v) << endl;

	system("pause");
	return 0;
}