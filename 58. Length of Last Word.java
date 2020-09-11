class Solution {
    public int lengthOfLastWord(String s) {
        if (s == null || s == "") {
            return 0;
        }

        int lastWordLen = 0;
        boolean isLastWord = false;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.charAt(i) == ' ' && isLastWord) {
                return lastWordLen;
            }

            if (s.charAt(i) != ' ') {
                ++lastWordLen;
                isLastWord = true;
            }
        }

        return lastWordLen;
    }

    public int lengthOfLastWord1(String s) {
        if (s == null || s == "") {
            return 0;
        }

        int idx = s.lastIndexOf(" ");
        if (idx < 0) {
            return s.length();
        }

        while (idx > 0 && idx == s.length() - 1) {
            s = s.substring(0, idx);
            idx = s.lastIndexOf(" ");
        }

        return (s.substring(idx + 1)).length();
    }
}
