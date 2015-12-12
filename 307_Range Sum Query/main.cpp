#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//普通方法实现
class NumArray1 {
public:
	NumArray1(vector<int> &nums) {
		array = vector<int>(nums.begin(), nums.end());
		int len = array.size(), tmpSum = 0;
		for (int i = 0; i < len; ++i)
		{
			tmpSum += array[i];
			allSum.push_back(tmpSum);
		}//for
	}

	void update(int i, int val) {
		if (i < 0 || i >= array.size())
			return;
		int tmp = val - array[i];
		array[i] = val;
		for (; i < array.size(); ++i)
			allSum[i] += tmp;		
	}

	int sumRange(int i, int j) {
		if (i < 0 || i >= array.size() || j<0 || j >= array.size() || i>j)
			return 0;
		if (0 == i)
			return allSum[j];
		else
			return allSum[j] - allSum[i - 1];
	}

private:
	vector<int> array;
	vector<int> allSum;
};

//树状数组实现
class NumArray {
private:
	vector<int> c;
	vector<int> m_nums;
public:
	NumArray(vector<int> &nums) {
		c.resize(nums.size() + 1);
		m_nums = nums;
		for (int i = 0; i < nums.size(); i++){
			add(i + 1, nums[i]);
		}
	}

	int lowbit(int pos){
		return pos&(-pos);
	}

	void add(int pos, int value){
		while (pos < c.size()){
			c[pos] += value;
			pos += lowbit(pos);
		}
	}
	int sum(int pos){
		int res = 0;
		while (pos > 0){
			res += c[pos];
			pos -= lowbit(pos);
		}
		return res;
	}

	void update(int i, int val) {
		int ori = m_nums[i];
		int delta = val - ori;
		m_nums[i] = val;
		add(i + 1, delta);
	}

	int sumRange(int i, int j) {
		return sum(j + 1) - sum(i);
	}
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
//
int main()
{
	vector<int> v = { 1, 3, 5 };
	NumArray numArray(v);

	cout << numArray.sumRange(0, 2) << endl;

	numArray.update(1, 2);

	cout << numArray.sumRange(0, 2) << endl;

	system("pause");
	return 0;
}