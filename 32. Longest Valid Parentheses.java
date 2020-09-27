class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                ++left;
            } else {
                ++right;
            }

            if (left == right) {
                maxLen = Math.max(maxLen, 2 * right);
            } else if (right > left){
                left = right = 0;
            }
        }

        left = right = 0;
        for (int j = s.length() - 1; j >= 0; --j) {
            if (s.charAt(j) == '(') {
                ++left;
            } else {
                ++right;
            }

            if (left == right) {
                maxLen = Math.max(maxLen, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return maxLen;
    }
    public int longestValidParentheses2(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);

        int maxValidLen = 0, curLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxValidLen = Math.max(maxValidLen, i - stack.peek());
                }
            }
        }

        return maxValidLen;
    }


    public int longestValidParentheses1(String s) {
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i+2; j <= s.length(); j+=2) {
                if (isValid(s.substring(i, j))) {
                    maxLen = Math.max(maxLen, j - i);
                }
            }
        }

        return maxLen;
    }

    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (Character c : s.toCharArray()) {
            if (c == '(') {
                stack.push(c);
                continue;
            }

            if (c == ')') {
                if (!stack.empty()) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return stack.empty();
    }
}
