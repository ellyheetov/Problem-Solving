import java.util.Arrays;

public class Leetcode268_Missing_Number {

    public static int missingNumber(int[] nums) {
        /*Arrays.sort(nums);
        int i;
        for (i = 0; i < nums.length; i++) {
            if (nums[i] != i) return i;
        }
        return i;*/
        int len = nums.length;
        int sum = (len * (len + 1)) / 2;
        int total = 0;

        for(int x : nums){
            total += x;
        }
        return sum - total;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {0};
        int answer = missingNumber(nums);
        System.out.print(answer);
    }
}
