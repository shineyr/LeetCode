import java.util.Arrays;

/**
 * 739. Daily Temperatures
 *  Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.
 *  If there is no future day for which this is possible, put 0 instead.
 *
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 */
public class NO_739 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new NO_739().solution.dailyTemperatures(new int[]{73, 74, 75, 71, 69, 72, 76, 73})));
    }

    class Solution {
        public int[] dailyTemperatures(int[] T) {
            int[] nextWarmers = new int[T.length];
            Arrays.fill(nextWarmers, 0);

            for (int i=0; i<T.length; ++i) {
                for (int j=i+1; j<T.length; ++j) {
                    if (T[j] > T[i]) {
                        nextWarmers[i] = j - i;
                        break;
                    }
                }
            }

            return nextWarmers;
        }
    }
}
