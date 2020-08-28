public class Leetcode557_Reverse_Words_in_a_String_III {
    public static String reverseWords(String s) {
        StringBuilder stringBuilder = new StringBuilder();
        for(String str : s.split(" ")){
            stringBuilder.append(new StringBuilder(str).reverse());
            stringBuilder.append(" ");
        }
        return stringBuilder.toString().trim();
    }
    public static void main(String[] args) {
        // write your code here
        String s = "Let's take LeetCode contest";
        String answer = reverseWords(s);
        System.out.print(answer);
    }
}
