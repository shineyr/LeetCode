import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * 1297. Maximum Number of Occurrences of a Substring
 *
 * https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
 *
 * Given a string s, return the maximum number of ocurrences of any substring under the following rules:
 *
 *     The number of unique characters in the substring must be less than or equal to maxLetters.
 *     The substring size must be between minSize and maxSize inclusive.
 */
public class NO_1297 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_1297().solution.maxFreq("aababcaab", 2, 3,4));

        System.out.println(new NO_1297().solution.maxFreq("aaaa", 1, 3,3));

    }

    class Solution {
        public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
            Map<String, Integer> subStrMap = new HashMap<>();
            Set<Character> uniqueChars = new HashSet<>();
            int max = 0;

            // If substring is longer, the more characters it contains is more. Therefore, we just need to check substrings with length minSize.
            for (int i=0; i<s.length() - minSize + 1; ++i) {
                uniqueChars.clear();
                for (int j=i; j< i + minSize; ++j) {
                    uniqueChars.add(s.charAt(j));
                }

                if (uniqueChars.size() <= maxLetters) {
                    String subStr = s.substring(i, i+minSize);
                    int count = subStrMap.getOrDefault(subStr, 0);
                    subStrMap.put(subStr, ++count);

                    max = Math.max(max, subStrMap.get(subStr));
                }
            }

            return max;
        }
    }
}
