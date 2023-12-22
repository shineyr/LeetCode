class Solution {
    fun maxArea(height: IntArray): Int {
        var left = 0
        var right = height.lastIndex

        var maxAmount = 0
        while (left < right) {
            maxAmount = max(maxAmount, min(height[left], height[right]) * (right - left))

            if (height[left] < height[right]) {
                ++left
            } else {
                --right
            }
        }

        return maxAmount
    }
}
