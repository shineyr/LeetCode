class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        int[] counts = new int[26];

        for (char c : s.toCharArray()) {
            counts[c - 'a'] += 1;
        }

        for (char c : t.toCharArray()) {
            counts[c - 'a'] -= 1;

            if (counts[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }

    public boolean isAnagram1(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();

        Arrays.sort(sArr);
        Arrays.sort(tArr);

        return Arrays.equals(sArr, tArr);
    }
}
