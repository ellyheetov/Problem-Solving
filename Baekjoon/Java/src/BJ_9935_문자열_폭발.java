import java.util.Deque;
import java.util.Scanner;
import java.util.Stack;

public class BJ_9935_문자열_폭발 {

    public static Stack<Character> stack = new Stack<>();
    public static String str = "";
    public static String pattern = "";
    public static boolean isBomb = false;

    public static void main(String[] args) {
        // write your code here
        Scanner scanner = new Scanner(System.in);
        str = scanner.next();
        pattern = scanner.next();

        solution();
    }

    private static void solution() {

        for (int index = 0; index < str.length(); index++) {
            stack.push(str.charAt(index));

            int patternSize = pattern.length();

            if (stack.size() < patternSize) {
                continue;
            }
            if (stack.peek() == pattern.charAt(patternSize - 1)) {
                isBomb = true;

                for (int gap = 1; gap < patternSize; gap++) {
                    if ( stack.get(stack.size() - gap - 1) != pattern.charAt(patternSize - gap - 1)){
                        isBomb = false;
                        break;
                    }
                }
            }
            if (isBomb) {
                while (patternSize-- > 0) {
                    stack.pop();
                }
                isBomb = false;
            }
        }
        printAnswer();
    }


    private static void printAnswer() {
        StringBuffer answer = new StringBuffer();

        if (stack.empty()) {
            answer.append("FRULA");
        } else {
            while (!stack.empty()) {
                answer.append(stack.pop());
            }
            answer.reverse();
        }
        System.out.print(answer);
    }
}
