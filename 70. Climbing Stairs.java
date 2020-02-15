/**
 * 70. Climbing Stairs
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 * Note: Given n will be a positive integer.
 */
public class NO_70 {
    private Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_70().solution.climbStairs(3));
    }

    class Solution {
        public int climbStairs(int n) {
            if (n == 0) {
                return 1;
            }

            if (n == 1) {
                return 1;
            }

            int[] dp = new int[n+1];
            dp[0] = 1;
            dp[1] = 1;

            for (int i=2; i<=n; ++i) {
                dp[i] = dp[i-1] + dp[i-2];
            }

            return dp[n];
        }
    }
}
