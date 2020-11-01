class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Character> map = new HashMap<>();

        for (int i = 0; i < s.length(); ++i) {
            char sChar = s.charAt(i);
            char tChar = t.charAt(i);

            if (!map.containsKey(sChar) && !map.containsValue(tChar)) {
                map.put(sChar, tChar);
            }

            if (map.get(sChar) == null || map.get(sChar) != tChar) {
                return false;
            }
        }

        return true;
    }
}
