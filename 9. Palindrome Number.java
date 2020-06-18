/**
 * https://leetcode.com/problems/palindrome-number/submissions/
 * 9. Palindrome Number
 */
public class NO_9 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_9().solution.isPalindrome(101));
    }

    class Solution {
        public boolean isPalindrome(int x) {
            if (x < 0 || (x % 10 == 0 && x != 0)) {
                return false;
            }

            // Reverse half of the number
            int reverseNum = 0;
            while (x > reverseNum) {
                reverseNum = reverseNum * 10 + x % 10;
                x /= 10;
            }

            // For the length of x, if it's odd x should be reverseNum / 10; if it's even x should be reverseNum
            return x == reverseNum || x == reverseNum / 10;
        }


        // Solution 2
        public boolean isPalindrome2(int x) {
            String str = String.valueOf(x);

            if (str.length() <= 1) {
                return true;
            }

            int left = 0, right = str.length() - 1;
            while (left < right) {
                if (str.charAt(left) != str.charAt(right)) {
                    return false;
                }

                ++left;
                --right;
            }

            return true;
        }
    }
}
