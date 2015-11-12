
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if (gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size()) return -1;
		int total = 0, sum = 0, start = 0;
		for (int i = 0; i < gas.size(); ++i){
			total += (gas[i] - cost[i]);
			if (sum < 0){ //发现油箱空了，从下一个站点尝试
				sum = (gas[i] - cost[i]);
				start = i;
			}
			else
				sum += (gas[i] - cost[i]);
		}
		return total < 0 ? -1 : start; //用total判断start 是否是满足要求的解
	}
};

int main()
{

}