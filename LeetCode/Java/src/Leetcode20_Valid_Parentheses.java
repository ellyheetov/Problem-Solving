import java.util.Stack;

public class Leetcode20_Valid_Parentheses {
    public static boolean isValid(String s) {

        Stack<Character> parenthese = new Stack<>();
        char[] charArray = s.toCharArray();

        if (s.length() % 2 != 0) return false;

        for (char c : charArray) {

            if (c == '(' || c == '{' ||c == '[') {
                parenthese.push(c);
                continue;
            }
            if(parenthese.empty()) return false;
            if (parenthese.peek() == '{' && c == '}')
                parenthese.pop();
            else if (parenthese.peek() == '(' && c == ')')
                parenthese.pop();
            else if (parenthese.peek() == '[' && c == ']')
                parenthese.pop();
            else return false;
        }
        return parenthese.empty();
    }
/*    public static boolean isValid(String s) {

        Stack<Character> parenthese = new Stack<>();
        if (s.length() % 2 != 0) return false;

        for (int i = 0; i < s.length(); i++) {

            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') {
                parenthese.push(s.charAt(i));
                continue;
            }
            if(parenthese.empty()) return false;
            if (parenthese.peek() == '{' && s.charAt(i) == '}')
                parenthese.pop();
            else if (parenthese.peek() == '(' && s.charAt(i) == ')')
                parenthese.pop();
            else if (parenthese.peek() == '[' && s.charAt(i) == ']')
                parenthese.pop();
            else return false;
        }
        return parenthese.empty();
    }*/

    public static void main(String[] args) {
        // write your code here
        String str = "[]{}[]{";
        boolean answer = isValid(str);
        System.out.print(answer);
    }
}
