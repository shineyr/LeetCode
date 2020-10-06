class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = m > 0 ? obstacleGrid[0].length : 0;
        if (m <= 0 || n <= 0) {
            return 0;
        }

        int[][] uniquePaths = new int[m][n];
        uniquePaths[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int i = 1; i < m; ++i) {
            uniquePaths[i][0] = obstacleGrid[i][0] == 0 ? uniquePaths[i-1][0] : 0;
        }

        for (int j = 1; j < n; ++j) {
            uniquePaths[0][j] = obstacleGrid[0][j] == 0 ? uniquePaths[0][j-1] : 0;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    uniquePaths[i][j] = uniquePaths[i][j-1] + uniquePaths[i-1][j];
                } else {
                    uniquePaths[i][j] = 0;
                }
                
            }
        }

        return uniquePaths[m-1][n-1];
    }
}
