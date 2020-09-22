class Solution {
    // Two pointer
    public int trap(int[] height) {
        int left = 0, right = height.length - 1;

        int leftMaxHeight = 0, rightMaxHeight = 0, ans = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMaxHeight) {
                    leftMaxHeight = height[left];
                } else {
                    ans += leftMaxHeight - height[left];
                }
                ++left;
            } else {
                if (height[right] >= rightMaxHeight) {
                    rightMaxHeight = height[right];
                } else {
                    ans += (rightMaxHeight - height[right]);
                }
                --right;
            }
        }
        return ans;
    }

    // Dynamic programming
    public int trap2(int[] height) {
        int len = height.length;

        if (len == 0) {
            return 0;
        }

        int[] leftMaxHeight = new int[len];
        int[] rightMaxHeight = new int[len];

        for (int i = 0; i < len; ++i) {
            if (i == 0) {
                leftMaxHeight[i] = height[0];
            } else {
                leftMaxHeight[i] = Math.max(height[i], leftMaxHeight[i-1]);
            }
        }

        for (int j = len - 1; j >= 0; --j) {
            if (j == len - 1) {
                rightMaxHeight[j] = height[len - 1];
            } else {
                rightMaxHeight[j] = Math.max(height[j], rightMaxHeight[j + 1]);
            }
        }

        int ans = 0;
        for (int k = 0; k < len; ++k) {
            ans += (Math.min(leftMaxHeight[k], rightMaxHeight[k]) - height[k]);
        }

        return ans;
    }
    
    // Brute force
    public int trap1(int[] height) {
        int ans = 0;
            
        for (int i = 0; i < height.length; ++i) {
            int left_max = 0, right_max = 0;
            int j = i, k = i;
            while (j >= 0) {
                left_max = Math.max(left_max, height[j]);
                --j;
            }

            while (k < height.length) {
                right_max = Math.max(right_max, height[k]);
                ++k;
            }

            ans += (Math.min(left_max, right_max) - height[i]);
        }
        return ans;
    }
}
