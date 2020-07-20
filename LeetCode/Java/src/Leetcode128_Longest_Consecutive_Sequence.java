import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Leetcode128_Longest_Consecutive_Sequence {
    //O(N)
    public static int longestConsecutive(int[] nums) {

        Set<Integer> nums_set = new HashSet<Integer>();
        for (int num : nums) {
            nums_set.add(num);
        }

        int longestStreak = 0;

        for (int num : nums_set) {
            if (nums_set.contains(num - 1)) continue;

            int currentNum = num;
            int currentStreak = 1;

            while (nums_set.contains(currentNum + 1)) {
                currentNum++;
                currentStreak++;
            }
            longestStreak = Math.max(longestStreak, currentStreak);

        }
        return longestStreak;
    }

    //O(NlonN)
    /*public static int longestConsecutive(int[] nums) {

        if(nums.length == 0) return 0;

        int longest = 1;
        int current = 1;

        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 1; i++) {
            if(nums[i] == nums[i+1]) continue;

            if (nums[i] + 1 == nums[i + 1])
                current++;
            else {
                longest = Math.max(longest, current);
                current = 1;
            }
        }
        longest = Math.max(longest, current);

        return longest;
    }*/

    public static void main(String[] args) {
        // write your code here
        int[] nums = {1, 2, 0, 1,5};
        int answer = longestConsecutive(nums);
        System.out.print(answer);
    }

}

