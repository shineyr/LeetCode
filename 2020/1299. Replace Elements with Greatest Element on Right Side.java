import java.util.Arrays;

/**
 * 1299. Replace Elements with Greatest Element on Right Side
 *
 * Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
 *
 * After doing so, return the array.
 */
public class NO_1299 {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Solution().replaceElements(new int[] {17,18,5,4,6,1})));
    }
}


class Solution {
    public int[] replaceElements(int[] arr) {
        int len = arr.length, maxValue = arr[len-1];

        for (int i = len-1; i>=0; --i) {
            if (i == len - 1) {
                arr[i] = -1;
                continue;
            }

            int curValue = arr[i];

            arr[i] = maxValue;

            maxValue = Math.max(maxValue, curValue);

        }
        return arr;
    }
}
