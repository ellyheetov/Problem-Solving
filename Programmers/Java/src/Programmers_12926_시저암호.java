public class Programmers_12926_시저암호 {

    public static String solution(String s, int n) {
        String answer = "";
        n = n % 26;

        for (int index = 0; index < s.length(); index++) {
            char ch = s.charAt(index);

            if (Character.isLowerCase(ch)) {
                ch = (char) ((ch - 'a' + n) % 26 + 'a');
            } else if (Character.isUpperCase(ch)) {
                ch = (char) ((ch - 'A' + n) % 26 + 'A');
            }
            answer += ch;
        }
        return answer;
    }

    public static void main(String[] args) {
        String str = "z";
        int n = 1;
        String answer = solution(str, n);
        System.out.print(answer);
    }
}
