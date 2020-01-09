import java.util.HashMap;
import java.util.Map;

/**
 * 1296. Divide Array in Sets of K Consecutive Numbers
 * Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive numbers
 * Return True if its possible otherwise return False.
 */

public class NO_1296 {
    public static void main(String[] args) {
        System.out.println(Solution.isPossibleDivide(new int[] {1,2,3,3,4,4,5,6}, 4));

        System.out.println(Solution.isPossibleDivide(new int[]{3,2,1,2,3,4,3,4,5,9,10,11}, 3));

        System.out.println(Solution.isPossibleDivide(new int[]{1,2,3,4}, 3));

    }

    static class Solution {
        public static boolean isPossibleDivide(int[] nums, int k) {
            if (nums.length % k != 0) {
                return false;
            }

            Map<Integer, Integer> map = new HashMap<>();
            for (int val : nums) {
                map.put(val, map.getOrDefault(val, 0) + 1);
            }

            for(int val : nums) {
                if (map.get(val) == 0) {
                    continue;
                }

                // Find the min value
                while(map.containsKey(val) && map.get(val) != 0) {
                    val--;
                }
                val += 1;
                int times = map.get(val);

                // Check whether there're subsets with k consecutive numbers start with val
                for(int i=0; i<k; ++i) {
                    if (!map.containsKey(val+i) || map.get(val+i) < times) {
                        return false;
                    }

                    map.put(val+i, map.get(val+i) - times);
                }
            }

            return true;
        }
    }
}

