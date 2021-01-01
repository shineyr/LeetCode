class Solution {
    public int minCost(String s, int[] cost) {
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
