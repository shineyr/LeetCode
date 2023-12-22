class Solution {
    fun isPalindrome(s: String): Boolean {
        var i = 0
        var j = s.lastIndex
        var sl = s.lowercase()
        while (i < j) {
            // Character.isLetterOrDigit(sl[i])
            if (!sl[i].isLetterOrDigit()) {
                ++i
            } else if (sl[j] !in ('a' .. 'z') && sl[j] !in ('0' .. '9')) {
                --j
            } else if (sl[i] != sl[j]) {
                return false
            } else {
                ++i
                --j
            }
        }

        return true
    }
}
