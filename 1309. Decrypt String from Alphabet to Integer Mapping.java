/**
 * 1309. Decrypt String from Alphabet to Integer Mapping
 *
 * Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:
 *
 *     Characters ('a' to 'i') are represented by ('1' to '9') respectively.
 *     Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
 *
 * Return the string formed after mapping.
 *
 * It's guaranteed that a unique mapping will always exist.
 */
public class NO_1309 {
    Solution solution = new Solution();


    public static void main(String[] args) {
        System.out.println(new NO_1309().solution.freqAlphabets("10#11#12"));

        System.out.println(new NO_1309().solution.freqAlphabets("1326#"));

        System.out.println(new NO_1309().solution.freqAlphabets("25#"));

    }

    class Solution {
        public String freqAlphabets(String s) {
            String ret = "";

            for (int i=0; i<s.length(); ) {
                if (i+1 < s.length() && i+2 < s.length() && s.charAt(i+2) == '#') {
                        int tmp = (s.charAt(i) - '0') * 10 + (s.charAt(i+1) - '0');

                        char c = (char) ('a' + tmp - 1);
                        ret += c;

                        i+=3;
                } else {
                    int tmp = (s.charAt(i) - '0');
                    char c = (char) ('a' + tmp - 1);
                    ret += c;

                    i++;
                }
            }

            return ret;
        }

    }
}
