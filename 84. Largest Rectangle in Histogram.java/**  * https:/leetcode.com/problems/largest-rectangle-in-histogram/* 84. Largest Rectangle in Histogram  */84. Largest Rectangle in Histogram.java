/**
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 * 84. Largest Rectangle in Histogram
 */
public class NO_84 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_84().solution.largestRectangleArea(new int[] {2,1,5,6,2,3}));
    }

    class Solution {
        public int largestRectangleArea(int[] heights) {
            if (heights.length == 0) {
                return 0;
            }

            int maxRec = 0;

            for (int i=0; i<heights.length; ++i){
                int left = i - 1, right = i + 1;
                while (left >= 0 && heights[left] >= heights[i]) {
                    --left;
                }

                while (right < heights.length && heights[right] >= heights[i]) {
                    ++right;
                }

                int curRec = heights[i] * (right - left - 1);

                maxRec = Math.max(curRec, maxRec);
            }

            return maxRec;
        }
    }
}
