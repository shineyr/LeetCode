class Solution {
    public int maxProfit1(int[] prices) {
        int maxProfit = 0;
        
        for (int i = 0; i < prices.length; ++i) {
            if (i > 0 && prices[i] > prices[i-1]) {
                maxProfit += (prices[i] - prices[i-1]);
            }
        }
        
        return maxProfit;
    }
    
    public int maxProfit(int[] prices) {
        
        int valley = 0, peak = 0, maxProfit = 0;
        
        for (int i = 0; i < prices.length - 1; ) {
            while(i < prices.length - 1 && prices[i] > prices[i+1]) {
                ++i;
            }
            
            valley = prices[i];
            
            while(i < prices.length - 1 && prices[i] <= prices[i+1]) {
                ++i;
            }
            
            peak = prices[i];
            
            maxProfit += (peak - valley);
        }
        
        return maxProfit;
    }
}
