#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	/*方法一：动态规划方式*/
	vector<string> restoreIpAddresses(string s) {
		if (s.empty())
			return vector<string>();

		return getIpAddresses(s, 4);
	}

	/*s为需要划分的字符串，num为需要划分段数*/
	vector<string> getIpAddresses(string s, int num)
	{
		int len = s.length();
		if (s.empty() || num <= 0 || len > 3 * num || len < num)
			return vector<string>();
		vector<string> ips;
		if (num == 1)
		{
			if (isLegal(s))
				ips.push_back(s);
			return ips;
		}//if
		else{
			//得到首段，每段ip长度不超过3
			for (int i = 0; i < len && i < 3; ++i)
			{
				string ip1 = s.substr(0, i + 1);
				if (isLegal(ip1))
				{
					vector<string> tmpIps = getIpAddresses(s.substr(i + 1), num - 1);
					if (!tmpIps.empty())
					{
						auto iter = tmpIps.begin();
						while (iter != tmpIps.end())
						{
							string ip = ip1 + "." + *iter;
							ips.push_back(ip);
							++iter;
						}//while
					}//if
				}//if
			}//for
			return ips;
		}
	}
		
	/*判断ip段是否合法*/
	bool isLegal(string ip)
	{
		if (ip.empty())
			return false;
		else if (ip[0] == '0')
			return ip.length() == 1;
		else{
			int pos = ip.length() - 1;
			int sum = 0 , tmp = 1;
			while (pos >= 0)
			{
				sum = sum + (ip[pos] - '0') * tmp;
				if (sum > 255)
					return false;
				tmp *= 10;
				--pos;
			}//while
		}//else
		return true;
	}

	/*方法二：三重循环，效率低*/
	vector<string> restoreIpAddresses2(string s) {
		vector<string> ips;
		if (s.empty())
			return vector<string>();

		int len = s.length();
		for (int i = 0; i < len - 2; ++i)
		{
			for (int j = i + 1; j < len - 1; ++j)
			{
				for (int k = j + 1; k < len; ++k)
				{
					string ip1 = s.substr(0, i + 1);
					string ip2 = s.substr(i + 1, j - i);
					string ip3 = s.substr(j + 1, k - j);
					string ip4 = s.substr(k + 1);
					if (isLegal(ip1) && isLegal(ip2) && isLegal(ip3) && isLegal(ip4))
						ips.push_back(ip1 + "." + ip2 + "." + ip3 + "." + ip4);
				}//for
			}//for
		}//for

		return ips;
	}
};

int main()
{
	Solution s;
	
	string str = "255255255255";
	vector<string> ips = s.restoreIpAddresses2(str);

	for (unsigned i = 0; i < ips.size(); ++i)
	{
		cout << ips[i] << endl;
	}//for

	system("pause");
	return 0;
}
