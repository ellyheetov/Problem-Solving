public class Programmers_12909_올바른_괄호 {

    public static boolean solution(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }

    public static void main(String[] args) {
        String s = "()";
        boolean answer = solution(s);
        System.out.print(answer);
    }
}
