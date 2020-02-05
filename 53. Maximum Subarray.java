
/**
 * 53. Maximum Subarray
 *
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 */
public class NO_53 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_53().solution.maxSubArray(new int[] {-2,1,-3,4,-1,2,1,-5,4}));
    }

    class Solution {
        public int maxSubArray(int[] nums) {

            int maxSum = Integer.MIN_VALUE, tempSum = 0;
            for (int i=0; i<nums.length; ++i) {
                tempSum += nums[i];

                if (tempSum > maxSum) {
                    maxSum = tempSum;
                }

                if (tempSum < 0) {
                    tempSum = 0;
                }
            }
            return maxSum;
        }
    }
}
