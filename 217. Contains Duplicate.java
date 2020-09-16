class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> counts = new HashSet<Integer>();

        for(int i = 0; i < nums.length; ++i) {
            if (counts.contains(nums[i])) {
                return true;
            } else {
                counts.add(nums[i]);
            }
        }

        return false;
    }

    public boolean containsDuplicate1(int[] nums) {
        Arrays.sort(nums);

        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }

        return false;
    }
}
