import java.util.HashSet;
import java.util.Set;

/**
 * 3. Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 */
public class NO_3 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_3().solution.lengthOfLongestSubstring2(""));
    }

    class Solution {
        public int lengthOfLongestSubstring3(String s) {
            int n = s.length();
            Set<Character> set = new HashSet<>();
            int ans = 0, i = 0, j = 0;
            while (i < n && j < n) {
                // try to extend the range [i, j]
                if (!set.contains(s.charAt(j))){
                    set.add(s.charAt(j++));
                    ans = Math.max(ans, j - i);
                }
                else {
                    set.remove(s.charAt(i++));
                }
            }
            return ans;
        }

        public int lengthOfLongestSubstring2(String s) {
            int maxLen = 0, curLen=0;

            int i = 0, j = i+1;
            while(i<s.length() && j<s.length()) {
                String subStr = s.substring(i, j);
                curLen = subStr.length();
                maxLen = Math.max(maxLen, curLen);

                if (!subStr.contains(String.valueOf(s.charAt(j)))) {
                    curLen++;
                    j++;
                } else {
                    while (s.charAt(i) != s.charAt(j)) {
                        i++;
                    }
                    i++;
                }

                maxLen = Math.max(maxLen, curLen);
            }

            if (i == s.length() - 1) {
                curLen = 1;
                maxLen = Math.max(maxLen, curLen);
            }

            return maxLen;
        }

        public int lengthOfLongestSubstring(String s) {
            int maxLen = 0, curLen=0;

            for (int i=0; i<s.length(); ++i) {
                curLen = 1;

                for(int j=i+1; j<s.length(); ++j) {
                    String subStr = s.substring(i,j);

                    if (subStr.contains(String.valueOf(s.charAt(j)))) {
                        maxLen = Math.max(maxLen, curLen);
                        break;
                    }

                    curLen++;
                    maxLen = Math.max(maxLen, curLen);
                }
            }

            maxLen = Math.max(maxLen, curLen);

            return maxLen;
        }
    }
}
