class Solution {
    public boolean isHappy(int n) {
        if (n <= 0) {
            return false;
        }
        
        if (n == 1) {
            return true;
        }
        
        int sum = n;
        while(sum != 1) {
            sum = squareSum(sum);
            
            // loops endlessly in a cycle
            if (sum == n || sum == 4) {
                return false;
            }
        }
        
        return true;
    }
    
    private int squareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            
            sum += digit * digit;
            
            n /= 10;
        }
        
        return sum;
    }
}
