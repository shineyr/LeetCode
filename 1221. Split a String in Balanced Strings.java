/**
 * 1221. Split a String in Balanced Strings
 *
 * Balanced strings are those who have equal quantity of 'L' and 'R' characters.
 *
 * Given a balanced string s split it in the maximum amount of balanced strings.
 *
 * Return the maximum amount of splitted balanced strings.
 */

public class NO_1221 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_1221().solution.balancedStringSplit("RLRRLLRLRL"));

        System.out.println(new NO_1221().solution.balancedStringSplit("RLLLLRRRLR"));

        System.out.println(new NO_1221().solution.balancedStringSplit("LLLLRRRR"));

    }

    class Solution {
        public int balancedStringSplit(String s) {
            int totalCount = 0, lCount = 0, rCount = 0;

            for (int i=0; i<s.length(); ++i) {
                if (s.charAt(i) == 'L') {
                    ++lCount;
                } else {
                    ++rCount;
                }

                if (lCount == rCount) {
                    ++totalCount;
                    lCount = 0;
                    rCount = 0;
                }
            }

            return totalCount;
        }
    }
}
