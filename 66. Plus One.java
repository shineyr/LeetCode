/**
 * https://leetcode.com/problems/plus-one/
 * 66. Plus One
 */

import java.util.Arrays;

public class NO_66 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new NO_66().solution.plusOne(new int[] {9, 9, 9})));
    }

    class Solution {
        public int[] plusOne(int[] digits) {
            int carry = 1;
            for (int i = digits.length - 1; i >= 0; --i) {
                int tmp = digits[i] + carry;

                if (tmp >= 10) {
                    digits[i] = tmp % 10;
                    carry = tmp / 10;
                } else {
                    digits[i] = tmp;
                    carry = 0;
                    break;
                }
            }

            if (carry != 0) {
                int[] ret = new int[digits.length + 1];
                ret[0] = carry;

                System.arraycopy(digits, 0, ret, 1, digits.length);
                return ret;
            }

            return digits;
        }
    }
}
