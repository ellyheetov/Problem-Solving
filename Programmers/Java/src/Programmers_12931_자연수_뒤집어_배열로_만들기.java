import java.util.ArrayList;

public class Programmers_12931_자연수_뒤집어_배열로_만들기 {
    public static int[] solution(long n) {
        int size = Long.toString(n).length();
        int[] answer = new int[size];

        int index = 0;
        while (n != 0) {
            answer[index++] = (int) (n % 10);
            n = n / 10;
        }
        return answer;
    }

    public static void main(String[] args) {
        long n = 000;
        int[] answer = solution(n);
    }
}
