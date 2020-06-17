/**
 * https://leetcode.com/problems/reverse-integer/
 * 7. Reverse Integer
 */
public class NO_7 {
    Solution solution = new Solution();
    public static void main(String[] args) {
        System.out.println(new NO_7().solution.reverse(1534236469));
    }

    class Solution {
        public int reverse(int x) {
            int ret = 0;
            while(x != 0) {
                int digit = x % 10;
                x /= 10;

                // Check overflow
                if (ret > Integer.MAX_VALUE / 10 || ret < Integer.MIN_VALUE) {
                    return 0;
                }

                ret = ret * 10 + digit;
            }
            return ret;
        }

        public int reverse2(int x) {

            String values = String.valueOf(Math.abs(x));
            String reverseValues = new StringBuilder(values).reverse().toString();

            try {
                return x < 0 ? Integer.parseInt(reverseValues) * -1 : Integer.parseInt(reverseValues);
            } catch (NumberFormatException e) {
                return 0;
            }
        }
    }
}
