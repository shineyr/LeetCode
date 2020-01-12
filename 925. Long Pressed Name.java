/**
 * 925. Long Pressed Name
 *
 * Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
 *
 * You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
 *
 */
public class NO_925 {

    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_925().solution.isLongPressedName("alex", "aaleex"));

        System.out.println(new NO_925().solution.isLongPressedName("saeed", "ssaaedd"));


    }

    class Solution {
        public boolean isLongPressedName(String name, String typed) {

            int j = 0;
            for (int i=0; i<name.length(); ++i) {
                if (j >= typed.length() || name.charAt(i) != typed.charAt(j)) {
                    return false;
                }

                j++;

                if (i != name.length() - 1 && name.charAt(i) == name.charAt(i+1)) {
                    continue;
                }

                while (j < typed.length()) {
                    if (typed.charAt(j) == name.charAt(i)) {
                        j++;
                    } else {
                        break;
                    }
                }
            }

            if (j != typed.length()) {
                return false;
            }

            return true;
        }
    }
}
