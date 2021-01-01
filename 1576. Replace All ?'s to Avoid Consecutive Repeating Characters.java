class Solution {
    public String modifyString(String s) {
        StringBuilder newStr = new StringBuilder(s);
        int slen = s.length();
        
        for (int i = 0; i < slen; ++i) {
            if (s.charAt(i) != '?') {
                continue;
            }
            
            for (char c = 'a'; c <= 'z'; ++c) {
                if (i - 1 >= 0 && c == newStr.charAt(i-1)) {
                    continue;
                } else if (i + 1 < slen && c == newStr.charAt(i+1)) {
                    continue;
                } else {
                    newStr.setCharAt(i, c);
                }
            }
        }
    
        return newStr.toString();
    }
}
