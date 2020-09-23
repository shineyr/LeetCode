class Solution {
    //https://www.youtube.com/watch?v=cfdwhSmLt3w
    public int jump(int[] nums) {
        int len = nums.length;

        if (len <= 1 || nums[0] == 0) {
            return 0;
        }

        int minJumps = 1, farthest = nums[0], curEnd = nums[0];

        for (int i = 1; i < len; ++i) {
            if (i == len - 1) {
                return minJumps;
            }

            farthest = Math.max(farthest, i + nums[i]);

            if (i == curEnd) {
                ++minJumps;
                curEnd = farthest;
            }
        }

        return minJumps;
    }
}
