import java.util.Arrays;

/**
 * 34. Find First and Last Position of Element in Sorted Array
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 */
public class NO_34 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new NO_34().solution.searchRange(new int[] {5,7,7,8,8,10}, 8)));
    }

    class Solution {
        public int[] searchRange(int[] nums, int target) {
            return new int[] {findFirstPos(nums, target), findLastPos(nums, target)};
        }

        public int findFirstPos(int[] nums, int target) {
            int left = 0, right = nums.length-1;

            while (left <= right) {
                int middle = left + (right - left) / 2;

                if (nums[middle] < target) {
                    left = middle + 1;
                } else if (nums[middle] > target) {
                    right = middle - 1;
                } else {
                    if (middle == 0) {
                        return middle;
                    } else if (nums[middle-1] == target){
                        right = middle - 1;
                    } else {
                        return middle;
                    }
                }
            }
            return -1;
        }


        public int findLastPos(int[] nums, int target) {
            int left = 0, right = nums.length-1;

            while (left <= right) {
                int middle = left + (right - left) / 2;

                if (nums[middle] < target) {
                    left = middle + 1;
                } else if (nums[middle] > target) {
                    right = middle - 1;
                } else {
                    if (middle == nums.length - 1) {
                        return middle;
                    } else if (nums[middle + 1] == target){
                        left = middle + 1;
                    } else {
                        return middle;
                    }
                }
            }
            return -1;
        }
    }
}
