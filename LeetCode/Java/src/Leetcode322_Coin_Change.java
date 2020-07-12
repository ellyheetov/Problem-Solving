import java.util.Arrays;

public class Leetcode322_Coin_Change {

    public static int coinChange(int[] coins, int amount) {
        int max = amount + 1;
        int[] dp = new int[amount + 1];

        Arrays.fill(dp, max);
        Arrays.sort(coins);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (i - coins[j] < 0) break;
                dp[i] = Math.min(1 + dp[i - coins[j]], dp[i]);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }


    public static void main(String[] args) {
        // write your code here
        int[] coins = {1, 2, 5};
        int answer = coinChange(coins, 11);
        System.out.print(answer);
    }
}
