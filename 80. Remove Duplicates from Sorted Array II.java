/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * 80. Remove Duplicates from Sorted Array II
 */
public class NO_80 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_80().solution.removeDuplicates(new int[] {0,0,1,1,1,1,2,3,3}));
    }

    class Solution {
        public int removeDuplicates(int[] nums) {
            int idx = 0, dup = 0;

            for(int i=0; i<nums.length; ++i) {
                if (i == 0) {
                    nums[idx++] = nums[i];
                    dup = 1;
                    continue;
                }

                if (nums[i] == nums[i-1]) {
                    if (dup < 2) {
                        nums[idx++] = nums[i];
                        ++dup;
                    }
                } else {
                    nums[idx++] = nums[i];
                    dup = 1;
                }
            }

            return idx;
        }
    }
}
