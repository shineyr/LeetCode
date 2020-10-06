class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int len = intervals.length;
        if (len == 0) {
            return new int[][] {newInterval};
        }

        List<int[]> ret = new ArrayList<>();

        // Add current intervals before overlapping
        int idx = 0;
        while(idx < len && intervals[idx][1] < newInterval[0]) {
            ret.add(intervals[idx]);

            ++idx;
        }

        // Find new [beg, end] while overlapping
        while (idx < len && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = Math.min(intervals[idx][0], newInterval[0]);
            newInterval[1] = Math.max(intervals[idx][1], newInterval[1]);

            ++idx;
        }

        ret.add(newInterval);

        // Add rest intervals after overlapping
        while (idx < len) {
            ret.add(intervals[idx]);

            ++idx;
        }

        return ret.toArray(new int[ret.size()][2]);
    }
}
