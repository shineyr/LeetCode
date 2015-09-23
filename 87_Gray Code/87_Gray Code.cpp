#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		//n位构成的二进制序列值为0~2^n-1

		if (n == 0)
			return vector<int>(1,0);
		//1左移n位 得到2^n
		int size = 1 << n;

		vector<int> ret;
		
		for (int i = 0; i < size; i++)
		{
			ret.push_back(i ^ (i >> 1));
		}

		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> v = s.grayCode(0);

	typedef vector<int>::iterator iter;

	for (iter i = v.begin(); i != v.end(); i++)
		cout << *i << endl;

	system("pause");
	return 0;
}