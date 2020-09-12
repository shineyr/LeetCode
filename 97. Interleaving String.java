class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1 == null || s2 == null || s3 == null) {
            return false;
        }

        int m = s1.length(), n = s2.length();
        if (s3.length() != (m + n)) {
            return false;
        }

        boolean[][] matches = new boolean[m + 1][n + 1];
        matches[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    matches[i][j] = true;
                } else if (i == 0) {
                    matches[i][j] = (matches[i][j-1] && s2.charAt(j-1) == s3.charAt(i+j-1));
                } else if (j == 0) {
                    matches[i][j] = (matches[i-1][j] && s1.charAt(i-1) == s3.charAt(i+j-1));
                } else {
                    matches[i][j] = (matches[i][j-1] && s2.charAt(j-1) == s3.charAt(i+j-1)) 
                            || (matches[i-1][j] && s1.charAt(i-1) == s3.charAt(i+j-1));
                }
            }
        }
        return matches[m][n];
    }


    // Solution 1: brute force - TLE
    public boolean isInterleave1(String s1, String s2, String s3) {
        return isInterleave(s1, 0, s2, 0, s3, "");
    }

    private boolean isInterleave(String s1, int i, String s2, int j, String s3, String cur) {
        if (s3.equals(cur) && i == s1.length() && j == s2.length()) {
            return true;
        }

        boolean ans = false;

        if (i < s1.length()) {
            ans |= isInterleave(s1, i+1, s2, j, s3, cur + s1.charAt(i));
        }

        if (j < s2.length()) {
            ans |= isInterleave(s1, i, s2, j+1, s3, cur + s2.charAt(j));
        }

        return ans;
    }
}
