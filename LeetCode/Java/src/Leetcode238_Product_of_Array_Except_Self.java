
public class Leetcode238_Product_of_Array_Except_Self {
    public static int[] productExceptSelf(int[] nums) {

        int len = nums.length;
        int[] answer = new int[len];
        int[] left = new int[len];
        int[] right = new int[len];

        left[0] = 1;
        right[len - 1] = 1;
        for (int i = 1; i < len; i++) {
            left[i] = nums[i - 1] * left[i - 1];
        }
        for (int i = len - 2; i >= 0; i--) {
            right[i] = right[i +1] * nums[i +1];
        }
        for (int i = 0; i < len; i++) {
            answer[i] = left[i] * right[i];
        }
        return answer;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {1, 2, 3, 4};
        int[] answer = productExceptSelf(nums);
        System.out.println(answer);
    }
}
