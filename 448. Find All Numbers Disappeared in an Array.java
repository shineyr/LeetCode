import java.util.ArrayList;
import java.util.List;

/**
 * 448. Find All Numbers Disappeared in an Array
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 */
public class NO_448 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_448().solution.findDisappearedNumbers(new int[] {4,3,2,7,8,2,3,1}));
    }

    class Solution {
        public List<Integer> findDisappearedNumbers(int[] nums) {
            for (int i=0; i<nums.length; ++i) {
                while (nums[i] != i+1 && nums[nums[i] - 1] != nums[i]) {
                    int cur = nums[i];
                    nums[i] = nums[cur - 1];
                    nums[cur - 1] = cur;
                }
            }

            List<Integer> numbers = new ArrayList<>();
            for (int i=0; i<nums.length; ++i) {
                if (nums[i] != i+1) {
                    numbers.add(i+1);
                }
            }

            return numbers;
        }
    }

}
