/**
 * 1295. Find Numbers with Even Number of Digits
 *
 * Given an array nums of integers, return how many of them contain an even number of digits.
 */
public class NO_1295 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_1295().solution.findNumbers(new int[] {12,345,2,6,7896}));

        System.out.println(new NO_1295().solution.findNumbers(new int[] {555,901,482,1771}));

    }

    class Solution {
        public int findNumbers(int[] nums) {
            int count = 0;
            for (int num : nums) {
                if (numberOfDigits(num) % 2 == 0) {
                    ++count;
                }
            }

            return count;
        }

        private int numberOfDigits(int value) {
            int count = 1;

            while (value / 10 != 0) {
                ++count;

                value /= 10;
            }

            return count;
        }
    }
}
