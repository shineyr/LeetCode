import java.util.HashMap;
import java.util.Map;

/**
 * 1224. Maximum Equal Frequency
 *
 * Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.
 *
 * If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).
 */
public class NO_1224 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_1224().solution.maxEqualFreq(new int[] {2,2,1,1,5,3,3,5}));

        System.out.println(new NO_1224().solution.maxEqualFreq(new int[] {1,1,1,2,2,2,3,3,3,4,4,4,5}));

        System.out.println(new NO_1224().solution.maxEqualFreq(new int[] {1,1,1,2,2,2}));

        System.out.println(new NO_1224().solution.maxEqualFreq(new int[] {10,2,8,9,3,8,1,5,2,3,7,6}));

    }

    class Solution {
        public int maxEqualFreq(int[] nums) {
            Map<Integer, Integer> timesOfNumMap = new HashMap<>();

            for (int num : nums) {
                timesOfNumMap.put(num, timesOfNumMap.getOrDefault(num, 0) + 1);
            }

            Map<Integer, Integer> countOfTimesMap = new HashMap<>();
            for (int times: timesOfNumMap.values()) {
                countOfTimesMap.put(times, countOfTimesMap.getOrDefault(times, 0) + 1);
            }

            for (int idx = nums.length - 1; idx >= 0; --idx) {
                if (isValid(countOfTimesMap)) {
                    return idx + 1;
                }

                int num = nums[idx];
                int count = timesOfNumMap.get(num);

                timesOfNumMap.put(num, timesOfNumMap.get(num) - 1);

                countOfTimesMap.put(count, countOfTimesMap.get(count) - 1);

                if (countOfTimesMap.get(count) == 0) {
                    countOfTimesMap.remove(count);
                }

                if (count > 1) {
                    countOfTimesMap.put(count - 1, countOfTimesMap.getOrDefault(count - 1, 0) + 1);
                }
            }

            return 0;
        }

        private boolean isValid(Map<Integer, Integer> countOfTimesMap) {
            if (countOfTimesMap.size() == 1) {
                return countOfTimesMap.keySet().contains(1) || countOfTimesMap.values().contains(1);
            }

            if (countOfTimesMap.size() != 2) {
                return false;
            }

            int smallerCount = Integer.MAX_VALUE;
            int largerCount = Integer.MIN_VALUE;
            for (int count : countOfTimesMap.keySet()) {
                smallerCount = Math.min(smallerCount, count);
                largerCount = Math.max(largerCount, count);
            }
            // [2, 3, 3, 1] or [2, 2, 1, 3, 3]
            return (largerCount - smallerCount == 1 && countOfTimesMap.get(largerCount) == 1)
                    || (smallerCount == 1 && countOfTimesMap.get(smallerCount) == 1);

        }
    }
}
