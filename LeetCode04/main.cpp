#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//方法一，采用merge的思想，将两个有序序列合并为一个有序序列，返回其中位数。T(n)=O(n)
//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//		//求两个有序序列的长度
//		int len1 = nums1.size(), len2 = nums2.size();
//
//		vector<int> nums(len1 + len2);
//
//		int i = 0, j = 0 , k=0;
//		while (i < len1&&j < len2)
//		{
//			if (nums1[i] <= nums2[j])
//			{
//				nums[k++] = nums1[i];
//				i++;
//			}
//			else{
//				nums[k++] = nums2[j];
//				j++;
//			}
//		}//while
//
//		while (i < len1)
//		{
//			nums[k++] = nums1[i];
//			i++;
//		}//while
//		
//		while (j < len2)
//		{
//			nums[k++] = nums2[j];
//			j++;
//		}//while
//
//		return (double)((len1 + len2) % 2 ? nums[(len1 + len2) / 2] : (nums[(len1 + len2 - 1) / 2] + nums[(len1 + len2) / 2]) / 2.0);
//	}
//};


//方法2：经典求第k小元素算法
class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int total = m + n;
		if (total & 0x1)
			return findKth(A, m, B, n, total / 2 + 1);
		else
			return (findKth(A, m, B, n, total / 2)
			+ findKth(A, m, B, n, total / 2 + 1)) / 2;
	}

	double findKth(int a[], int m, int b[], int n, int k)
	{
		//always assume that m is equal or smaller than n
		if (m > n)
			return findKth(b, n, a, m, k);
		if (m == 0)
			return b[k - 1];
		if (k == 1)
			return min(a[0], b[0]);
		//divide k into two parts
		int pa = min(k / 2, m), pb = k - pa;
		if (a[pa - 1] < b[pb - 1])
			return findKth(a + pa, m - pa, b, n, k - pa);
		else if (a[pa - 1] > b[pb - 1])
			return findKth(a, m, b + pb, n - pb, k - pb);
		else
			return a[pa - 1];
	}
};




int main()
{
	int arr1[] = { 1, 2, 3, 3, 4, 5, 6 };
	int arr2[] = { 2, 3, 4, 5, 6, 6, 7, 8 };
	vector<int> v1;
	vector<int> v2(arr2 , arr2+2);

	Solution s;
	cout << s.findMedianSortedArrays(arr1,7 ,  arr2 , 8) << endl;

	system("pause");
	return 0;
}