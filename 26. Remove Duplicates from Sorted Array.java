/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/solution/
 * 26. Remove Duplicates from Sorted Array
 */
public class NO_26 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_26().solution.removeDuplicates(new int[] {1,1,2}));
    }

    class Solution {
        public int removeDuplicates(int[] nums) {
            int len = nums.length;

            if(len <= 1) {
                return len;
            }

            int count = 1, idx = 1;
            while (idx < len) {
                if (nums[idx] != nums[idx-1]) {
                    nums[count] = nums[idx];
                    ++count;
                }
                ++idx;
            }

            return count;
        }
    }
}
