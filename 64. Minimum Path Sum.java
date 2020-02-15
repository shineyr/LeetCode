/**
 * 64. Minimum Path Sum
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 */
public class NO_64 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_64().solution.minPathSum(new int[][]{{1,3,1},{1,5,1},{4,2,1}}));
    }

    class Solution {
        public int minPathSum(int[][] grid) {
            if (grid.length <= 0) {
                return 0;
            }

            int m = grid.length, n = grid[0].length;

            int[][] minPath = new int[m][n];
            minPath[0][0] = grid[0][0];

            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (i > 0 && j == 0) {
                        minPath[i][j] = minPath[i-1][j] + grid[i][j];
                    } else if (i ==0 && j > 0) {
                        minPath[i][j] = minPath[i][j-1] + grid[i][j];
                    } else if (i > 0 && j > 0) {
                        minPath[i][j] = Math.min(minPath[i-1][j], minPath[i][j-1]) + grid[i][j];
                    }
                }
            }

            return minPath[m-1][n-1];
        }
    }
}
