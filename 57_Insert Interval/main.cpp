#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
struct Interval{
	int start;
	int end;
	Interval() :start(0), end(0){}
	Interval(int s, int e) : start(s), end(e){}
};

//自定义Interval类型元素的升序比较函数
bool cmp(Interval a, Interval b)
{
	return a.start < b.start;
}

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		//如果输入参数为空，则返回空vector
		if (intervals.empty())
			return vector<Interval>(1 , newInterval);

		//将新元素插入序列中
		intervals.push_back(newInterval);
		
		int len = intervals.size();
		//首先，按照每个Integerval的区间首值进行排序，自定义比较
		sort(intervals.begin(), intervals.end(), cmp);

		//声明结果
		vector<Interval> ret;

		//定义临时变量
		Interval temp = intervals[0];

		for (int i = 0; i < len; i++)
		{
			//换一种判断方法
			if (intervals[i].start > temp.end)
			{
				ret.push_back(temp);
				temp = intervals[i];
			}
			else{
				temp.end = temp.end > intervals[i].end ? temp.end : intervals[i].end;
			}//else

		}//for
		ret.push_back(temp);
		return ret;
	}
};


int main()
{
	Solution s;

	//[1,3],[2,6],[8,10],[15,18]
	vector<Interval> v{ Interval(1, 3), Interval(6, 9), Interval(8, 10), Interval(15, 18) };

	vector<Interval> ret = s.insert(v , Interval(2,5));
	vector<Interval>::iterator iter = ret.begin();

	for (; iter != ret.end(); iter++)
	{
		cout << "[" << (*iter).start << " , " << (*iter).end << "]" << "\t";
	}//for

	cout << endl;

	system("pause");

	return 0;
}