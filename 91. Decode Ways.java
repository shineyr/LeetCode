class Solution {
    public int numDecodings(String s) {
        int len = s.length();
        if (len <= 0) {
            return 0;
        }

        int[] dp = new int[len + 1];
        dp[0] = 1;
        dp[1] = s.charAt(0) == '0' ? 0 : 1;

        for (int i = 2; i <= len; ++i) {
            int oneDigitVal = Integer.valueOf(s.substring(i-1, i));
            if (oneDigitVal > 0 && oneDigitVal <= 9) {
                dp[i] += dp[i-1];
            }

            int twoDigitVal = Integer.valueOf(s.substring(i-2, i));
            if (twoDigitVal >= 10 && twoDigitVal <= 26) {
                dp[i] += dp[i-2];
            }
        }

        return dp[len];
    }
}
