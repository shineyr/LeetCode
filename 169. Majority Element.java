class Solution {
    public int majorityElement(int[] nums) {
        int len = nums.length;
        
        int majority = nums[0], count = 1;
        
        for (int i = 1; i < len; ++i) {
            if (count == 0) {
                majority = nums[i];
                count = 1;
                continue;
            }
            
            if (nums[i] == majority) {
                ++count;
            } else {
                --count;
            }
        }
        
        return majority;
    }
}
