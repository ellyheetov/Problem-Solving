import java.util.Arrays;

public class Leetcode300_Longest_Increasing_Subsequence {

    public static int lengthOfLIS(int[] nums) {
        if (nums.length == 0) return 0;

        int maxLength = 1;
        int[] dp = new int[nums.length];
        Arrays.fill(dp,1);

        for(int i = 0;i<nums.length; i++){
            for(int j =0;j< i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = Math.max(dp[i],dp[j] + 1);
                    maxLength = Math.max(dp[i],maxLength);
                }
            }
        }
        return maxLength;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};
        int answer = lengthOfLIS(nums);
        System.out.print(answer);
    }
}
