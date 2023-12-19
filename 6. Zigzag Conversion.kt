class Solution {
    fun convert(s: String, numRows: Int): String {
        var result = Array<String>(numRows, {i -> ""})

        var i = 0
        while (i < s.length) {
            // fill the first column
            for (row in 0 .. numRows - 1) {
                if (i < s.length) {
                    result[row] = result[row].plus(s[i++])
                } else {
                    break
                }
            }

            // handle the rest numRows - 2 columns
            for (row in numRows - 2 downTo 1) {
                if (i < s.length) {
                    result[row] = result[row].plus(s[i++])
                } else {
                    break
                }
            }
        }

        return result.joinToString("")
    }
}

// rows - 2, .. 1
// 0: P
// 1: A
// 2: Y
// 3: P


