
/**
 * 930. Binary Sub-arrays With Sum
 *
 * https://leetcode.com/problems/binary-subarrays-with-sum/
 *
 * In an array A of 0s and 1s, how many non-empty sub-arrays have sum S?
 */
public class NO_930 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_930().solution.numSubArraysWithSum(new int[]{1,0,1,0,1}, 2));

        System.out.println(new NO_930().solution.numSubArraysWithSum(new int[]{0,0,0,0,0}, 0));

    }

    class Solution {
        public int numSubArraysWithSum(int[] A, int S) {
            int[] preSum = new int[A.length + 1];

            for(int i = 0; i < A.length; i++) {
                preSum[i + 1] = preSum[i] + A[i];
            }

            int totalCount = 0;
            for(int i = 1; i <= A.length; i++) {
                for(int j = 0; j < i; j++) {
                    if(preSum[i] - preSum[j] == S) {
                        totalCount++;
                    }
                }
            }
            return totalCount;
        }
    }
}
