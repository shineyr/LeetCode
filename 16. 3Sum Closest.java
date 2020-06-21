/**
 * https://leetcode.com/problems/3sum-closest/
 * 16. 3Sum Closest
 */

import java.util.Arrays;

public class NO_16 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_16().solution.threeSumClosest(new int[]{-1, 2, 1, -4}, 1));
    }

    class Solution {

        // Two pointers
        public int threeSumClosest(int[] nums, int target) {
            int diff = Integer.MAX_VALUE, len = nums.length;

            Arrays.sort(nums);

            for(int i = 0; i < len && diff != 0; ++i) {
                int low = i + 1, high = len - 1;
                while (low < high) {
                    int sum = nums[i] + nums[low] + nums[high];

                    if (sum < target) {
                        low += 1;
                    } else {
                        high -= 1;
                    }

                    if (Math.abs(target - sum) < Math.abs(diff)) {
                        diff = target - sum;
                    }
                }
            }

            return target - diff;
        }


    }
}
