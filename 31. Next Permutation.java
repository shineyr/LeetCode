
/**
 * 31. Next Permutation
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 */
public class NO_31 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        new NO_31().solution.nextPermutation(new int[] {1, 5, 1});
    }

    class Solution {
        public void nextPermutation(int[] nums) {
            int len = nums.length;

            // Step 1: 从尾向前找最后一个降序元素，如【1 3 5 4 2】中的5
            int i = len - 1;
            while(i > 0 && nums[i-1] >= nums[i]) {
                --i;
            }

            // Step 2：将其前置元素与第一个大于它的元素交换，【1 4 5 3 2】
            if (i != 0) {
                int previous = nums[i-1];

                int j = len-1;
                while (j >= i && nums[j] <= previous) {
                    --j;
                }

                nums[i-1] = nums[j];
                nums[j] = previous;
            }

            // Step3：将该元素至尾部逆序，【1 5 2 3 5】
            int k = len - 1;
            while (i < k) {
                int tmp = nums[k];
                nums[k] = nums[i];
                nums[i] = tmp;

                ++i;
                --k;
            }

        }
    }

}
