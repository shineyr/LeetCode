/**
 * https://leetcode.com/problems/subsets-ii/
 * 90. Subsets II
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class NO_90 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_90().solution.subsetsWithDup(new int[]{1,2,2}));
    }

    class Solution {
        public List<List<Integer>> subsetsWithDup(int[] nums) {
            if (nums.length < 1) {
                return Collections.emptyList();
            }

            Arrays.sort(nums);
            List<List<Integer>> result = new ArrayList<>();

            dfs(result, new ArrayList<>(), nums, 0);

            return result;
        }

        public void dfs(List<List<Integer>> res, List<Integer> subset, int[] nums, int idx) {
            if (!res.contains(subset)) {
                res.add(subset);
            }

            for (int j = idx; j < nums.length; ++j) {
                List<Integer> nextSubset = new ArrayList<>(subset);
                nextSubset.add(nums[j]);

                dfs(res, nextSubset, nums, j + 1);
            }
        }
    }
}
