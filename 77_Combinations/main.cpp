#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {	

		if (n <= 0 || n < k)
			return vector<vector<int>>();

		//保存结果
		vector<vector<int>> ret;
		if (k == 1)
		{
			for (int i = 1; i <= n; i++)
			{
				vector<int> v(1,i);
				ret.push_back(v);
			}//for

			return ret;
		}//if
		if (n == k)
		{
			vector<int> v;
			for (int i = 1; i <= n; i++)
			{
				v.push_back(i);
			}//for
			ret.push_back(v);

			return ret;
		}//if
		else{
			//由两部分组成，第一部分为 1~n-1 中k-1个数的组合，每个组合加入元素n
			vector<vector<int>> tmp = combine(n - 1, k - 1);
			int len = tmp.size();
			for (int i = 0; i < len; i++)
			{
				tmp[i].push_back(n);
				ret.push_back(tmp[i]);
			}//for

			//第二部分，1~n-1中 k个数的组合，两部分合并得到最终结果
			tmp = combine(n - 1, k);
			len = tmp.size();
			for (int i = 0; i < len; i++)
			{
				ret.push_back(tmp[i]);
			}//for

			return ret;
		}//else
	}
};

int main()
{
	Solution s;

	vector<vector<int> > v = s.combine(5, 3);
	int len = v.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << v[i][j] << "\t";
		}//for
		cout << endl;
	}

	system("pause");
	return 0;
}

