/**
 * 1300. Sum of Mutated Array Closest to Target
 *
 * Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.
 *
 * In case of a tie, return the minimum such integer.
 *
 * Notice that the answer is not necessarily a number from arr.
 */
public class NO_1300 {
    public int findBestValue(int[] arr, int target) {
        int bestValue = target / arr.length;

        int minGap = Math.abs(target - sum(arr, bestValue));

        while (true) {
            int nextValue = bestValue + 1;

            int curGap = Math.abs(target - sum(arr, nextValue));

            if(curGap >= minGap) {
                return bestValue;
            } else {
                minGap = curGap;
                bestValue = nextValue;
            }
        }
    }

    public int sum(int[] arr, int bestValue) {
        int sum = 0;
        for(int i = 0; i < arr.length; ++i) {
            if (arr[i] > bestValue) {
                sum += bestValue;
            } else {
                sum += arr[i];
            }
        }

        return sum;
    }

    public static void main(String[] args) {

        System.out.println(new NO_1300().findBestValue(new int[] {4,9,3}, 10));

        System.out.println(new NO_1300().findBestValue(new int[] {2,3,5}, 10));

        System.out.println(new NO_1300().findBestValue(new int[] {60864,25176,27249,21296,20204}, 56803));
    }
}
