/**
 * 4. Median of Two Sorted Arrays
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 */
public class NO_4 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_4().solution.findMedianSortedArrays(new int[]{1, 2}, new int[] {3, 4}));
    }

    class Solution {
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            int[] nums = new int[nums1.length + nums2.length];

            int i=0, j=0, k=0;
            while(i<nums1.length && j<nums2.length) {
                if (nums1[i] <= nums2[j]) {
                    nums[k++] = nums1[i++];
                } else {
                    nums[k++] = nums2[j++];
                }
            }

            while (i < nums1.length) {
                nums[k++] = nums1[i++];
            }

            while (j < nums2.length) {
                nums[k++] = nums2[j++];
            }

            if (nums.length % 2 != 0) {
                return (double) nums[nums.length/2];
            } else {
                return (double)(nums[nums.length/2-1] + nums[nums.length/2]) / 2;
            }
        }
    }

}
