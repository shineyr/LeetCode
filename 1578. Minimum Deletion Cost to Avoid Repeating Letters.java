class Solution {
    public int minCost(String s, int[] cost) {
        int sLen = s.length();
        if (sLen <= 1) {
            return 0;
        }
        
        int sumCost = 0;
        
        for (int i = 0; i < sLen-1; ++i) {
            if (s.charAt(i+1) == s.charAt(i)) {
                sumCost += Math.min(cost[i], cost[i+1]);
                
                cost[i+1] = Math.max(cost[i], cost[i+1]);
            }
        }
        
        return sumCost;
    }
    
    public int minCost1(String s, int[] cost) {
        int sLen = s.length();
        if (sLen <= 1) {
            return 0;
        }
        
        int sumCost = 0;
        
        for (int i = 0; i < sLen; ) {
            char c = s.charAt(i);
            
            int j = i + 1;
            while(j < sLen && s.charAt(j) == c) {
                ++j;
            }
            
            if (j == i + 1) {
                i = j;
                continue;
            }
            
            int maxCost = 0;
            for (int dup = i; dup < j; ++dup) {
                maxCost = Math.max(maxCost, cost[dup]);
                sumCost += cost[dup];
            }
            
            sumCost -= maxCost;
            
            
            i = j;
        }
        
        return sumCost;
    }
}
