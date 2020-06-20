/**
 * https://leetcode.com/problems/remove-element/submissions/
 * 27. Remove Element
 */
public class NO_27 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_27().solution.removeElement(new int[]{0,1,2,2,3,0,4,2}, 2));
    }

    class Solution {

        // Two pointers
        public int removeElement(int[] nums, int val) {
            int i = 0, j = 0;
            while (j < nums.length) {
                if (nums[j] != val) {
                    nums[i] = nums[j];
                    ++i;
                }

                ++j;
            }
            return i;
        }
    }
}
