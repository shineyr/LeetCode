import java.util.ArrayList;
import java.util.List;

/**
 * 22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 */
public class NO_22 {
    Solution solution = new Solution();

    public static void main(String[] args) {

        System.out.println(new NO_22().solution.generateParenthesis(3));
    }

    class Solution {
        public List<String> generateParenthesis(int n) {
            List<String> strings = new ArrayList<>();

            dfs(strings, "", 0, 0, n);

            return strings;
        }

        private void dfs(List<String> strings, String str, int left, int right, int n) {
            if (right > left) {
                return;
            }

            if (left == n && right == n) {
                strings.add(str);
            } else {
                if (left < n) {
                    dfs(strings, str + "(", left + 1, right, n);
                }

                if (right < n) {
                    dfs(strings, str + ")", left, right + 1, n);
                }
            }
        }
    }
}
