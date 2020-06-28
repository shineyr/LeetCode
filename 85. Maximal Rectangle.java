/**
 * https://leetcode.com/problems/maximal-rectangle/
 * 85. Maximal Rectangle
 */
public class NO_85 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_85().solution.maximalRectangle(
                new char[][]{
                /*{'1', '0', '1', '0', '0'},
                {'1', '0', '1', '1', '1'},
                {'1', '1', '1', '1', '1'},
                {'1', '0', '0', '1', '0'},*/
                {'0', '1'},
                {'1', '0'}
        }));
    }

    class Solution {
        public int maximalRectangle(char[][] matrix) {
            if (matrix.length == 0) {
                return 0;
            }

            int m = matrix.length, n = matrix[0].length;

            int[][] heights = new int[m][n];

            int maxRec = 0;

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == 0) {
                        heights[i][j] = matrix[i][j] == '0' ? 0 : 1;
                    } else {
                        heights[i][j] = matrix[i][j] == '0' ? 0 : heights[i-1][j] + 1;
                    }
                }

                int curRec = maximalRectangle(heights[i]);
                maxRec = curRec > maxRec ? curRec : maxRec;
            }

            return maxRec;
        }


        public int maximalRectangle(int[] heights) {
            if (heights.length == 0) {
                return 0;
            }

            int maxRec = 0;

            for (int i = 0; i< heights.length; ++i) {
                int curRec = heights[i];

                int left = i - 1, right = i + 1;
                while (left >= 0 && heights[left] >= heights[i]) {
                    curRec += heights[i];
                    --left;
                }

                while (right < heights.length && heights[right] >= heights[i]) {
                    curRec += heights[i];
                    ++right;
                }

                maxRec = curRec > maxRec ? curRec : maxRec;
            }

            return maxRec;
        }
    }
}
