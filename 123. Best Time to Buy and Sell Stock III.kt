class Solution {
    fun maxProfit(prices: IntArray): Int {
        val n = prices.size

        val firstMaxProfits: IntArray = IntArray(n)
        var minPrice = prices[0]
        var firstMaxProfit = 0

        for (i in 1 .. prices.size - 1) {
            if (prices[i] < minPrice ) {
                minPrice = prices[i]
            } else {
                firstMaxProfit = max(firstMaxProfit, prices[i] - minPrice)
            }

            firstMaxProfits[i] = firstMaxProfit
        }

        var secondProfits: IntArray = IntArray(n)
        var maxPrice = prices[n-1]
        var secondMaxProfit = 0
        for (i in prices.size - 2 downTo 0) {
            if (prices[i] > maxPrice) {
                maxPrice = prices[i]
            } else {
                secondMaxProfit = max(secondMaxProfit, maxPrice - prices[i])
            }

            secondProfits[i] = secondMaxProfit
        }

        var maxProfit = 0
        for (i in prices.indices) {
            maxProfit = max(maxProfit, firstMaxProfits[i] + secondProfits[i])
        }

        return maxProfit
    }
}
