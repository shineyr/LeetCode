class Solution {
    fun minSubArrayLen(target: Int, nums: IntArray): Int {
        var i = 0
        var left = 0
        var subArraySum = 0
        var minLength = Int.MAX_VALUE
        
        while (i < nums.size) {
            if (subArraySum < target) {
                subArraySum += nums[i]
            } 

            while (subArraySum >= target && left <= i) {
                minLength = min(minLength, i - left + 1)

                subArraySum -= nums[left]
                ++left
            }
            
            ++i
        }

        return if (minLength == Int.MAX_VALUE) 0 else minLength
    }
}
