class Solution {
    public String addBinary(String a, String b) {
        if (a == null || a.isEmpty()) {
            return b;
        }

        if (b == null || b.isEmpty()) {
            return a;
        }

        int aIdx = a.length() - 1, bIdx = b.length() - 1;

        StringBuilder sum = new StringBuilder();
        int carry = 0;
        while (aIdx >= 0 || bIdx >= 0) {
            int unitSum;

            if (aIdx >= 0 && bIdx >= 0) {
                unitSum = (a.charAt(aIdx) - '0') + (b.charAt(bIdx) - '0') + carry;
                --aIdx;
                --bIdx;
            } else if (aIdx >= 0) {
                unitSum = (a.charAt(aIdx) - '0') + carry;
                --aIdx;
            } else if (bIdx >= 0) {
                unitSum = (b.charAt(bIdx) - '0') + carry;
                --bIdx;
            } else {
                break;
            }

            if (unitSum >= 2) {
                unitSum -= 2;
                carry = 1;
            } else {
                carry = 0;
            }

            sum.append(unitSum);
        }

        if (carry == 1) {
            sum.append('1');
        }

        return sum.reverse().toString();
    }      
}
