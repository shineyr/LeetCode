#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		if (n < 1)
			return -1;
		int lhs = 1, rhs = n;

		while (lhs < rhs)
		{
			int mid = lhs + (rhs - lhs) / 2;
			//找到bad version
			if (isBadVersion(mid))
			{
				rhs = mid;
			}
			//mid并不是bad version 则first bad肯定在右边
			else{
				lhs = mid + 1;
			}
		}//while
		return lhs;
	}
};
