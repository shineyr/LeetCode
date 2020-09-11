class Solution {
    // Solution 1
    public String countAndSay(int n) {
        String[] say = new String[n+1];
        say[1] = "1";

        for (int i = 2; i < n + 1; ++i) {
            say[i] = nextSay(say[i-1]);
        }

        return say[n];
    }

    // Solution 2
    public String countAndSay1(int n) {
        if (n == 1) {
            return "1";
        }

        String pre = countAndSay(n - 1);

        return nextSay(pre);
    }

    private String nextSay(String pre) {
        String ret = "";
        for (int i = 0; i < pre.length(); ) {
            char c = pre.charAt(i);
            int count = 1;

            int j = i + 1;
            while (j < pre.length()) {
                if (pre.charAt(j) != c) {
                    break;
                } else {
                    ++count;
                    ++j;
                }
            }

            i = j;
            ret = ret + count + c;
        }

        return ret;
    }
}
