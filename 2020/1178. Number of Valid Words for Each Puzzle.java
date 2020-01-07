import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 1178. Number of Valid Words for Each Puzzle
 * https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
 *
 * With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
 *
 *     word contains the first letter of puzzle.
 *     For each letter in word, that letter is in puzzle.
 *     For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage"; while invalid words are "beefed" (doesn't include "a") and "based" (includes "s" which isn't in the puzzle).
 *
 * Return an array answer, where answer[i] is the number of words in the given word list words that are valid with respect to the puzzle puzzles[i].
 */
public class NO_1178 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_1178().solution.findNumOfValidWords(
                new String[] {"aaaa","asas","able","ability","actt","actor","access"},
                new String[] {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"}
        ));
    }

    class Solution {
        public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
            Map<Integer, Integer> wordMap = new HashMap<>();
            for (String word : words) {
                int mask = 0;

                for (char c : word.toCharArray()) {
                    mask |= 1 << (c - 'a');
                }

                wordMap.put(mask, wordMap.getOrDefault(mask, 0) + 1);
            }


            List<Integer> result = new ArrayList<>();
            for (String puzzle : puzzles) {
                result.add(countValidWords(wordMap, puzzle));
            }

            return result;
        }

        private int countValidWords(Map<Integer, Integer> wordMap, String puzzle) {
            int mask = 0;
            for (char c : puzzle.toCharArray()) {
                mask |= 1 << (c - 'a');
            }

            int count = 0;
            int subMask = mask;

            int first = 1 << (puzzle.charAt(0) - 'a');
            while (true) {
                if ((subMask & first) == first && wordMap.containsKey(subMask)) {
                    count += wordMap.get(subMask);
                }

                if (subMask == 0) {
                    break;
                }

                subMask = (subMask - 1) & mask;
            }

            return count;
        }
    }
}
