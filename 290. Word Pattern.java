class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");

        if (pattern.length() != words.length) {
            return false;
        }

        HashMap indexMap = new HashMap();

        for (Integer i = 0; i < words.length; ++i) {
            char c = pattern.charAt(i);
            String word = words[i];

            if (!indexMap.containsKey(c)) {
                indexMap.put(c, i);
            }

            if (!indexMap.containsKey(word)) {
                indexMap.put(word, i);
            }

            if (indexMap.get(c) != indexMap.get(word)) {
                return false;
            }
        }

        return true;
    }
        
    
    public boolean wordPattern1(String pattern, String s) {
        int pLen = pattern.length();
        String[] words = s.split(" ");
        int sLen = words.length;

        if (pLen != sLen) {
            return false;
        }

        Map<Character, String> charMap = new HashMap<>();
        Map<String, Character> strMap = new HashMap<>();

        for (int i = 0; i < sLen; ++i) {
            char c = pattern.charAt(i);
            String word = words[i];

            if (!charMap.containsKey(c)) {
                if (strMap.containsKey(word)) {
                    return false;
                } else {
                    charMap.put(c, word);
                    strMap.put(word, c);
                }
            } else {
                if (!word.equals(charMap.get(c))) {
                    return false;
                }
            }
        }
        return true;
    }
}
