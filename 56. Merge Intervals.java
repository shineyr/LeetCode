import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * 56. Merge Intervals
 * Given a collection of intervals, merge all overlapping intervals.
 */
public class NO_56 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        int[][] ret = new NO_56().solution.merge(new int[][] {{1,3},{2,6},{8,10},{15,18}});
        for (int i=0; i<ret.length; ++i) {
            System.out.println(Arrays.toString(ret[i]));
        }
    }

    private class Solution {
        public int[][] merge(int[][] intervals) {
            if (intervals.length == 0) {
                return intervals;
            }

            // 对二维数组按行排序
            Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[0]));

            List<int[]> ret = new ArrayList<>();

            int left = intervals[0][0], right = intervals[0][1];
            for (int row=0; row<intervals.length; ++row) {
                left = Math.min(intervals[row][0], left);
                right = Math.max(intervals[row][1], right);

                if (row == intervals.length - 1) {
                    ret.add(new int[] {left, right});
                } else if (row < intervals.length-1 && right < intervals[row+1][0]) {
                    ret.add(new int[] {left, right});
                    left = intervals[row+1][0];
                    right = intervals[row+1][1];
                } else if (row < intervals.length-1 && right > intervals[row+1][0]) {
                    right = Math.max(intervals[row+1][1], right);
                }
            }

            return ret.toArray(new int[0][]);
        }
    }
}
