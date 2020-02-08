import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 17. Letter Combinations of a Phone Number
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 */
public class NO_17 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_17().solution.letterCombinations("23"));
    }

    private class Solution {
        public List<String> letterCombinations(String digits) {
            Map<Character, List<String>> digitMap = new HashMap<Character, List<String>>() {
                {
                    put('2', Arrays.asList("a", "b", "c"));
                    put('3', Arrays.asList("d", "e", "f"));
                    put('4', Arrays.asList("g", "h", "i"));
                    put('5', Arrays.asList("j", "k", "l"));
                    put('6', Arrays.asList("m", "n", "o"));
                    put('7', Arrays.asList("p", "q", "r", "s"));
                    put('8', Arrays.asList("t", "u", "v"));
                    put('9', Arrays.asList("w", "x", "y", "z"));
                }
            };

            return letterCombinations(digits, digitMap);
        }

        List<String> letterCombinations(String digits, Map<Character, List<String>> digitMap) {
            if (digits.isEmpty()) {
                return new ArrayList<>();
            }

            if (digits.length() == 1) {
                if (!digitMap.containsKey(digits.charAt(0))) {
                    return new ArrayList<>();
                }

                return digitMap.get(digits.charAt(0));
            }

            List<String> rightCombinations = letterCombinations(digits.substring(1), digitMap);

            List<String> ret = new ArrayList<>();
            for (String letter : digitMap.get(digits.charAt(0))) {
                for (String combination : rightCombinations) {
                    ret.add(letter + combination);
                }
            }

            return ret;
        }
    }
}
