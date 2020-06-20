/**
 * https://leetcode.com/problems/search-insert-position/
 * 35. Search Insert Position
 */
public class NO_35 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_35().solution.searchInsert(new int[]{1,3,5,6}, 0));
    }

    class Solution {
        public int searchInsert(int[] nums, int target) {
            int left = 0, right = nums.length - 1;

            while (left <= right) {
                int mid = (right - left) / 2 + left;

                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            return left;
        }
    }
}
