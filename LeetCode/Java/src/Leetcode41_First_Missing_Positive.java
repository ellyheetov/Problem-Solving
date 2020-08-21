import java.util.*;

public class Leetcode41_First_Missing_Positive {


    public static int firstMissingPositive(int[] nums) {
        Set<Integer> hashset = new HashSet<Integer>();

        for(int num: nums){
            hashset.add(num);
        }
        for(int value = 1; value <= hashset.size(); value++){
            if(!hashset.contains(value))
                return value;
        }
        return hashset.size() + 1;
    }
    /*public static int firstMissingPositive(int[] nums) {
        int answer = 1;

        PriorityQueue<Integer> que = new PriorityQueue<Integer>();
        for (int num : nums) {
            que.offer(num);
        }
        while(!que.isEmpty()){
            int value = que.poll();
            if(value == answer)
                answer++;
        }
        return answer;
    }*/

    public static void main(String[] args) {
        // write your code here
        int[] nums = {2, 3};
        int answer = firstMissingPositive(nums);
        System.out.print(answer);
    }
}
