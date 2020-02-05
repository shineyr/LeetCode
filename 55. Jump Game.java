/**
 * 55. Jump Game
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 */
public class NO_55 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_55().solution.canJump(new int[]{0, 1, 1, 1}));
    }


    private class Solution {
        public boolean canJump(int[] nums) {
            int[] maxJump = new int[nums.length];

            maxJump[0] = nums[0];
            for (int i=1; i<nums.length; ++i) {
                if (maxJump[i-1] < i) {
                    return false;
                }

                maxJump[i] = Math.max(maxJump[i-1], i + nums[i]);
            }

            return maxJump[nums.length - 1] > nums.length - 1;
        }
    }
}
