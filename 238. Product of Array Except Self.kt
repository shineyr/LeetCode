class Solution {
    // space O(1) -- output doesn't count extra space time O(1)
    fun productExceptSelf(nums: IntArray): IntArray {
        val answer = IntArray(nums.size)
        answer[0] = 1

        for (i in 1 .. nums.size-1) {
            answer[i] = answer[i-1] * nums[i-1]
        }

        var backwardProduct = 1
        for (i in nums.size-1 downTo 0) {
            answer[i] = answer[i] * backwardProduct

            backwardProduct *= nums[i]
        }

        return answer
    }

    // space O(n) time O(n)
    fun productExceptSelf2(nums: IntArray): IntArray {
        val forwardProduct = IntArray(nums.size)
        val backwardProduct = IntArray(nums.size)

        var product = 1
        forwardProduct[0] = product
        for (i in 1 .. nums.size-1) {
            product *= nums[i-1]
            forwardProduct[i] = product
        }

        product = 1
        backwardProduct[nums.size-1] = product
        for (i in nums.size-2 downTo 0) {
            product *= nums[i+1]
            backwardProduct[i] = product
        }

        for(i in 0 .. nums.size-1) {
            nums[i] = forwardProduct[i] * backwardProduct[i]
        }

        return nums
    }

    // TLE
    fun productExceptSelf1(nums: IntArray): IntArray {
       var result = IntArray(nums.size)

        for (i in 0 .. nums.size-1) {
            var product = 1
            for (j in 0 .. nums.size-1) {
                if (j == i) {
                    continue
                }

                product *= nums[j]
            }
            result[i] = product
        }

        return result
    }
}
