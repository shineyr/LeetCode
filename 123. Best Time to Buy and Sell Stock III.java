class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if (len < 1) {
            return 0;
        }
        
        int[] profit1 = new int[len];
        int[] profit2 = new int[len];
        profit1[0] = 0;
        profit2[len-1] = 0;
        
        int p1Min = prices[0], p2Max = prices[len - 1];
        
        for (int i = 1; i < len; ++i) {
            profit1[i] = Math.max(profit1[i - 1], prices[i] - p1Min);
            p1Min = Math.min(p1Min, prices[i]);
            
            int right = len - 1 - i;
            profit2[right] = Math.max(profit2[right + 1], p2Max - prices[right]);
            p2Max = Math.max(p2Max, prices[right]);
        }
        
        int maxProfit = 0;
        for (int i = 0; i < len; ++i) {
            maxProfit = Math.max(maxProfit, profit1[i] + profit2[i]);
        }
        
        return maxProfit;
    }
    
    // Solution 1: TLE
    public int maxProfit1(int[] prices) {
        
        int maxProfit = 0;
        for (int i = 0; i < prices.length; ++i) {
            int curProfit1 = maxProfixOneTransaction(prices, 0, i);
            int curProfit2 = maxProfixOneTransaction(prices, i+1, prices.length - 1);
            
            maxProfit = Math.max(maxProfit, curProfit1 + curProfit2);
        }
        
        return maxProfit;
    }
    
    private int maxProfixOneTransaction(int[] prices, int start, int end) {
        if (start > end || end > prices.length - 1) {
            return 0;
        }
        
        int bestBuy = prices[start], maxProfit = 0;
        
        for(int i = start + 1; i <= end; ++i) {
            if (prices[i] < bestBuy) {
                bestBuy = prices[i];
            }
            
            int curProfit = prices[i] > bestBuy ? prices[i] - bestBuy : 0;

            maxProfit = Math.max(maxProfit, curProfit);
        }
        
        return maxProfit;
    }
}
