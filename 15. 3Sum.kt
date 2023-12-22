class Solution {
    fun threeSum(nums: IntArray): List<List<Int>> {
        var sortedNums = nums.sorted()
        var result = mutableListOf<List<Int>>()

        for (i in 0 ..< sortedNums.size) {
            if (i > 0 && sortedNums[i] == sortedNums[i-1]) {
                continue
            }

            var beg = i + 1
            var end = sortedNums.lastIndex

            while (beg < end) {
                var sum = sortedNums[i] + sortedNums[beg] + sortedNums[end]

                if (sum == 0) {
                    result.add(listOf(sortedNums[i], sortedNums[beg], sortedNums[end]))

                    while (beg < end && sortedNums[beg+1] == sortedNums[beg]) {
                        ++beg
                    }

                    while (beg < end && sortedNums[end-1] == sortedNums[end]) {
                        --end
                    }

                    ++beg
                    --end
                } else if (sum < 0) {
                    ++beg
                } else {
                    --end
                } 
            } 
        }

        return result
    }
}
