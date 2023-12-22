class Solution {
    fun findSubstring(s: String, words: Array<String>): List<Int> {
        if (words.size == 0) {
            return listOf()
        }

        val wordSize = words.size
        val wordCountMap = mutableMapOf<String, Int>()
        val wordLength = words[0].length

        for (word in words) {
            wordCountMap.put(word,(wordCountMap.get(word) ?: 0) + 1)
        }

        var result = mutableListOf<Int>()
        for (i in 0 ..< s.length - wordSize * wordLength + 1) {
            val tempCountMap = mutableMapOf<String, Int>()

            var c = 0
            while (c < wordSize) {
                val curWordInS = s.substring(i + c * wordLength, i + c * wordLength + wordLength)

                if (wordCountMap.contains(curWordInS)) {
                    tempCountMap.put(curWordInS, (tempCountMap.get(curWordInS) ?: 0) + 1)

                    if (tempCountMap.getOrElse(curWordInS) {0} > wordCountMap.getOrElse(curWordInS) {0}) {
                        break
                    }
                } else {
                    break
                }

                ++c
            }

            if (c == wordSize) {
                result.add(i)
            }
        }

        return result
    }
}


// barfoothefoobarman
// ["foo","bar"]
