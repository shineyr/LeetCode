class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        if (rows <= 0) {
            return false;
        }

        int cols = matrix[0].length;

        int left = 0, right = rows * cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = mid / cols, col = mid % cols;

            if (matrix[row][col] == target) {
                return true;
            } else if (target > matrix[row][col]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }

    public boolean searchMatrix1(int[][] matrix, int target) {
        int rows = matrix.length;
        if (rows <= 0) {
            return false;
        }

        int cols = matrix[0].length;

        int begRow = 0, endRow = rows - 1, targetRow = 0;
        while (begRow < endRow) {
            int midRow = begRow + (endRow - begRow) / 2;

            if (matrix[midRow][0] == target) {
                return true;
            } else if (midRow + 1 <= endRow && matrix[midRow][0] < target && matrix[midRow + 1][0] > target) {
                targetRow = midRow;
                break;
            } else if (matrix[midRow][0] < target) {
                begRow = midRow + 1;
            } else {
                endRow = midRow - 1;
            }
        }

        if (begRow == endRow) {
            targetRow = begRow;
        }

        int begCol = 0, endCol = cols - 1;
        while (begCol <= endCol) {
            int midCol = begCol + (endCol - begCol) / 2;

            if (matrix[targetRow][midCol] == target) {
                return true;
            } else if (matrix[targetRow][midCol] < target) {
                begCol = midCol + 1;
            } else {
                endCol = midCol - 1;
            }
        }

        return false;
    }
}
