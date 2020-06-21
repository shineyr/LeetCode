import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * https://leetcode.com/problems/4sum/
 * 18. 4Sum
 */
public class NO_18 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_18().solution.fourSum(new int[]{1, 0, -1, 0, -2, 2}, 0));
    }

    class Solution {
        public List<List<Integer>> fourSum(int[] nums, int target) {
            Arrays.sort(nums);

            return kSum(nums, target, 0, 4);
        }

        public List<List<Integer>> kSum(int[] nums, int target, int start, int k) {
            List<List<Integer>> res = new ArrayList<>();

            if (start == nums.length || nums[start] * k > target || nums[nums.length - 1] * k < target) {
                return res;
            }

            if (k == 2) {
                return twoSum(nums, target, start);
            }

            for (int i = start; i < nums.length; ++i) {
                if (i > start && nums[i] == nums[i-1]) {
                    continue;
                }

                List<List<Integer>> subSets = kSum(nums, target - nums[i], i + 1, k-1);
                for (List<Integer> subSet : subSets) {
                    List<Integer> set = new ArrayList<>();
                    set.add(nums[i]);
                    set.addAll(subSet);

                    res.add(set);
                }
            }

            return res;
        }

        public List<List<Integer>> twoSum(int[] nums, int target, int start) {
            List<List<Integer>> res = new ArrayList<>();

            int low = start, high = nums.length - 1;
            while (low < high) {
                int sum = nums[low] + nums[high];

                if (sum < target || (low > start && nums[low] == nums[low - 1])) {
                    ++low;
                } else if (sum > target || (high < nums.length - 1 && nums[high + 1] == nums[high])) {
                    --high;
                } else {
                    res.add(Arrays.asList(nums[low++], nums[high--]));
                }
            }

            return res;
        }
    }
}
