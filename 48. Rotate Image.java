class Solution {
    public void rotate(int[][] matrix) {
        if (matrix.length <= 0) {
            return;
        }
        
        int m = matrix.length, n = matrix[0].length;
        
        // First swap
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < n; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Second swap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n/2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
        
    }
}
