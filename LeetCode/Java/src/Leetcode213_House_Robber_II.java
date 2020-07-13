public class Leetcode213_House_Robber_II {

    public static int rob(int[] nums, int start, int end) {
        int prev = nums[start];
        int curr = Math.max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            int temp = prev;
            prev = curr;
            curr = Math.max(temp + nums[i], curr);
        }
        return curr;
    }

    public static int rob(int[] nums) {
        if (nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        if (nums.length == 2) return Math.max(nums[0], nums[1]);

        int max_value = Math.max(rob(nums, 0, nums.length - 2), rob(nums, 1, nums.length - 1));
        return max_value;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {2,7,5,3,1};
        int answer = rob(nums);
        System.out.print(answer);
    }
}
