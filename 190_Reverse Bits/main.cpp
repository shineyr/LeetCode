#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
	//方法一
	uint32_t reverseBits(uint32_t n) {
		vector<int> bits;
		//利用位运算求二进制序列
		while (n)
		{
			bits.push_back(n & 1);
			n = n>> 1;
		}

		//求二进制位反转后对应的十进制数，若bits中长度不足32，以0步之
		uint32_t ret = 0;
		int size = bits.size();
		for (int i = 0 ; i <size; ++i)
		{
			ret = ret + bits[i] * (1 << (32 - i - 1));
		}//for
		return ret;

	}

	//简洁的解法2
	uint32_t reverseBits2(uint32_t n) {
         uint32_t res = 0;
         for (int i = 0; i < 32; ++i) {
             res |= (((n >> i) & 1) << (31 - i));

		}
         return res;
	}
};

int main()
{
	uint32_t u = 43261596;
	Solution s;
	cout << s.reverseBits2(u) << endl;

	system("pause");
	return 0;
}