class Solution {
    // two direction traversal
    fun candy(ratings: IntArray): Int {
        val candies = IntArray(ratings.size, {i -> 1})

        for (i in 1 .. ratings.size-1) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1
            }
        }
        for (i in ratings.size-2 downTo 0) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1)
            }
        }

        return candies.sum()
    }
}


// 1 0 2
// 1 1 1
// 1 1 2 left to right
// 2 1 2 right to left


// 1 3 2 2 1
// 1 1 1 1 1
// 1 2 1 1 1
// 1  2  1 2 1
