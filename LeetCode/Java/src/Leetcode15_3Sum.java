import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Leetcode15_3Sum {
    public static List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> answer = new ArrayList<>();
        Arrays.sort(nums);

        for(int i = 0; i< nums.length -2; i++){

            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.length -1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    answer.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++; right--;

                    while(left<right && nums[left -1] == nums[left]) left++;
                    while(left<right && nums[right] == nums[right+1]) right--;
                }
                else if(sum < 0){
                    left++;
                }
                else if(sum > 0){
                    right--;
                }
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        // write your code here

        int[] nums = {-1,0,1,2,-1,-4};
        List<List<Integer>> answer = threeSum(nums);
    }
}
