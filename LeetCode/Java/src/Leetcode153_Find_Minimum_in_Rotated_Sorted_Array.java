public class Leetcode153_Find_Minimum_in_Rotated_Sorted_Array {

    public static int findMin(int[] nums) {
        int left = 0;
        int right = nums.length -1;

        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] > nums[right])
                left = mid+1;
            else
                right = mid;
        }
        return nums[left];
    }
    public static void main(String[] args) {
        // write your code here
        int[] nums = {4,5,6,7,1,2};
        int answer = findMin(nums);
        System.out.println(answer);
    }
}
