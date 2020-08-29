import java.util.Stack;

public class Programmers_60058_괄호_변환 {
    public static String solution(String p) {
        return transform(p);
    }

    private static String transform(String p) {
        if (p.length() == 0) return "";

        String u = p;
        String v = "";

        for (int index = 2; index < p.length(); index = index + 2) {
            if (isBalance(p.substring(0, index))) {
                u = p.substring(0, index);
                v = p.substring(index);
                break;
            }
        }
        if (isValid(u)) {
            return u + transform(v);
        } else {
            return '(' + transform(v) + ')' + reverse(u);
        }
    }

    private static String reverse(String u) {
        String result = "";
        for (int i = 1; i < u.length() - 1; i++) {
            if (u.charAt(i) == '(')
                result += ')';
            else
                result += '(';
        }
        return result;
    }

    private static boolean isValid(String p) {
        if (p.length() == 0) return true;

        int index = 0;
        Stack<Character> stringStack = new Stack<>();

        while (index < p.length()) {
            if (p.charAt(index++) == '(') {
                stringStack.push('(');
                continue;
            }
            if (stringStack.empty()) return false;
            char temp = stringStack.pop();
            if (temp != '(') break;
        }
        return stringStack.empty();
    }

    private static boolean isBalance(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') cnt++;
            else cnt--;
        }
        return cnt == 0;
    }


    public static void main(String[] args) {
        String s = "()))((()";
        String pattern = solution(s);
        String answer = "()(())()";
        System.out.println(" answer : " + answer);
        System.out.println("pattern : " + pattern);
        System.out.print(answer.equals(pattern));
    }
}
