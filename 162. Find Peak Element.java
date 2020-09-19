class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0, right = nums.length - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
    public int findPeakElement2(int[] nums) {
        for (int i = 0; i < nums.length; ++i) {
            if (i == nums.length - 1 || nums[i] > nums[i + 1]) {
                return i;
            }
        }
        
        return nums.length - 1;
    }
    
    public int findPeakElement1(int[] nums) {
        int len = nums.length;
        
        if (len == 0) {
            return -1;
        } 
        
        int idx = 0;
        
        for (int i = 1; i < len; ++i) {
            if (nums[i] > nums[i-1] && (i+1) < len && nums[i+1] < nums[i]) {
                return i;
            } else if (nums[i] > nums[i-1]) {
                idx = i;
            }
        }
        
        return idx;
    }
}
