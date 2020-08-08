public class Programmers_12924_숫자의_표현 {

    public static int solution(int n) {
        int answer = 1;
        int start = 1, end = 1;
        int sum = 0;

        while (end < n) {
            if (sum == n) {
                answer++;
                sum -= start++;
            } else if (sum > n) {
                sum -= start++;

            } else {
                end++;
                sum += end;
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        int n = 15;
        int answer = solution(n);
        System.out.print(answer);
    }
}
