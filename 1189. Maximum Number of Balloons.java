import java.util.HashMap;
import java.util.Map;

/**
 * 1189. Maximum Number of Balloons
 *
 * Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
 *
 * You can use each character in text at most once. Return the maximum number of instances that can be formed.
 */
public class NO_1189 {
    Solution solution = new Solution();

    public static void main(String[] args) {

        System.out.println(new NO_1189().solution.maxNumberOfBalloons("balon"));

        System.out.println(new NO_1189().solution.maxNumberOfBalloons("nlaebolko"));

        System.out.println(new NO_1189().solution.maxNumberOfBalloons("loonbalxballpoon"));



    }

    class Solution {
        public int maxNumberOfBalloons(String text) {
            Map<Character, Integer> targetMap = new HashMap<>();
            String target = "balloon";
            for (char c : target.toCharArray()) {
                if (targetMap.containsKey(c)) {
                    targetMap.put(c, targetMap.get(c) + 1);
                } else {
                    targetMap.put(c, 1);
                }
            }

            Map<Character, Integer> sourceMap = new HashMap<>();
            for (char c : text.toCharArray()) {
                if (!targetMap.containsKey(c)) {
                    continue;
                }

                if( sourceMap.containsKey(c)) {
                    sourceMap.put(c, sourceMap.get(c) + 1);
                } else {
                    sourceMap.put(c, 1);
                }
            }

            int minNumber = sourceMap.values().isEmpty() ? 0 : (int) sourceMap.values().toArray()[0];

            for (char key : targetMap.keySet()) {
                if (!sourceMap.containsKey(key)) {
                    return 0;
                } else {
                    int times = sourceMap.get(key) / targetMap.get(key);

                    minNumber = minNumber < times ? minNumber : times;
                }
            }
            return minNumber;
        }
    }
}

