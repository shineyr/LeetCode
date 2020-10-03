class Solution {
    public boolean exist(char[][] board, String word) {

        // Use each point as a beginning, see whether it can finish the tracking.
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (backTracking(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    private boolean backTracking(char[][] board, int x, int y, String word, int idx) {
        if (x < 0 || x == board.length || y < 0 || y >= board[0].length || board[x][y] == '-' || board[x][y] != word.charAt(idx)) {
            return false;
        }

        if (idx == word.length() - 1) {
            return true;
        }

        char curVal = board[x][y];
        board[x][y] = '-';

        boolean goUp = backTracking(board, x, y-1, word, idx + 1);
        boolean goDown = backTracking(board, x, y+1, word, idx + 1);
        boolean goLeft = backTracking(board, x-1, y, word, idx + 1);
        boolean goRight = backTracking(board, x+1, y, word, idx + 1);

        if (goUp || goDown || goLeft || goRight) {
            return true;
        } else {
            board[x][y] = curVal;
            return false;
        }
    }
}
