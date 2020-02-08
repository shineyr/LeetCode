import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * 15. 3Sum
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 */
public class NO_15 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_15().solution.threeSum(new int[] {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6}));
    }

    private class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            List<List<Integer>> ret = new ArrayList<>();

            Arrays.sort(nums);

            for (int i=0; i<nums.length; ++i) {
                if (i > 0 && nums[i] == nums[i-1]) {
                    continue;
                }

                int lIdx = i+1, rIdx = nums.length - 1;

                while (lIdx < rIdx) {
                    int sum = nums[i] + nums[lIdx] + nums[rIdx];
                    if (sum == 0) {
                        ret.add(Arrays.asList(nums[i], nums[lIdx], nums[rIdx]));

                        // 跳过重复元素
                        while(lIdx < rIdx && nums[lIdx+1] == nums[lIdx]) {
                            lIdx++;
                        }

                        while (rIdx > lIdx && nums[lIdx-1] == nums[rIdx]) {
                            --rIdx;
                        }
                        
                        lIdx++;
                        rIdx--;
                    } else if (sum < 0) {
                        lIdx++;
                    } else {
                        rIdx--;
                    }
                }
            }

            return ret;
        }



        /**
         * 低效不可取
         */
        public List<List<Integer>> threeSum1(int[] nums) {
            List<List<Integer>> ret = new ArrayList<>();

            for (int i=0; i<nums.length-1; ++i) {
                int key = nums[i];

                List<List<Integer>> twoSums = twoSum(Arrays.copyOfRange(nums, i+1, nums.length),
                        0 - key);

                if (twoSums.isEmpty()) {
                    continue;
                }

                for (List<Integer> list : twoSums) {
                    List<Integer> threeSumList = new ArrayList<>();
                    threeSumList.add(key);
                    threeSumList.addAll(list);

                    if (!isExist(ret, threeSumList)) {
                        ret.add(threeSumList);
                    }
                }
            }


            return ret;
        }

        private boolean isExist(List<List<Integer>> lists, List<Integer> list) {
            for (List<Integer> iList : lists) {
                if (iList.size() != list.size()) {
                    continue;
                }

                iList.sort(Integer::compare);
                list.sort(Integer::compareTo);

                boolean flag = true;
                for (int i=0; i< iList.size(); ++i) {
                    if (iList.get(i) != list.get(i)) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    return true;
                }
            }

            return false;
        }

        private List<List<Integer>> twoSum(int[] nums, int target) {
            Map<Integer, Integer> numsMap = new HashMap<>();
            for (Integer num : nums) {
                numsMap.put(num, numsMap.getOrDefault(num, 0) + 1);
            }

            Map<Integer, List<Integer>> sumsMap = new HashMap<>();

            for (Integer key : nums) {
                if (numsMap.get(key) <= 0 || sumsMap.containsKey(key)) {
                    continue;
                }
                numsMap.put(key, numsMap.get(key) - 1);

                int num = target - key;
                if (numsMap.containsKey(num) && numsMap.get(num) > 0) {
                    sumsMap.put(key, Arrays.asList(key, num));

                    numsMap.put(num, numsMap.get(num) - 1);
                }
            }
            return sumsMap.values().stream().collect(Collectors.toList());
        }

    }
}
