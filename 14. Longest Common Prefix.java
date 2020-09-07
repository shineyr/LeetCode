class Solution {
    public String longestCommonPrefix(String[] strs) {
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
