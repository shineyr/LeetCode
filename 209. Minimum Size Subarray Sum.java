class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int len = nums.length;

        int minCount = Integer.MAX_VALUE;

        int left = 0, sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];

            while (sum >= s) {
                minCount = Math.min(minCount, i + 1 - left);

                sum -= nums[left];
                ++left;
            }
        }

        return minCount != Integer.MAX_VALUE ? minCount : 0;
    }

    public int minSubArrayLen1(int s, int[] nums) {
        int len = nums.length;

        int minCount = Integer.MAX_VALUE;
        for (int i = 0; i < len; ++i) {
            int sum = nums[i];
            int count = 1;
            if (sum >= s) {
                minCount = Math.min(count, minCount);
                break;
            }

            for (int j = i + 1; j < len; ++j) {
                sum += nums[j];
                ++count;

                if (sum >= s) {
                    minCount = Math.min(count, minCount);
                    break;
                }
            }
        }

        return minCount != Integer.MAX_VALUE ? minCount : 0;
    }
}
