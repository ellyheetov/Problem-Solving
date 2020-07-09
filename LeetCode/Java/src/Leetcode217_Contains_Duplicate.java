import java.util.Arrays;

public class Leetcode217_Contains_Duplicate {
    public static boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i =0;i< nums.length -1; i++){
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {1,2,3};
        boolean answer = containsDuplicate(nums);
        System.out.print(answer);
    }
}
