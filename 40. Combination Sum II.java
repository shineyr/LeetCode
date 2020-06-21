/**
 * https://leetcode.com/problems/combination-sum-ii/
 * 40. Combination Sum II
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class NO_40 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_40().solution.combinationSum2(new int[]{10,1,2,7,6,1,5}, 8));
    }

    class Solution {
        public List<List<Integer>> combinationSum2(int[] candidates, int target) {
            List<List<Integer>> combinations = new ArrayList<>();

            if (candidates.length < 1) {
                return combinations;
            }

            Arrays.sort(candidates);

            dfs(combinations, new ArrayList<>(), candidates, 0, target);

            return combinations;
        }

        public void dfs(List<List<Integer>> combinations, List<Integer> combination, int[] candidates, int idx, int diff) {

            if (diff == 0) {
                combinations.add(new ArrayList<>(combination));
                return;
            } else if (diff < 0) {
                return;
            }


            for (int i = idx; i < candidates.length; ++i) {

                if (i != idx && candidates[i] == candidates[i-1]) {
                    continue;
                }

                combination.add(candidates[i]);
                dfs(combinations, combination, candidates, i + 1, diff - candidates[i]);
                combination.remove(combination.size() - 1);
            }
        }
    }
}
