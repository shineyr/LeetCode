class Solution {
    public int strStr(String haystack, String needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        
        if (nLen == 0) {
            return 0;
        }

        for (int i = 0; i < hLen; ++i) {
            boolean find = true;

            for (int j = 0; j < nLen; ++j) {
                if (i + j >= hLen || haystack.charAt(i + j) != needle.charAt(j)) {
                    find = false;
                    break;
                }
            }

            if (find) {
                return i;
            }
        }

        return -1;
    }
    
    public int strStr1(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}
