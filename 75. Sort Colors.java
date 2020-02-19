import java.util.Arrays;

/**
 * 75. Sort Colors
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this problem.
 */
public class NO_75 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        new NO_75().solution.sortColors(new int[] {2,0,2,1,1,0});
    }

    class Solution {
        public void sortColors(int[] nums) {
            if (nums.length <= 0) {
                return;
            }

            int maxNum = nums[0];
            for (int i=0; i<nums.length; ++i) {
                maxNum = Math.max(maxNum, nums[i]);
            }

            int[] countOfNum = new int[maxNum+1];
            Arrays.fill(countOfNum, 0);

            for (int i=0; i<nums.length; ++i) {
                countOfNum[nums[i]]++;
            }

            int i=0, j=0;
            while (i < nums.length) {
                if (countOfNum[j] != 0) {
                    nums[i] = j;
                    countOfNum[j]--;

                    i++;
                } else {
                    j++;
                }
            }
        }
    }
}
