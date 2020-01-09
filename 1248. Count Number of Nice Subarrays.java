/**
 * 1248. Count Number of Nice Subarrays
 *
 * Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.
 *
 * Return the number of nice sub-arrays.
 */
public class NO_1248 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_1248().solution.numberOfSubArrays(new int[] {2,2,2,1,2,2,1,2,2,2}, 2));

        System.out.println(new NO_1248().solution.numberOfSubArrays(new int[] {1,1,2,1,1}, 3));

        System.out.println(new NO_1248().solution.numberOfSubArrays(new int[] {2,4,6}, 1));

    }

    class Solution {
        public int numberOfSubArrays(int[] nums, int k) {
            int len = nums.length;

            int[] odds = new int[len];
            int oddCount = 0;
            for (int idx=0; idx<len; ++idx) {
                if (nums[idx] % 2 != 0) {
                    odds[oddCount++] = idx;
                }
            }

            if (oddCount < k) {
                return 0;
            }

            int totalCount = 0;
            for (int i=0; i<oddCount-k+1; ++i) {
                // 包含k个奇数的子数组起始位置
                int left = odds[i];
                int right = odds[i+k-1];

                // 找到包含k个奇数的首尾为偶数的位置
                int firstPos = 0;
                int lastPos = len - 1;

                // 对于当前奇数不是第一个时
                if (i != 0) {
                    firstPos = odds[i-1] + 1;
                }

                // 第k个奇数不是最后一个时
                if (i+k-1 != oddCount-1) {
                    lastPos = odds[i+k] - 1;
                }

                int leftCount = left - firstPos;
                int rightCount = lastPos - right;
                totalCount += (leftCount + rightCount + 1 + (leftCount * rightCount));
            }

            return totalCount;
        }
    }
}
