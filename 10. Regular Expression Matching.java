/**
 * https://leetcode.com/problems/regular-expression-matching/
 * 10. Regular Expression Matching
 */
public class NO_10 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_10().solution.isMatch("ab", ".*"));
    }

    class Solution {
        // Recursion
        public boolean isMatch(String s, String p) {
            if(p.isEmpty()) {
                return s.isEmpty();
            }

            boolean firstMatch = !s.isEmpty() && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.');

            if (p.length() >= 2 && p.charAt(1) == '*') {
                return isMatch(s, p.substring(2)) || (firstMatch && isMatch(s.substring(1), p));
            } else {
                return firstMatch && isMatch(s.substring(1), p.substring(1));
            }
        }
    }
}
