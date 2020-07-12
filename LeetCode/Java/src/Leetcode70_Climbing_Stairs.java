public class Leetcode70_Climbing_Stairs {


    public static int climbStairs(int n) {
        if (n < 3) return n;

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }

    public static void main(String[] args) {
        // write your code here
        int n = 5;
        int answer = climbStairs(n);
        System.out.print(answer);
    }
}
