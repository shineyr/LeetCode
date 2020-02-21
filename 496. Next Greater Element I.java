import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * 496. Next Greater Element I
 *  You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
 *  Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 *
 * The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
 * If it does not exist, output -1 for this number.
 */
public class NO_496 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new NO_496().solution.nextGreaterElement(new int[]{4,1,2}, new int[]{1,3,4,2})));
    }

    class Solution {
        public int[] nextGreaterElement(int[] nums1, int[] nums2) {
            int[] nextGreaters = new int[nums1.length];

            Map<Integer, Integer> nextGreaterMap = new HashMap<>();
            for (int i=0; i<nums2.length; ++i) {
                for (int j=i+1; j<nums2.length; ++j) {
                    if (nums2[j] > nums2[i]) {
                        nextGreaterMap.put(nums2[i], nums2[j]);
                        break;
                    }
                }
            }

            for (int i=0; i<nums1.length; ++i) {
                if (nextGreaterMap.containsKey(nums1[i])) {
                    nextGreaters[i] = nextGreaterMap.get(nums1[i]);
                } else {
                    nextGreaters[i] = -1;
                }
            }

            return nextGreaters;
        }
    }
}
