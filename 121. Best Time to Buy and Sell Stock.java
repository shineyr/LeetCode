class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        
        if (len <= 1) {
            return 0;
        }
        
        int bestBuy = prices[0], maxProfit = 0;
        
        for (int i = 1; i < len; ++i) {
            bestBuy = Math.min(bestBuy, prices[i]);
            
            int curProfit = prices[i] > bestBuy ? prices[i] - bestBuy : 0;
            
            maxProfit = Math.max(curProfit, maxProfit);
        }
        
        return maxProfit;
    }
}
