import java.util.HashMap;
import java.util.Map;

/**
 * 1160. Find Words That Can Be Formed by Characters
 * https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
 * 
 * You are given an array of strings words and a string chars.
 *
 * A string is good if it can be formed by characters from chars (each character can only be used once).
 *
 * Return the sum of lengths of all good strings in words.
 */
public class NO_1160 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_1160().solution.countCharacters(new String[] {"cat","bt","hat","tree"},"atach"));
    }

    class Solution {
        public int countCharacters(String[] words, String chars) {
            Map<Character, Integer> charsMap = new HashMap<>();
            for (Character c : chars.toCharArray()) {
                charsMap.put(c, charsMap.getOrDefault(c, 0) + 1);
            }

            int sumOfLength = 0;
            for (String word : words) {
                if (isIncluded(word, charsMap)) {
                    sumOfLength += word.length();
                }
            }

            return sumOfLength;
        }

        private Boolean isIncluded(String word, Map<Character, Integer> charsMap) {
            Map<Character, Integer> wordMap = new HashMap<>();
            for (Character c : word.toCharArray()) {
                wordMap.put(c, wordMap.getOrDefault(c, 0) + 1);
            }

            for (Character key : wordMap.keySet()) {
                if (!charsMap.containsKey(key) || charsMap.get(key) < wordMap.get(key)) {
                    return false;
                }
            }

            return true;
        }
    }
}
