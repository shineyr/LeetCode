class Solution {
    public int[] twoSum(int[] numbers, int target) {
        
        int beg = 0, end = numbers.length - 1;
        
        while(beg < end) {
            int sum = numbers[beg] + numbers[end];
            
            if (sum == target) {
                break;
            } else if (sum > target) {
                --end;
            } else {
                ++beg;
            }
        }
        
        return new int[] {beg + 1, end + 1};
    }
}
