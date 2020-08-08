import java.util.Arrays;

public class Programmers_12941_최솟값_만들기 {

    public static int solution(int[] A, int[] B) {
        int answer = 0;

        Arrays.sort(A);
        Arrays.sort(B);

        for (int index = 0; index < A.length; index++) {
            answer += A[index] * B[B.length - index - 1];
        }
        return answer;
    }

    public static void main(String[] args) {
        int[] a = {1, 2};
        int[] b = {3, 4};
        int answer = solution(a, b);
        System.out.print(answer);
    }
}
