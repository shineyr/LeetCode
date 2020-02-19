import java.util.ArrayList;
import java.util.List;

/**
 * 46. Permutations
 * Given a collection of distinct integers, return all possible permutations.
 */
public class NO_46 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_46().solution.permute(new int[] {1, 1, 3}));
    }

    class Solution {
        public List<List<Integer>> permute(int[] nums) {
            List<List<Integer>> permutations = new ArrayList<>();

            boolean[] visited = new boolean[nums.length];
            for (int i=0; i<nums.length; ++i) {
                visited[i] = false;
            }

            dfs(permutations, new ArrayList<>(), visited, 0, nums);

            return permutations;
        }

        public void dfs(List<List<Integer>> permutations, List<Integer> permutation, boolean[] visited, int level, int[] nums) {
            if (level == nums.length) {
                permutations.add(new ArrayList<>(permutation));
                return;
            }

            for (int idx=0; idx < nums.length; ++idx) {
                if (!visited[idx]) {
                    permutation.add(nums[idx]);
                    visited[idx] = true;
                    dfs(permutations, permutation, visited, level + 1, nums);
                    permutation.remove(permutation.size() - 1);
                    visited[idx] = false;
                }
            }
        }
    }
}
