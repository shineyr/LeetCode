class Solution {
    fun lengthOfLastWord(s: String): Int {
        var wordList = s.trim().split(' ')

        return wordList.get(wordList.size - 1).length
    }


    fun lengthOfLastWord1(s: String): Int {
        var lastWordLen = 0

        for (i in s.length-1 downTo 0) {
            if (s[i] == ' ') {
                if (lastWordLen == 0) {
                    continue
                } else {
                    return lastWordLen
                }
            } else {
                ++lastWordLen
            }
        }

        return lastWordLen
    }
}
