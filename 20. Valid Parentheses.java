import java.util.Stack;

/**
 * 20. Valid Parentheses
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *     Open brackets must be closed by the same type of brackets.
 *     Open brackets must be closed in the correct order.
 *
 * Note that an empty string is also considered valid.
 *
 */
public class NO_20 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_20().solution.isValid("()"));
        System.out.println(new NO_20().solution.isValid("()[]{}"));
        System.out.println(new NO_20().solution.isValid("([)]"));
    }

    class Solution {
        public boolean isValid(String s) {
            Stack<Character> stack = new Stack<>();

            for (Character c : s.toCharArray()) {
                if (c == '(' || c == '[' || c == '{') {
                    stack.push(c);
                } else if (c == ')' && (stack.isEmpty() || stack.pop() != '(')) {
                    return false;
                } else if (c == ']' && (stack.isEmpty() || stack.pop() != '[')) {
                    return false;
                } else if (c == '}' && (stack.isEmpty() || stack.pop() != '{')) {
                    return false;
                }
            }

            return stack.empty();
        }
    }
}
