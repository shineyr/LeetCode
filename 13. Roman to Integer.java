class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> romanToInt = new HashMap<Character, Integer>() {
            {
                put('I', 1);
                put('V', 5);
                put('X', 10);
                put('L', 50);
                put('C', 100);
                put('D', 500);
                put('M', 1000);
            }
        };

        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            int curInt = romanToInt.get(s.charAt(i));

            if (i + 1 < s.length()) {
                int nextInt = romanToInt.get(s.charAt(i+1));

                if (nextInt <= curInt) {
                    total += curInt;
                } else {
                    total += (nextInt - curInt);
                    ++i;
                }
            } else {
                total += curInt;
            }
        }

        return total;
    }
}
