class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] product = new int[len];
        product[0] = 1;

        for (int i = 1; i < len; ++i) {
            product[i] = product[i-1] * nums[i-1];
        }

        int rightMultiple = 1;
        for (int j = len - 1; j >= 0; --j) {
            product[j] *= rightMultiple;

            rightMultiple *= nums[j];
        }

        return product;
    }

    public int[] productExceptSelf1(int[] nums) {
        int len = nums.length;
        int[] product = new int[len];

        int[] leftProduct = new int[len];
        leftProduct[0] = 1;

        int[] rightProduct = new int[len];
        rightProduct[len - 1] = 1;

        for (int i = 1; i < len; ++i) {
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
        }

        for (int j = len-2; j >= 0; --j) {
            rightProduct[j] = rightProduct[j+1] * nums[j+1];
        }

        for (int i = 0; i < len; ++i) {
            product[i] = leftProduct[i] * rightProduct[i];
        }

        return product;
    }
}
