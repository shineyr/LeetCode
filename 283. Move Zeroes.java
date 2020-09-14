class Solution {
    public void moveZeroes1(int[] nums) {
        int len = nums.length;

        int lastNonZeroIdx = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != 0) {
                nums[lastNonZeroIdx++] = nums[i];
            }
        }

        while (lastNonZeroIdx < len) {
            nums[lastNonZeroIdx++] = 0;
        }
    }

    public void moveZeroes(int[] nums) {
        int len = nums.length;
        int lastNonZeroIdx = 0;

        for (int i = 0; i < len; ++i) {
            if (nums[i] != 0) {
                if (lastNonZeroIdx == i) {
                    ++lastNonZeroIdx;
                    continue;
                }

                int temp = nums[lastNonZeroIdx];
                nums[lastNonZeroIdx++] = nums[i];
                nums[i] = temp;
            }
        }
    }
}
