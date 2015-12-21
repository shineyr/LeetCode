#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*方法一：每个坐标点左右延伸（当高度降低停止延伸）构造矩形,但是大集合TLE*/
	int largestRectangleArea1(vector<int> &height) {
		if (height.empty())
			return 0;
		int maxArea = 0;
		int len = height.size();
		for (int i = 0; i < len; ++i)
		{
			/*记录包含第i个柱体的矩形面积*/
			int tmpArea = height[i];
			int left = i - 1, right = i + 1;
			/*左侧扩展*/
			while (left >= 0 && height[left] >= height[i])
			{
				tmpArea += height[i];
				--left;
			}//while
			/*右侧扩展*/
			while (right < len && height[right] >= height[i])
			{
				tmpArea += height[i];
				++right;
			}//while

			if (maxArea < tmpArea)
				maxArea = tmpArea;
		}//for

		return maxArea;
	}
	/*方法二：利用栈*/
	int largestRectangleArea(vector<int> &height) {
		if (height.empty())
			return 0;
		stack<int> stk;
		int len = height.size();
		int maxArea = 0;
		for (int i = 0; i < len; i++)
		{
			if (stk.empty() || stk.top() <= height[i])
				stk.push(height[i]);
			else
			{
				int count = 0;
				while (!stk.empty() && stk.top() > height[i])
				{
					count++;
					maxArea = max(maxArea, stk.top()*count);
					stk.pop();
				}
				while (count--)
					stk.push(height[i]);
				stk.push(height[i]);
			}//else
		}//for
		int count = 1;
		while (!stk.empty())
		{
			maxArea = max(maxArea, stk.top()*count);
			stk.pop();
			count++;
		}//while
		return maxArea;
	}
};

int main()
{
	vector<int> height{ 2, 1, 5, 6, 2, 3 };
	Solution s;

	cout << s.largestRectangleArea3(height) << endl; 

	system("pause");
	return 0;
}