import java.util.Arrays;

/**
 * 1304. Find N Unique Integers Sum up to Zero
 *
 * Given an integer n, return any array containing n unique integers such that they add up to 0.
 */
public class NO_1304 {
    public int[] sumZero(int n) {
        int[] arr = new int[n];

        int middle = n / 2;

        for (int lIdx = 0; lIdx < middle; ++lIdx) {
            arr[lIdx] = lIdx - middle;
        }

        for (int idx = middle; idx < n; ++idx) {
            if (n % 2 != 0 && idx == middle) {
                arr[idx] = 0;
            } else {
                arr[idx] = 0 - arr[n-idx-1];
            }
        }

        return arr;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new NO_1304().sumZero(4)));

        System.out.println(Arrays.toString(new NO_1304().sumZero(9)));

    }
}
