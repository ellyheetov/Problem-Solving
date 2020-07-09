public class Leetcode53_Maximum_Subarray {

    public static int maxSubArray(int[] nums) {
        if(nums.length < 1) return 0;
        int max_value = nums[0];
        int current = Math.max(nums[0], 0);

        for(int i = 1;i< nums.length; i++){
            current = current + nums[i];
            if(max_value < current)
                max_value = current;
            if(current< 0)
                current = 0;
        }
        return max_value;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {1,2};
        int answer= maxSubArray(nums);
        System.out.println(answer);
    }
}

