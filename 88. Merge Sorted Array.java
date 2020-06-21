/**
 * https://leetcode.com/problems/merge-sorted-array/
 * 88. Merge Sorted Array
 */

import java.util.Arrays;

public class NO_88 {
    Solution solution = new Solution();

    public static void main(String args[]) {
        int[] nums1 = new int[] {1,2,3,0,0,0};
        int[] nums2 = new int[] {2,5,6};

        new NO_88().solution.merge(nums1, 3, nums2, 3);

        System.out.println(Arrays.toString(nums1));
    }
    class Solution {
        public void merge(int[] nums1, int m, int[] nums2, int n) {

            int i = m - 1, j = n - 1, k = m + n - 1;

            while (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                } else {
                    nums1[k--] = nums2[j--];
                }
            }

            while (i >= 0) {
                nums1[k--] = nums1[i--];
            }

            while (j >= 0) {
                nums1[k--] = nums2[j--];
            }
        }
    }
}
