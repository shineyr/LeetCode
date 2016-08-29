#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		return (n & (n - 1)) == 0 ? true : false;
	}
};

int main()
{
	cout << Solution().isPowerOfTwo(2) << endl;

	system("pause");
	return 0;
}
