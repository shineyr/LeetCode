class Solution {
    public void setZeroes(int[][] matrix) {
        int rowLen = matrix.length, colLen = rowLen > 0 ? matrix[0].length : 0;

        boolean isFirstCol = false;
        for (int i = 0; i < rowLen; ++i) {
            // check if the first column should be 0
            if (matrix[i][0] == 0) {
                isFirstCol = true;
            }

            for (int j = 1; j < colLen; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < rowLen; ++i) {
            for (int j = 1; j < colLen; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // See if the first row needs to be set to zero as well
        if (matrix[0][0] == 0) {
            for (int j = 0; j < colLen; j++) {
                matrix[0][j] = 0;
            }
        }

        // See if the first column needs to be set to zero as well
        if (isFirstCol) {
            for (int i = 0; i < rowLen; i++) {
                matrix[i][0] = 0;
            }
        }
    }

    public void setZeroes1(int[][] matrix) {
        int rowLen = matrix.length, colLen = rowLen > 0 ? matrix[0].length : 0;

        Set<Integer> rows = new HashSet<>();
        Set<Integer> cols = new HashSet<>();

        for (int i = 0; i < rowLen; ++i) {
            for (int j = 0; j < colLen; ++j) {
                if (matrix[i][j] == 0) {
                    rows.add(i);
                    cols.add(j);
                }
            }
        }

        for (int i = 0; i < rowLen; ++i) {
            for (int j = 0; j < colLen; ++j) {
                if (rows.contains(i) || cols.contains(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
