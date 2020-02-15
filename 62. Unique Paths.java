/**
 * 62. Unique Paths
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 */
public class NO_62 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_62().solution.uniquePaths(7, 3));
    }

    class Solution {
        public int uniquePaths(int m, int n) {
            int[][] dp = new int[m][n];
            dp[0][0] = 1;

            for(int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    dp[i][j] += (i == 0 ? 0 : dp[i-1][j]) + (j == 0 ? 0 : dp[i][j-1]);
                }
            }

            return dp[m-1][n-1];
        }
    }
}
