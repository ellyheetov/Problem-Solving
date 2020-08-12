public class Leetcode647_Palindromic_Substrings {


    public static int countSubstrings(String s) {
        int answer = 0;

        for (int startIndex = 0; startIndex < s.length(); startIndex++) {
            for (int endIndex = startIndex + 1; endIndex <= s.length(); endIndex++) {
                String str = s.substring(startIndex, endIndex);
                if (isPalidromic(str)) answer++;
            }
        }

        return answer;
    }

    private static boolean isPalidromic(String str) {

        int left = 0, right = str.length() - 1;

        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }

    public static void main(String[] args) {
        String str = "abaab";
        int answer = countSubstrings(str);
        System.out.print(answer);
    }
}
