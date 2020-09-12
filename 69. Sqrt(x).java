class Solution {
    public int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        long low = 1, high = x / 2;

        while (low <= high) {
            long mid = low + (high - low) / 2;
            if (mid * mid == x) {
                return (int) mid;
            } else if (mid * mid < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int) (low - 1);
    }
    
    public int mySqrt1(int x) {
        return (int) Math.sqrt(x);
    }
}
