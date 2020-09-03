import java.util.*;


public class Leetcode17_Letter_Combinations_of_a_Phone_Number {

    public static Map<String, String> phone = new HashMap<String, String>() {{
        put("2", "abc");
        put("3", "def");
        put("4", "ghi");
        put("5", "jkl");
        put("6", "mno");
        put("7", "pqrs");
        put("8", "tuv");
        put("9", "wxyz");
    }};

    public static List<String> output = new ArrayList<String>();

    public static void backtrack(String combination,String nextDigits){
        if(nextDigits.length() ==0){
            output.add(combination);
            return;
        }
        String digit = nextDigits.substring(0,1);
        String letters = phone.get(digit);

        for(int i = 0; i< letters.length(); i++) {
            String letter = phone.get(digit).substring(i,i+1);
            backtrack(combination + letter, nextDigits.substring(1));
        }
    }

    public static List<String> letterCombinations(String digits) {
        if (digits.length() != 0)
            backtrack("", digits);
        return output;
    }

    public static void main(String[] args) {
        // write your code here
        String input = "23";
        List<String> answer = letterCombinations(input);
        System.out.println(answer.toString());
    }
}

