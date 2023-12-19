class Solution {
    // time nlog(n) * L
    fun longestCommonPrefix3(strs: Array<String>): String{
        if (strs.size == 0) {
            return ""
        }

        // N
        var minLen = strs[0].length
        for (i in 1 .. strs.size-1) {
            minLen = min(minLen, strs[i].length)
        }

        var low = 1
        var high = minLen
        var prefixLen = 0

        // log(N) times * NL
        while (low <= high) {
            val mid = low + (high - low) / 2

            
            if (isCommonPrefix(strs, mid)) {
                prefixLen = mid
                low = mid + 1
            } else {
                high = mid - 1
            }
        }

        return strs[0].substring(0, prefixLen)
    }


    // NL
    fun isCommonPrefix(strs: Array<String>, len: Int): Boolean {
        val prefix = strs[0].substring(0, len)

        for (i in 1 .. strs.size-1) {
            if (!strs[i].startsWith(prefix)) {
                return false
            }
        }

        return true
    }

    fun longestCommonPrefix(strs: Array<String>): String {
        return longestCommonPrefix(strs, 0, strs.size - 1)
    }

    fun longestCommonPrefix(strs: Array<String>, beg: Int, end: Int): String {
        if (beg == end) {
            return strs[beg]
        }

        val mid = beg + (end - beg) / 2

        val leftCommonPrefix = longestCommonPrefix(strs, beg, mid)
        val rightCommonPrefix = longestCommonPrefix(strs, mid + 1, end)

        return commonPrefix(leftCommonPrefix, rightCommonPrefix)
    }

    fun commonPrefix(str1: String, str2: String): String {
        if (str1.equals(str2)) {
            return str1
        }

        val minLen = min(str1.length, str2.length)
        for (i in 0 .. minLen-1) {
            if (str1[i] != str2[i]) {
                return str1.substring(0, i)
            }
        }
        return str1.substring(0, minLen)
    }


    // Solution 1: brute force
    fun longestCommonPrefix1(strs: Array<String>): String {
        if (strs.size == 0) {
            return ""
        }

        var ret = strs[0]
        for (i in 1 .. strs.size-1) {
            ret = findPrefix(ret, strs[i])
        }

        return ret
    }


    fun findPrefix(str1: String, str2: String): String {
        if (str1.startsWith(str2)) {
            return str2
        }

        if (str2.startsWith(str1)) {
            return str1
        }

        val prefix = ArrayList<Char>()

        var i = 0
        while (i < str1.length && i < str2.length) {
            if (str1[i] == str2[i]) {
                prefix.add(str1[i])
            } else {
                break
            }

            ++i
        }

        return prefix.joinToString("")
    }
}
