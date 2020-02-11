import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 39. Combination Sum
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of times.
 *
 * Note:
 *
 *     All numbers (including target) will be positive integers.
 *     The solution set must not contain duplicate combinations.
 */
public class NO_39 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_39().solution.combinationSum(new int[] {8,7,4,3}, 11));
    }

    class Solution {
        public List<List<Integer>> combinationSum(int[] candidates, int target) {
            List<List<Integer>> combinations = new ArrayList<>();

            Arrays.sort(candidates);

            dfs(combinations, new ArrayList<>(), candidates[0], candidates, target);

            return combinations;
        }

        public void dfs(List<List<Integer>> combinations, List<Integer> combination, int candidate, int[] candidates, int target) {
            if (0 == target) {
                combinations.add(new ArrayList<>(combination));
                return;
            } else if (0 > target) {
                return;
            }

            for (int num : candidates) {
                if (num < candidate) {
                    continue;
                }

                combination.add(num);

                dfs(combinations, combination, num, candidates, target - num);

                combination.remove(combination.size() - 1);
            }
        }

    }
}
