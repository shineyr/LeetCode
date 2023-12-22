class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        var charMap = mutableMapOf<Char, Int>()
        var left = 0
        var i = 0
        var maxLen = 0

        while (i < s.length) {  
            while (charMap.contains(s[i])) {
                maxLen = max(maxLen, i - left)

                charMap.remove(s[left++])
            }
            charMap.put(s[i++], 1)  
        }

        maxLen = max(maxLen, i-left)

        return maxLen
    }
}

