class Solution {
    public int divide(int dividend, int divisor) {
        boolean isNegative = ( dividend > 0 && divisor < 0 ) || ( dividend < 0 && divisor > 0);

        int ret = 0;

        if (divisor == Integer.MIN_VALUE) {
            if (dividend == Integer.MIN_VALUE) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if (dividend == Integer.MIN_VALUE) {
            if (divisor == 1) {
                return Integer.MIN_VALUE;
            } else if (divisor == -1) {
                return Integer.MAX_VALUE;
            } else {
                ++ret;
                dividend += Math.abs(divisor);
            }
        } 
        
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);

        while (dividend >= divisor) {
            ++ret;
            dividend -= divisor;
        }

        return isNegative ? -ret : ret;
    }
}
