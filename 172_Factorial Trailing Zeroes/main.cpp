#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int count = 0;
		while (n)
		{
			count += n / 5;
			n /= 5;
		}
		return count;
	}
};

int main()
{
	Solution s;
	cout << s.trailingZeroes(5) << endl;

	system("pause");
	return 0;
}