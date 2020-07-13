public class Leetcode198_House_Robber {
    public static int rob(int[] nums) {

        if (nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        if(nums.length ==2) return Math.max(nums[0],nums[1]);

        int[] profit = new int[nums.length];

        profit[0] = nums[0];
        profit[1] = nums[1];
        profit[2] = nums[0] + nums[2];

        int max_value = Math.max(profit[2],Math.max(profit[0],profit[1]));

        for (int i = 3; i < nums.length; i++) {
            profit[i] = nums[i] + Math.max(profit[i - 2], profit[i - 3]);
            max_value = Math.max(max_value,profit[i]);
        }
        return max_value;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {1,2,3,1};
        int answer = rob(nums);
        System.out.print(answer);
    }
}
