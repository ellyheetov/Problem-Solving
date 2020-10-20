import java.util.Scanner;

public class BJ_2847_게임을_만든_동준이 {

    public static void main(String[] args) {
        // write your code here
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        int answer = solution(array);
        System.out.print(answer);
    }

    private static int solution(int[] array) {

        int cnt = 0;
        for (int index = array.length - 2; index >= 0; index--) {
            if (array[index] >= array[index + 1]) {
                cnt += array[index] - array[index + 1] + 1;
                array[index] = array[index + 1] - 1;
            }
        }
        return cnt;
    }
}
