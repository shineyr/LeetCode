/**
 * https://leetcode.com/problems/string-to-integer-atoi/
 * 8. String to Integer (atoi)
 */
public class NO_8 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_8().solution.myAtoi("-91283472332"));
    }

    class Solution {
        public int myAtoi(String str) {

            boolean positive  = true;
            int idx=0;
            while (idx < str.length()) {
                if (str.charAt(idx) == ' ') {
                    ++idx;
                } else if (str.charAt(idx) == '-') {
                    positive = false;
                    idx += 1;
                    break;
                } else if (str.charAt(idx) == '+') {
                    idx += 1;
                    break;
                } else if (str.charAt(idx) >= '0' && str.charAt(idx) <= '9') {
                    break;
                } else {
                    return 0;
                }
            }

            int ret = 0;
            while (idx < str.length() && (str.charAt(idx) >= '0' && str.charAt(idx) <= '9')) {
                int digit = str.charAt(idx) - '0';

                if (positive) {
                    if (ret > Integer.MAX_VALUE / 10 ||
                            (ret == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE - ret * 10)) {
                        return Integer.MAX_VALUE;
                    }
                } else {
                    if ((ret * -1) < Integer.MIN_VALUE / 10 ||
                            ((ret * -1) == Integer.MIN_VALUE / 10 && (digit * -1) < Integer.MIN_VALUE - ret * -10 )) {
                        return Integer.MIN_VALUE;
                    }
                }

                ret = ret * 10 + digit;

                ++idx;
            }

            return positive ? ret : ret * -1;
        }
    }
}
