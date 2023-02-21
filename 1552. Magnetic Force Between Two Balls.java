class Solution {
    public int maxDistance(int[] position, int m) {
        int max = Arrays.stream(position).max().getAsInt();
        int min = Arrays.stream(position).min().getAsInt();

        int right = max - min, left = 1;

        while (left < right) {
            int mid = right - (right - left) / 2;

            if (isValid(position, m, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }

    private boolean isValid(int[] position, int m, int distance) {
        int count = 1;

        Arrays.sort(position);

        int lastPos = position[0];
        for (int i = 1; i < position.length; ++i) {
            if (position[i] - lastPos >= distance) {
                ++count;
                lastPos = position[i];

                if (count >= m) {
                    return true;
                }
            }
        }

        return false;
    }
}
