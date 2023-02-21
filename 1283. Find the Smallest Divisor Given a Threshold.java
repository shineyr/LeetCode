class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        if (threshold < nums.length) {
            return -1;
        }

        int right = Arrays.stream(nums).max().getAsInt();
        int left = 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isValid(nums, threshold, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    private boolean isValid(int[] nums, int threshold, int divisor) {
        int sum = 0;

        for (int num : nums) {
            sum += (int) Math.ceil((double) num / divisor);
        }

        return sum <= threshold;
    }
}
