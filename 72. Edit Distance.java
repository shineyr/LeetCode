/**
 * 72. Edit Distance
 *
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 *
 * You have the following 3 operations permitted on a word:
 *
 *     Insert a character
 *     Delete a character
 *     Replace a character
 */
public class NO_72 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_72().solution.minDistance("sea", "eat"));
    }

    class Solution {
        public int minDistance(String word1, String word2) {
            int m = word1.length(), n = word2.length();

            if (m * n == 0) {
                return m + n;
            }

            int[][] dp = new int[m+1][n+1];
            dp[0][0] = 0;

            for (int i=1; i<=m; ++i) {
                dp[i][0] = i;
            }

            for (int j=1; j<=n; ++j) {
                dp[0][j] = j;
            }

            for (int i=1; i<=m; ++i) {
                for (int j=1; j<=n; ++j) {
                    if (word1.charAt(i-1) == word2.charAt(j-1)) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = Math.min(Math.min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                }
            }

            return dp[m][n];
        }
    }
}
