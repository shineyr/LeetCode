import java.util.HashSet;
import java.util.Set;

/**
 * 992. Subarrays with K Different Integers
 *
 * Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.
 *
 * (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
 *
 * Return the number of good subarrays of A.
 */
public class NO_992 {

    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_992().solution.subarraysWithKDistinct(new int[]{1,2,1,2,3}, 2));

        System.out.println(new NO_992().solution.subarraysWithKDistinct(new int[]{1,2,1,3,4}, 3));

    }

    class Solution {
        public int subarraysWithKDistinct(int[] A, int K) {
            int len = A.length;
            Set<Integer> uniqueValues = new HashSet<>();

            int count = 0;
            for (int i=0; i< len; ++i) {
                uniqueValues.clear();
                uniqueValues.add(A[i]);

                for (int j=i; j< len; j++) {
                    if (uniqueValues.size() > K) {
                        break;
                    }

                    if (uniqueValues.contains(A[j])) {
                        if (uniqueValues.size() == K) {
                            ++count;
                        }
                        continue;
                    }

                    uniqueValues.add(A[j]);

                    if (uniqueValues.size() == K) {
                        ++count;
                    }

                }
            }
            return count;
        }
    }
}
