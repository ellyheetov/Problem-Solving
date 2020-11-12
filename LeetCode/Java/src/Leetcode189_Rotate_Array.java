import java.util.Arrays;

public class Leetcode189_Rotate_Array {

    /*
    Solution1)
    Time Complexity: O(K * N)
    Space Complexity: O(1)
     */
    /*
        public static void rotate(int[] nums, int k) {
            int next = nums[nums.length - 1];
            int current = nums[0];

            while(k-- > 0) {
                for (int i = 0; i < nums.length - 1; i++) {
                    current = nums[i];
                    nums[i] = next;
                    next = current;
                }
                nums[nums.length - 1] = current;
            }
        }
    */
    /*
    Solution 2)
    Time Complexity: O(N)
    Space Complexity: O(N)
     */
    public static void rotate(int[] nums, int k) {

        int size = nums.length;
        boolean[] visit = new boolean[size];

        for (int index = 0; index < nums.length; index++) {
            int current = nums[index];
            int temp;

            index = (index + k) % size;

            while (!visit[index]) {
                visit[index] = true;
                temp = nums[index];
                nums[index] = current;
                current = temp;
                index = (index + k) % size;
            }
        }
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 6};
        int k = 2;
        rotate(nums, k);
        System.out.print(Arrays.toString(nums));
    }
}
