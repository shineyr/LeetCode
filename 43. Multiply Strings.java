class Solution {
    public String multiply(String num1, String num2) {
        if (num1.isEmpty() || num2.isEmpty()) {
            return "0";
        }

        int[] result = new int[num1.length() + num2.length()];

        int r1Pos = 0, r2Pos = 0;
        for (int i = num1.length() - 1; i >= 0; --i) {
            r2Pos = 0;
            int carry = 0;

            for (int j = num2.length() - 1; j >= 0; --j) {
                int product = result[r1Pos + r2Pos] + ((num1.charAt(i) - '0') * (num2.charAt(j) - '0')) + carry;

                result[r1Pos + r2Pos] = product % 10;
                carry = product / 10;
                ++r2Pos;
            }

            if (carry != 0) {
                result[r1Pos + r2Pos] += carry;
            }
            ++r1Pos;
        }

        int idx = result.length - 1;
        while (idx >= 0 && result[idx] == 0 ) {
            --idx;
        }

        if (idx == -1) {
            return "0";
        }

        StringBuilder strResult = new StringBuilder();
        while (idx >= 0) {
            strResult.append(result[idx]);
            --idx;
        }

        return strResult.toString();
    }
}
