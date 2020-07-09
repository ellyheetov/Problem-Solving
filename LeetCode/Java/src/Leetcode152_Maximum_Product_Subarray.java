public class Leetcode152_Maximum_Product_Subarray {
    public static int maxProduct(int[] nums) {
        int max = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        for(int i = 1;i< nums.length;i++){
            int nextMin = currentMin * nums[i];
            int nextMax = currentMax * nums[i];

            currentMax = Math.max(nums[i], Math.max(nextMax,nextMin));
            currentMin = Math.min(nums[i], Math.min(nextMax,nextMin));

            max = Math.max(currentMax,max);
        }
        return max;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {2, 3, -2, 4};
        int answer = maxProduct(nums);
        System.out.print(answer);
    }
}

