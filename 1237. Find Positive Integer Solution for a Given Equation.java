import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 1237. Find Positive Integer Solution for a Given Equation
 *
 * Given a function  f(x, y) and a value z, return all positive integer pairs x and y where f(x,y) == z.
 *
 * The function is constantly increasing, i.e.:
 *
 *     f(x, y) < f(x + 1, y)
 *     f(x, y) < f(x, y + 1)
 *
 * The function interface is defined like this:
 *
 * interface CustomFunction {
 * public:
 *   // Returns positive integer f(x, y) for any given positive integer x and y.
 *   int f(int x, int y);
 * };
 *
 * For custom testing purposes you're given an integer function_id and a target z as input, where function_id represent one function from an secret internal list, on the examples you'll know only two functions from the list.
 *
 * You may return the solutions in any order.
 */
public class NO_1237 {

    /*
     * // This is the custom function interface.
     * // You should not implement it, or speculate about its implementation
     * class CustomFunction {
     *     // Returns f(x, y) for any given positive integers x and y.
     *     // Note that f(x, y) is increasing with respect to both x and y.
     *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
     *     public int f(int x, int y);
     * };
     */

    class Solution {
        public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
            List<List<Integer>> results = new ArrayList<>();
            /*for (int x=1; x<=1000; ++x) {
                for (int y=1; y<=1000; ++y) {
                    if (customfunction.f(x, y) == z) {
                        results.add(Arrays.asList(x, y));
                    }
                }
            }*/

            for(int x=1; x<=1000; ++x) {
                int l = 1, r = 1000;
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    int ret = customfunction.f(x, mid);
                    if (ret == z) {
                        results.add(Arrays.asList(x, mid));
                        break;
                    }

                    if (mid == l || mid == r) {
                        break;
                    }

                    if (ret < z) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
            }

            return results;
        }
    }
}

