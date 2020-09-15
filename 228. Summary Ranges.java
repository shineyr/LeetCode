class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ranges = new ArrayList<>();

        int len = nums.length;

        if (len == 0) {
            return ranges;
        } else if (len == 1) {
            ranges.add(String.valueOf(nums[0]));
            return ranges;
        }

        int start = nums[0], count = 1;
        for(int i = 1; i < len; ++i) {
            if (nums[i] == (nums[i-1] + 1)) {
                ++count;
            } else {
                if (count == 1) {
                    ranges.add(String.valueOf(nums[i-1]));
                } else {
                    ranges.add(String.join("->", String.valueOf(start), String.valueOf(nums[i-1])));
                }

                start = nums[i];
                count = 1;
            }
        }

        if (count == 1) {
            ranges.add(String.valueOf(nums[len - 1]));
        } else {
            ranges.add(String.join("->", String.valueOf(start), String.valueOf(nums[len-1])));
        }

        return ranges;
    }
}
