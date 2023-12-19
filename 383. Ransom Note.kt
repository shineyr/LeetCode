class Solution {
    fun canConstruct(ransomNote: String, magazine: String): Boolean {
        var magazineMap = mutableMapOf<Char, Int>()

        for (i in 0 until magazine.length) {
            magazineMap.put(magazine[i], (magazineMap.get(magazine[i]) ?: 0) + 1)
        }

        for (i in 0 until ransomNote.length) {
            if ((magazineMap.get(ransomNote[i]) ?: 0) <= 0) {
                return false
            } else {
                magazineMap.put(ransomNote[i], (magazineMap.get(ransomNote[i]) ?: 0) - 1)
            }
        }

        return true
    }
}
