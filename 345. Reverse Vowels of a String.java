class Solution {
    public String reverseVowels(String s) {
        Set<Character> vowels = new HashSet<>();
        vowels.addAll(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));

        int left = 0, right = s.length() - 1;
        char[] chars = s.toCharArray();

        while (left < right) {
            if (!vowels.contains(chars[left])) {
                ++left;
                continue;
            }

            if (!vowels.contains(chars[right])) {
                --right;
                continue;
            }

            char tmp = chars[left];
            chars[left++] = chars[right];
            chars[right--] = tmp;
        }

        return String.valueOf(chars);
    }
}
