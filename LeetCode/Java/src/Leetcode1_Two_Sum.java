import java.util.HashMap;
import java.util.Map;

public class Leetcode1_Two_Sum {
    public static int[] twoSum(int[] nums, int target) {

        Map<Integer,Integer> map  = new HashMap<>();

        for(int i=0;i< nums.length;i++){
            int complement = target - nums[i];
            if(map.containsKey(complement))
                return new int[] { map.get(complement), i};
            map.put(nums[i],i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    public static void main(String[] args) {
        int nums[] = {2, 7, 11, 15};
        int target = 9;
        int answer[] = twoSum(nums, target);

        for(int i : answer){
            System.out.print(i + " ");
        }
    }
}
