class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int max = Arrays.stream(bloomDay).max().getAsInt();
        int min = Arrays.stream(bloomDay).min().getAsInt();

        int left = min, right = max, ans = -1;

        while (left <= right) {
            int mid =  left + (right - left) / 2;          

            if (isValid(bloomDay, m, k, mid)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }

        }

        return ans;
    }

    private boolean isValid(int[] bloomDay, int m, int k, int days) {
        int count = 0, lastBloom = 0;

        for (int i = 0; i < bloomDay.length; ++i) {
            if (bloomDay[i] <= days) {
                if (lastBloom <= i && i - lastBloom + 1 >= k) {
                    ++count;
                    lastBloom = i + 1;
                }
            } else {
                lastBloom = i + 1;
            }
        }

        return count >= m;
    }
}
