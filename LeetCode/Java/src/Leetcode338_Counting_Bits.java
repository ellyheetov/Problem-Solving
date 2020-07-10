public class Leetcode338_Counting_Bits {

    public static int[] countBits(int num) {
        int[] answer = new int[num + 1];
        for (int i = 1; i <= num; i++) {
            answer[i] = answer[i >> 1] + (i & 1);
        }
        return answer;
    }

    public static void main(String[] args) {
        // write your code here
        int num = 5;
        int[] answer = countBits(num);
        System.out.print(answer);
    }
}
