/**
 * 5. Longest Palindromic Substring
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 */
public class NO_5 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_5().solution.longestPalindrome("babad"));
        System.out.println(new NO_5().solution.longestPalindrome("cbbd"));
    }

    private class Solution {
        public String longestPalindrome(String s) {

            int maxPalindromeLen = 0;
            String maxPalindrome = "";
            for (int i=0; i<s.length(); ++i) {

                // 以元素s[i]为中心的回文串
                String oddPalindrome = getMaxPalindrome(s, i, i);

                if (oddPalindrome.length() > maxPalindromeLen) {
                    maxPalindromeLen = oddPalindrome.length();
                    maxPalindrome = oddPalindrome;
                }

                // 以元素s[i], s[i+1]为中心的回文串
                String evenPalindrome = getMaxPalindrome(s, i, i+1);
                if (evenPalindrome.length() > maxPalindromeLen) {
                    maxPalindromeLen = evenPalindrome.length();
                    maxPalindrome = evenPalindrome;
                }
            }
            return maxPalindrome;
        }

        private String getMaxPalindrome(String s, int lIdx, int rIdx) {
            Boolean find = false;

            while (lIdx >= 0 && rIdx < s.length()) {
                if (s.charAt(lIdx) == s.charAt(rIdx)) {
                    --lIdx;
                    ++rIdx;
                    find = true;
                } else {
                    return s.substring(lIdx + 1, rIdx);
                }
            }

            if (find) {
                return s.substring(lIdx + 1, rIdx);
            }

            return "";
        }

        /**
         * Brute Force
         */
        public String longestPalindrome1(String s) {

            int maxPalindromeLen = 0;
            String maxPalindrome = "";
            for (int i=0; i<s.length() - maxPalindromeLen; ++i) {
                for (int j=i+1; j<=s.length(); ++j) {
                    String subStr = s.substring(i, j);
                    if (isPalindrome(subStr) && subStr.length() > maxPalindromeLen) {
                        maxPalindromeLen = subStr.length();
                        maxPalindrome = subStr;
                    }
                }
            }
            return maxPalindrome;
        }

        private boolean isPalindrome(String s) {
            for (int i=0, j=s.length()-1; i<j; ++i, --j) {
                if (s.charAt(i) != s.charAt(j)) {
                    return false;
                }
            }
            return true;
        }
    }

}
