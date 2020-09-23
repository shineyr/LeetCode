/**
 * 55. Jump Game
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 */
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length <= 1) {
            return true;
        }

        int farthest = nums[0];

        for (int i = 1; i < nums.length; ++i) {
            if (farthest < i) {
                return false;
            }

            farthest = Math.max(farthest, i + nums[i]);
        }

        return farthest >= nums.length - 1;
    }

    public boolean canJump2(int[] nums) {
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

    public boolean canJump1(int[] nums) {
        int lastPos = nums.length - 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
}
