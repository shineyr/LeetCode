class Solution {
    fun canCompleteCircuit(gas: IntArray, cost: IntArray): Int {
        if (gas.size <= 0 || cost.size <= 0 || gas.size != cost.size) {
            return -1
        }

        val n = gas.size
        var totalGas = 0
        var curSumGas = 0
        var start = 0
        for (i in 0 .. n-1) {
            totalGas += (gas[i] - cost[i])

            // previously, gas tank is already empty, cannot reach current station
            // so we should start from current station and try
            if (curSumGas < 0) {
                start = i
                curSumGas = gas[i] - cost[i]
            } else {
                curSumGas += (gas[i] - cost[i])
            }
        }

        return if (totalGas < 0) -1 else start
    }

    // TLE
    fun canCompleteCircuit1(gas: IntArray, cost: IntArray): Int {
        for(i in gas.indices) {
            if (canComplete(gas, cost, i)) {
                return i
            }
        }

        return -1
    }

    fun canComplete(gas: IntArray, cost: IntArray, start: Int): Boolean {
        var totalGas = 0

        // count of stations that go through 
        var i = 0
        val n = gas.size

        while (i < n) {
            val station = (start + i + n) % n
            totalGas += gas[station]
            if (totalGas < cost[station]) {
                return false
            }

            totalGas -= cost[station]
            ++i
        }
        return true
    }
}


// 1 2 3 4 5
// 3 4 5 1 2

