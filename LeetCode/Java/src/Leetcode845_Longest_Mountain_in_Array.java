public class Leetcode845_Longest_Mountain_in_Array {
    public static int longestMountain(int[] arr) {
        boolean up = false;
        boolean down = false;

        int right = 1;
        int maxLen = 0;

        while (right < arr.length) {
            int left = right - 1;
            while (right < arr.length && arr[right - 1] < arr[right]) {
                right++;
                up = true;
            }
            while (right < arr.length && arr[right - 1] > arr[right]) {
                right++;
                down = true;
            }
            if (up && down) {
                maxLen = Math.max(maxLen, right - left);
            }
            if(left == right -1) right++;
            up = false;
            down = false;
        }
        return maxLen;
    }

    public static void main(String[] args) {
        int[] arr = {2,2,2};
        int answer = longestMountain(arr);
        System.out.print(answer);
    }
}
