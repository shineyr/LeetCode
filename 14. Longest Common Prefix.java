class Solution {
    // Solution 4
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }

        int minLen = strs[0].length();
        for (int i = 1; i < strs.length; ++i) {
            minLen = Math.min(minLen, strs[i].length());
        }

        int low = 1, high = minLen, commonLen = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isCommonPrefix(strs, mid)) {
                low = mid + 1;
                commonLen = mid;
            } else {
                high = mid - 1;
            }
        }

        return strs[0].substring(0, commonLen);
    }

    private boolean isCommonPrefix(String[] strs, int len) {
        String prefix = strs[0].substring(0, len);

        for (int i = 1; i < strs.length; ++i) {
            if (!strs[i].startsWith(prefix)) {
                return false;
            }
        }

        return true;
    }
    
    // Solution 3
    public String longestCommonPrefix3(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        return longestCommonPrefix(strs, 0, strs.length - 1);
    }

    private String longestCommonPrefix(String[] strs, int left, int right) {
        if (left == right) {
            return strs[left];
        }

        int mid = left + (right - left) / 2;

        String leftCommon = longestCommonPrefix(strs, left, mid);
        String rightCommon = longestCommonPrefix(strs, mid + 1, right);

        return commonPrefix(leftCommon, rightCommon);
    }

    private String commonPrefix(String str1, String str2) {
        if (str1.length() == 0 || str2.length() == 0) {
            return "";
        }

        int minLen = Math.min(str1.length(), str2.length());
        for(int i = 0; i < minLen; ++i) {
            if (str1.charAt(i) != str2.charAt(i)) {
                return str1.substring(0, i);
            }
        }

        return str1.substring(0, minLen);
    }
    
    // Solution 2
    public String longestCommonPrefix2(String[] strs) {
        if (strs.length == 0) {
            return "";
        }

        for (int i = 0; i < strs[0].length(); ++i) {
            char c = strs[0].charAt(i);

            for (int j = 1; j < strs.length; ++j) {
                if (strs[j].length() == i || strs[j].charAt(i) != c) {
                    return strs[0].substring(0, i);
                }
            }
        }

        return strs[0];
    }
    
    // Solution 1
    public String longestCommonPrefix1(String[] strs) {
        if (strs.length == 0) {
            return "";
        }

        String prefix = strs[0];

        for(int i = 1; i < strs.length; ++i) {
            // Need prefix starts from index 0
            while (strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);

                if (prefix == "") {
                    return "";
                }
            }
        }

        return prefix;
    }
}
