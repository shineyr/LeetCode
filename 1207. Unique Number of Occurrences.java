import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * 1207. Unique Number of Occurrences
 * Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.
 */
public class NO_1207 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_1207().solution.uniqueOccurrences(new int[] {1,2,2,1,1,3}));

        System.out.println(new NO_1207().solution.uniqueOccurrences(new int[] {1,2}));

        System.out.println(new NO_1207().solution.uniqueOccurrences(new int[] {-3,0,1,-3,1,1,1,-3,10,0}));
    }

    class Solution {
        public boolean uniqueOccurrences(int[] arr) {
            Map<Integer, Integer> map = new HashMap<>();

            for (int num : arr) {
                if (map.containsKey(num)) {
                    map.put(num, map.get(num) + 1);
                } else {
                    map.put(num, 1);
                }
            }

            Set<Integer> set = new HashSet<>();
            for (int val : map.values()) {
                if (set.contains(val)) {
                    return false;
                } else {
                    set.add(val);
                }
            }

            return true;
        }
    }
}
