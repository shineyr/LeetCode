/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * 81. Search in Rotated Sorted Array II
 */
public class NO_81 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_81().solution.search(new int[] {1, 3, 1, 1, 1}, 3));
    }

    class Solution {
        public boolean search(int[] nums, int target) {
            int left = 0, right = nums.length - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] == target) {
                    return true;
                }

                if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                    ++left;
                    --right;
                } else if (nums[left] <= nums[mid]) {
                    if (nums[left] <= target && nums[mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    if (nums[mid] < target && nums[right] >= target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }

            return false;
        }
    }
}
