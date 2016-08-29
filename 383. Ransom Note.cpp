#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int rL = ransomNote.length(), mL = magazine.length();

		vector<int> v(256, 0);
		for (int i = 0; i < mL; ++i)
		{
			++v[magazine[i]];
		}//for

		for (int i = 0; i < rL; ++i)
		{
			--v[ransomNote[i]];

			if (v[ransomNote[i]] < 0)
				return false;
		}//for

		return true;
	}
};

int main()
{
	cout << Solution().canConstruct("a", "b") << endl;

	system("pause");

	return 0;
}