class Solution {
    public String intToRoman(int num) {
        String[] units = new String[] {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        String[] tens = new String[] {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String[] hundreds = new String[] {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String[] thousands = new String[] {"", "M", "MM", "MMM"};

        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + units[num % 10];
    }

    public String intToRoman1(int num) {
        int[] values = new int[] {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] romans = new String[] {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        StringBuilder roman = new StringBuilder();
        for (int i = 0; i < values.length; ++i) {
            while (num >= values[i]) {
                roman.append(romans[i]);
                num -= values[i];
            }
        }

        return roman.toString();
    }
}
