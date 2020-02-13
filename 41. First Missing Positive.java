/**
 * 41. First Missing Positive
 * Given an unsorted integer array, find the smallest missing positive integer.
 */
public class NO_41 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_41().solution.firstMissingPositive(new int[] {1,1}));
    }

    class Solution {
        public int firstMissingPositive(int[] nums) {
            for (int i=0; i<nums.length; ++i) {
                while (nums[i] != i+1) {
                    int cur = nums[i];
                    if (cur <= 0 || cur > nums.length) {
                        nums[i] = 0;
                        break;
                    }

                    if (nums[cur - 1] == cur) {
                        break;
                    }

                    nums[i] = nums[cur - 1];
                    nums[cur - 1] = cur;

                }
            }

            for (int i=0; i<nums.length; ++i) {
                if (nums[i] != i+1) {
                    return i+1;
                }
            }

            return nums.length + 1;
        }
    }
}
