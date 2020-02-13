/**
 * 461. Hamming Distance
 *
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 */
public class NO_461 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_461().solution.hammingDistance(1, 4));
    }

    class Solution {
        public int hammingDistance(int x, int y) {
            int ret = x ^ y;

            int count = 0;
            while (ret != 0) {
                if ((ret & 1) != 0) {
                    ++count;
                }

                ret >>= 1;
            }

            return count;
        }
    }
}
