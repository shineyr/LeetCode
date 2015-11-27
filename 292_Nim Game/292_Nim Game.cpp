#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		if (n % 4 == 0)
			return false;
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.canWinNim(4) << endl;

	system("pause");
	return 0;
}

