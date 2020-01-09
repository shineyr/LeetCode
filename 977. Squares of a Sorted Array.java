import java.util.Arrays;

/**
 * 977. Squares of a Sorted Array
 *
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.
 */
public class NO_977 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new NO_977().solution.sortedSquares(new int[] {-3,-1,0})));

        System.out.println(Arrays.toString(new NO_977().solution.sortedSquares(new int[] {-4,-1,0,3,10})));

        System.out.println(Arrays.toString(new NO_977().solution.sortedSquares(new int[] {-7,-3,2,3,11})));
    }

    class Solution {
        public int[] sortedSquares(int[] A) {
            int len = A.length;

            int[] squares = new int[len];

            int minAbsPos = 0;
            for(int i=0; i<len; ++i) {
                if (i == len-1 || Math.abs(A[i]) < Math.abs(A[i+1])) {
                    minAbsPos = i;
                    break;
                }
            }

            int left = minAbsPos, right = minAbsPos+1, j = 0;
            while(left>=0 && right<len) {
                if (Math.abs(A[left]) < Math.abs(A[right])) {
                    squares[j++] = (int) Math.pow(A[left], 2);
                    --left;
                } else {
                    squares[j++] = (int) Math.pow(A[right], 2);
                    ++right;
                }
            }

            while (left >= 0) {
                squares[j++] = (int) Math.pow(A[left], 2);
                --left;
            }

            while (right < len) {
                squares[j++] = (int) Math.pow(A[right], 2);
                ++right;
            }

            return squares;
        }
    }
}
