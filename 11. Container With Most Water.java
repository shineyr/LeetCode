import sun.jvm.hotspot.memory.Space;

/**
 * 11. Container With Most Water
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 */
public class NO_11 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_11().solution.maxArea(new int[] {1,8,6,2,5,4,8,3,7}));
    }

    private class Solution {
        public int maxArea(int[] height) {
            int maxVolume = 0;
            for (int i=0, j=height.length-1; i<j; ) {
                int curVolume = (j - i) * Math.min(height[i], height[j]);

                maxVolume = Math.max(curVolume, maxVolume);

                if (height[i] < height[j]) {
                    ++i;
                } else {
                    --j;
                }
            }

            return maxVolume;
        }
    }
}
