class Solution {
    public int findMin(int[] nums) {
        int len = nums.length;
        
        if (len == 1) {
            return nums[0];
        }
        
        int left = 0, right = len - 1;
        
        if (nums[left] < nums[right]) {
            return nums[left];
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                --right;
            }
        }
        
        return nums[right];
    }
}
