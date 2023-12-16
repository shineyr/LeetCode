class Solution {
    fun hIndex(citations: IntArray): Int {
        val sortedCitations = citations.sorted()

        var maxH = 0

        for (i in 0 .. sortedCitations.size - 1) {
            val h = sortedCitations.size - i // at least h papers to the end

            if (sortedCitations[i] >= h) { // have each been cited at least h times.
                maxH = max(maxH, h)
            }
        }

        return maxH
    }
}


// 3, 0, 6, 1 5 
// 0, 1, 3, 5, 6
