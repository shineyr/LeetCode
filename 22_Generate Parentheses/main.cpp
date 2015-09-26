#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0)
			return vector<string>();

		vector<string > ret;

		dfs(ret, "", n, n);

		return ret;
	}

	//利用二叉树递归思想
	void dfs(vector<string> &ret, string tmp, int left, int right)
	{
		if (0 == left && 0 == right)
		{
			ret.push_back(tmp);
			return;
		}
		else if (left > 0)
			dfs(ret, tmp + '(', left - 1, right);
		
		if (left < right)
			dfs(ret, tmp + ')', left, right - 1);
	}


};

int main()
{
	Solution s;
	vector<string> v = s.generateParenthesis(3);

	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	system("pause");
	return 0;

}
