import java.util.Arrays;

public class Leetcode377_Combination_Sum_IV {

    public static int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        Arrays.fill(dp,0);

        Arrays.sort(nums);
        dp[0] =1;
        for (int i = 1; i < dp.length; i++) {
            for (int num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {1, 2, 3};
        int target = 4;
        int answer = combinationSum4(nums, target);

        System.out.print(answer);
    }
}
