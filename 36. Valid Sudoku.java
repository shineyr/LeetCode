class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<String> seen = new HashSet<>();

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char curVal = board[i][j];
                if (curVal != '.') {
                    if (!seen.add(curVal + " seen in row " + i) || !seen.add(curVal + " seen in col " + j) 
                            || !seen.add(curVal + " seen in sub-box " + i/3 + "-" + j/3)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public boolean isValidSudoku1(char[][] board) {
        for (int i = 0; i < board.length; ++i) {
            Set<Character> row = new HashSet<>();
            Set<Character> column = new HashSet<>();

            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] != '.' && row.contains(board[i][j])) {
                    return false;
                }

                if (board[j][i] != '.' && column.contains(board[j][i])) {
                    return false;
                }

                row.add(board[i][j]);
                column.add(board[j][i]);
            }
        }

        // Check 3*3 sub-box
        for (int row = 0; row < board.length; row += 3) {
            for (int col = 0; col < board[0].length; col += 3){
                if (!checkSubBox(board, row, col)) {
                    return false;
                }
            }
        }

        return true;
    }

    private boolean checkSubBox(char[][] board, int row, int col) {
        Set<Character> subBox = new HashSet<>();

        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j) {
                if (board[i][j] != '.' && subBox.contains(board[i][j])) {
                    return false;
                }
                subBox.add(board[i][j]);
            }
        }

        return true;
    }
}
