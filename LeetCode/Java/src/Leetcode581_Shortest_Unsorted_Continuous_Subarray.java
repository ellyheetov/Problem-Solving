import java.util.Arrays;

public class Leetcode581_Shortest_Unsorted_Continuous_Subarray {
    public static int findUnsortedSubarray(int[] nums) {

        int size = nums.length;
        int[] copyArray = new int[size];
        int answer = 0;

        System.arraycopy(nums, 0, copyArray, 0, size);
        Arrays.sort(copyArray);

        int start = nums.length;
        int end = 0;

//        int start = findStartIndex(nums, copyArray);
//        int end = findEndIndex(nums, copyArray);

        for(int index = 0; index < nums.length; index++){
            if(nums[index] != copyArray[index]){
                start = Math.min(start, index);
                end = Math.max(end, index);
            }
        }
        answer = end - start + 1;
        if(end == 0) return 0;
        return answer;
    }

/*    private static int findEndIndex(int[] nums, int[] copyArray) {
        int index = nums.length - 1;
        while (index >= 0) {
            if (nums[index] != copyArray[index]) break;
            index--;
        }
        return index;
    }

    private static int findStartIndex(int[] nums, int[] copyArray) {
        int index = 0;
        while (index < nums.length) {
            if (nums[index] != copyArray[index]) break;
            index++;
        }
        return index;
    }*/

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4};
        int answer = findUnsortedSubarray(nums);
        System.out.print(answer);
    }
}
