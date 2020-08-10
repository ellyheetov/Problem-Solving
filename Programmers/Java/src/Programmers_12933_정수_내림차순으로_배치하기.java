import java.util.Arrays;
import java.util.Comparator;

public class Programmers_12933_정수_내림차순으로_배치하기 {

    public static long solution(long n) {
        long answer = 0;

        int size = Long.toString(n).length();
        Integer[] array = new Integer[size];

        int index = 0;
        while (n != 0) {
            array[index++] = (int) (n % 10);
            n = n / 10;
        }
        Arrays.sort(array, (Comparator<Integer>) (o1, o2) -> o2 - o1);

        for (int i = 0; i < size; i++) {
            answer = answer * 10 + array[i];
        }
        return answer;
    }

    public static void main(String[] args) {
        long n = 118372;
        long answer = solution(n);
        System.out.print(answer);
    }
}
