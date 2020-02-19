import java.util.ArrayList;
import java.util.List;

/**
 * 78. Subsets
 *
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 */
public class NO_78 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_78().solution.subsets(new int[] {1,2,3}));
    }

    class Solution {
        public List<List<Integer>> subsets(int[] nums) {
            List<List<Integer>> res = new ArrayList<>();

            dfs(res, new ArrayList<>(), 0, nums);

            return res;
        }

        private void dfs(List<List<Integer>> res, List<Integer> subnet, int idx, int[] nums) {
            res.add(subnet);

            for (int j = idx; j < nums.length; ++j) {
                List<Integer> newSubnet = new ArrayList<>(subnet);
                newSubnet.add(nums[j]);

                dfs(res, newSubnet, j+1, nums);
            }
        }
    }
}
