class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> positions = new HashMap<>();
            
        for (int i = 0; i < nums.length; ++i) {
            if (positions.containsKey(nums[i])) {
                int previousPos = positions.get(nums[i]);
                if (k >= (i - previousPos)) {
                    return true;
                }
            }

            positions.put(nums[i], i);
        }

        return false;
    }
}
